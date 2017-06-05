//
//  PPOcrOverlayViewController.m
//  BlinkMoto-demo
//
//  Created by Jura Skrlec on 02/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "PPOcrOverlayViewController.h"
#import "PPOcrOverlayViewController+Private.h"
#import "PPOcrOverlaySubview.h"

@interface PPOcrOverlayViewController ()<PPOcrFinderViewDelegate>

@property (strong, nonatomic) PPOcrResultOverlaySubview *resultOverlay;

@property (nonatomic) UIInterfaceOrientation interfaceOrientation;

@property (nonatomic) PPImageMetadata *currentImageMetadata;

@property (nonatomic, assign) OcrRecognizerType orcRecognizerType;

@property (nonatomic, strong) PPBlinkOcrRecognizerSettings *ocrRecognizerSettings;

@end

static NSString * const kVinOcrParser = @"VIN OCR Parser";
static NSString * const kLicensePlateOcrParser = @"License Plate OCR Parser";

@implementation PPOcrOverlayViewController

- (instancetype)initWithOcrRecognizerType:(OcrRecognizerType)ocrRecognizerType {
    self = [super init];
    if (self) {
        self.orcRecognizerType = ocrRecognizerType;
    }
    
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _interfaceOrientation = UIInterfaceOrientationPortrait;
    
    _viewfinder = [[PPOcrFinderView alloc] initWithFrame:self.view.bounds];
    _viewfinder.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
    _viewfinder.delegate = self;
    
    [self.view insertSubview:self.viewfinder atIndex:0];
    
    self.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    
    self.resultOverlay = [[PPOcrResultOverlaySubview alloc] initWithFrame:self.view.bounds];
    
    // Set overlay subview
    self.resultOverlay.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.resultOverlay setBackgroundColor:[UIColor clearColor]];
    [self.view insertSubview:self.resultOverlay belowSubview:self.viewfinder];
    [self registerOverlaySubview:self.resultOverlay];
    
    [self setupSettingsForRecognizerType];
    
    [_viewfinder.acceptButton setTitle:@"Ubernhemnen" forState:UIControlStateNormal];
    [_viewfinder.cancelButton setTitle:@"Abbrechen" forState:UIControlStateNormal];
    [_viewfinder.repeatButton setTitle:@"Wiederholen" forState:UIControlStateNormal];
    
    _viewfinder.message.text = @"Bitte die FIN / VIN oder Barcode in diesem Bereich erfassen";
    [_viewfinder.message sizeToFit];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [self setupNotifications];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    // Set scanning region
    self.scanningRegion = self.viewfinder.scanningRegion;
}

- (void)viewWillDisappear:(BOOL)animated {
    [self removeNotifications];
}

- (void)setupSettingsForRecognizerType {
    
    // remove all recognizers
    [self.coordinator.currentSettings.scanSettings removeAllRecognizerSettings];
    
    // Add BlinkOCR Recognizer
    self.ocrRecognizerSettings = [[PPBlinkOcrRecognizerSettings alloc] init];
    
    if (self.orcRecognizerType == VIN) {
        [self.ocrRecognizerSettings addOcrParser:[[PPVinOcrParserFactory alloc] init] name:kVinOcrParser];
        [self.coordinator.currentSettings.scanSettings addRecognizerSettings:self.ocrRecognizerSettings];
        
        PPBarDecoderRecognizerSettings *barDecoderRecognizerSettings = [[PPBarDecoderRecognizerSettings alloc] init];
        barDecoderRecognizerSettings.scanCode39 = YES;
        barDecoderRecognizerSettings.scanCode128 = YES;
        
        [self.coordinator.currentSettings.scanSettings addRecognizerSettings:barDecoderRecognizerSettings];
        
        PPZXingRecognizerSettings *zxingRecognizerSettings = [[PPZXingRecognizerSettings alloc] init];
        zxingRecognizerSettings.scanQR = NO;
        zxingRecognizerSettings.scanDataMatrix = YES;
        
        [self.coordinator.currentSettings.scanSettings addRecognizerSettings:zxingRecognizerSettings];
    }
    else if (self.orcRecognizerType == LicensePlate) {
        [self.ocrRecognizerSettings addOcrParser:[[PPLicensePlatesParserFactory alloc] init] name:kLicensePlateOcrParser];
        [self.coordinator.currentSettings.scanSettings addRecognizerSettings:self.ocrRecognizerSettings];
    }
    
    self.coordinator.currentSettings.metadataSettings.currentFrame = YES;
    
    [self.coordinator applySettings];
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    
    [self.containerViewController setScanningRegion:self.viewfinder.scanningRegion];

}

