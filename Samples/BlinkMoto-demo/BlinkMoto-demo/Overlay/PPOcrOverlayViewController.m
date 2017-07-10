//
//  PPOcrOverlayViewController.m
//  BlinkMoto-demo
//
//  Created by Jura Skrlec on 02/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "PPOcrOverlayViewController.h"
#import "PPOcrOverlayViewController+Private.h"

@interface PPOcrOverlayViewController ()<PPOcrFinderViewDelegate>

@property (strong, nonatomic) PPModernOcrResultOverlaySubview *resultOverlay;

@property (nonatomic) UIInterfaceOrientation interfaceOrientation;

@property (nonatomic) PPImageMetadata *currentImageMetadata;

@property (nonatomic, assign) OcrRecognizerType orcRecognizerType;

@property (nonatomic, strong) PPBlinkOcrRecognizerSettings *ocrRecognizerSettings;

@property (nonatomic, strong) NSDictionary *translation;

@end

static NSString * const kVinOcrParser = @"VIN OCR Parser";
static NSString * const kLicensePlateOcrParser = @"License Plate OCR Parser";

@implementation PPOcrOverlayViewController

- (instancetype)initWithOcrRecognizerType:(OcrRecognizerType)ocrRecognizerType andTranslation:(NSDictionary *)translation {
    self = [super init];
    if (self) {
        self.orcRecognizerType = ocrRecognizerType;
        self.translation = translation;
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
    
    self.resultOverlay = [[PPModernOcrResultOverlaySubview alloc] initWithFrame:self.view.bounds];
    
    // Set overlay subview
    self.resultOverlay.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.resultOverlay setBackgroundColor:[UIColor clearColor]];
    [self.view insertSubview:self.resultOverlay belowSubview:self.viewfinder];
    [self registerOverlaySubview:self.resultOverlay];
    
    [self setupSettingsForRecognizerType];
    [_viewfinder setTranslation:self.translation];
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
        
        PPVinRecognizerSettings *vinRecognizerSettings = [[PPVinRecognizerSettings alloc] init];
        [self.coordinator.currentSettings.scanSettings addRecognizerSettings:vinRecognizerSettings];
    }
    else if (self.orcRecognizerType == LicensePlate) {
        [self.ocrRecognizerSettings addOcrParser:[[PPLicensePlatesParserFactory alloc] init] name:kLicensePlateOcrParser];
        [self.coordinator.currentSettings.scanSettings addRecognizerSettings:self.ocrRecognizerSettings];
    }
    
    self.coordinator.currentSettings.metadataSettings.currentFrame = YES;
    
    [self.coordinator applySettings];
}

- (void)viewWillLayoutSubviews {
    [super viewWillLayoutSubviews];
    
    [self updateScanningRegion];
}

- (void)updateScanningRegion {
    
    [self.view layoutIfNeeded];
    
    [self updateScanningRegionArea];
    
    [UIView animateWithDuration:0.4
                     animations:^{
                         [self.view layoutIfNeeded];
                     }];
}

- (void)updateScanningRegionArea {
    self.scanningRegion = self.viewfinder.scanningRegion;
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
        PPImageMetadata *imageMetadata = (PPImageMetadata *)metadata;
        if (imageMetadata.imageType == PPImageMetadataTypeSuccessfulFrame) {
            self.currentImageMetadata = imageMetadata;
        }
    }
}

- (void)cameraViewController:(UIViewController<PPScanningViewController> *)cameraViewController didOutputResults:(NSArray *)results {
    
    // First we check that we received a valid result!
    if (results == nil || results.count == 0) {
        return;
    }
    
    // then, pause scanning until we process all the results
    [cameraViewController pauseScanning];
    
    for (PPRecognizerResult *result in results) {
        NSString *resultVin;
        BOOL success = NO;
        if ([result isKindOfClass:[PPBlinkOcrRecognizerResult class]]) {
            PPBlinkOcrRecognizerResult *ocrRecognizerResult = (PPBlinkOcrRecognizerResult *)result;

            switch (self.orcRecognizerType) {
                case VIN:
                    resultVin = [ocrRecognizerResult parsedResultForName:kVinOcrParser];
                    success = YES;
                    break;
                case LicensePlate:
                    resultVin =  [ocrRecognizerResult parsedResultForName:kLicensePlateOcrParser];
                    success = YES;
                    break;
                default:
                    resultVin =  @"";
                    success = NO;
                    [cameraViewController resumeScanningAndResetState:YES];
                    break;
            }
            
            
        }
        if ([result isKindOfClass:[PPVinRecognizerResult class]]) {
            PPVinRecognizerResult *vinRecognizerResult = (PPVinRecognizerResult *)result;
            resultVin = vinRecognizerResult.vinNumber;
            success = YES;
        }
        
        [_viewfinder setOcrResultSucces:success withResult:resultVin andImage:self.currentImageMetadata.image];
        
    }
}

#pragma mark - PPOcrFinderViewDelegate


- (BOOL)viewfinderViewIsScanningPaused:(PPOcrFinderView *)viewfinderView {
    return [self.containerViewController isScanningPaused];
}

- (void)viewfinderViewDidTapAcceptButton:(UIButton *)sender {
    if ([[self.viewfinder getScanningResult] length] > 0) {
        [self.delegate ocrOverlayViewControllerDidReturnResult:[_viewfinder getScanningResult]];
    }
}

- (void)viewfinderViewDidTapCancelButton:(UIButton *)sender {
    [self.delegate ocrOverlayViewControllerWillClose:self];
}

- (void)viewfinderViewDidTapRepeatButton:(UIButton *)sender {
    [_viewfinder resetScanningState];
    [self.scanningViewController resumeScanningAndResetState:YES];
}

@end