#pragma mark - notifications

- (void)setupNotifications {
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(deviceOrientationChanged:)
                                                 name:UIDeviceOrientationDidChangeNotification
                                               object:nil];
}

- (void)removeNotifications {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIDeviceOrientationDidChangeNotification object:nil];
}


- (BOOL)shouldAutorotate {
    return YES;
}


- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskAllButUpsideDown;
}


- (void)deviceOrientationChanged:(NSNotification *)notification {
    
    UIDeviceOrientation deviceOrientation = [[UIDevice currentDevice] orientation];
    
    UIInterfaceOrientation orientation = self.interfaceOrientation;
    
    if (UIDeviceOrientationIsPortrait(deviceOrientation)) {
        orientation = UIInterfaceOrientationPortrait;
    }
    else if (UIDeviceOrientationIsLandscape(deviceOrientation)) {
        orientation = deviceOrientation == UIDeviceOrientationLandscapeLeft ? UIInterfaceOrientationLandscapeLeft : UIInterfaceOrientationLandscapeRight;
    }
    
    [self setInterfaceOrientation:orientation animated:YES];
}

- (void)setInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    [self setInterfaceOrientation:interfaceOrientation animated:NO];
}

- (void)setInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation animated:(BOOL)animated {
    if (self.interfaceOrientation == interfaceOrientation) {
        return;
    }
    
    if (UIInterfaceOrientationIsPortrait(interfaceOrientation)) {
        
        [self.viewfinder initViewfinderForPortrait];
        
    } else if (UIInterfaceOrientationIsLandscape(interfaceOrientation)) {

        [self.viewfinder initViewfinderForLandscape];
    }
    
    _interfaceOrientation = interfaceOrientation;
}

#pragma mark - OverlayViewController stuff

- (void)cameraViewController:(UIViewController<PPScanningViewController> *)cameraViewController didOutputMetadata:(PPMetadata *)metadata {
    
    if ([metadata isKindOfClass:[PPImageMetadata class]]) {
        self.currentImageMetadata = (PPImageMetadata *)metadata;
    }
}

- (void)cameraViewController:(UIViewController<PPScanningViewController> *)cameraViewController didOutputResults:(NSArray *)results {
    
    for (PPRecognizerResult *result in results) {
        if ([result isKindOfClass:[PPBlinkOcrRecognizerResult class]]) {
            PPBlinkOcrRecognizerResult *ocrRecognizerResult = (PPBlinkOcrRecognizerResult *)result;
            switch (self.orcRecognizerType) {
                case VIN:
                    _viewfinder.resultMessage.text =  [ocrRecognizerResult parsedResultForName:kVinOcrParser];
                    _viewfinder.repeatButton.enabled = YES;
                    _viewfinder.resultImageView.image = self.currentImageMetadata.image;
                    _viewfinder.resultImageView.hidden = NO;
                    break;
                case LicensePlate:
                    _viewfinder.resultMessage.text =  [ocrRecognizerResult parsedResultForName:kLicensePlateOcrParser];
                    _viewfinder.repeatButton.enabled = YES;
                    _viewfinder.resultImageView.image = self.currentImageMetadata.image;
                    _viewfinder.resultImageView.hidden = NO;
                    break;
                default:
                    _viewfinder.resultMessage.text =  @"";
                    break;
            }
        }
        if ([result isKindOfClass:[PPBarDecoderRecognizerResult class]]) {
            PPBarDecoderRecognizerResult *barDecoderResult = (PPBarDecoderRecognizerResult *)result;
            NSLog(@"%@", barDecoderResult);
        }
        
    }
}

#pragma mark - PPOcrFinderViewDelegate


- (BOOL)viewfinderViewIsScanningPaused:(PPOcrFinderView *)viewfinderView {
    return [self.containerViewController isScanningPaused];
}

- (void)viewfinderViewDidTapAcceptButton:(UIButton *)sender {
    if (_viewfinder.resultMessage.text.length > 0) {
        [self.delegate ocrOverlayViewControllerDidReturnResult:_viewfinder.resultMessage.text];
    }
}

- (void)viewfinderViewDidTapCancelButton:(UIButton *)sender {
    [self.delegate ocrOverlayViewControllerWillClose:self];
}

- (void)viewfinderViewDidTapRepeatButton:(UIButton *)sender {
    _viewfinder.resultImageView.image = nil;
    _viewfinder.resultImageView.hidden = YES;
    _viewfinder.repeatButton.enabled = NO;
}

@end
