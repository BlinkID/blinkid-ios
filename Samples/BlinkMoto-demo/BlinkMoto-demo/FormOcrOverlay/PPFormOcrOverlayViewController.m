//
//  PPFormOcrOverlayViewController.m
//  BlinkOCR
//
//  Created by Jura on 01/03/15.
//  Copyright (c) 2015 PhotoPay. All rights reserved.
//

#import "PPFormOcrOverlayViewController.h"

#import <MicroBlink/PPModernOcrResultOverlaySubview.h>
#import <MicroBlink/PPBlinkOcrRecognizerResult.h>

#import "PPPivotView.h"
#import "PPScanElement.h"
#import "PPScanResultView.h"

#import "PPBlinkOcrHelpViewController.h"

#import <MicroBlink/PPTapToFocusOverlaySubview.h>

CGPoint CGRectCenter(CGRect rect) { return CGPointMake(rect.origin.x + rect.size.width / 2, rect.origin.y + rect.size.height / 2); }

CGRect CGRectBounds(CGRect rect) { return CGRectMake(0, 0, rect.size.width, rect.size.height); }

@interface PPFormOcrOverlayViewController () <PPPivotViewDelegate, PPBlinkOcrHelpViewControllerDelegate>

@property (nonatomic, strong) PPOcrResultOverlaySubview *ocrResultOverlaySubview;

@property (nonatomic, strong) PPTapToFocusOverlaySubview *tapToFocusOverlaySubview;

@property (nonatomic, assign) BOOL lightOn;

@property (nonatomic, strong) PPPivotView *pivotView;

@property (nonatomic, strong) PPScanResultView *scanResultView;

@property (nonatomic, assign) NSUInteger currentElementIndex;

@property (nonatomic, strong) PPBlinkOcrRecognizerSettings *ocrRecognizerSettings;

@property (nonatomic, assign) SystemSoundID sound;

@property (nonatomic) NSMutableArray<NSLayoutConstraint *> *currentConstraints;

@property (weak, nonatomic) IBOutlet UILabel *labelNextButton;

@property (nonatomic) PPImageMetadata *currentImageMetadata;

@property (nonatomic) BOOL movingPivotView;

@end

@implementation PPFormOcrOverlayViewController

- (void)setupSubviews {
    
    self.ocrResultOverlaySubview = [[PPOcrResultOverlaySubview alloc] initWithFrame:self.view.frame];
    [self.view addSubview:self.ocrResultOverlaySubview];
    [self registerOverlaySubview:self.ocrResultOverlaySubview];

    // instantiate and setup Pivot view
    self.pivotView = [[PPPivotView alloc] initWithFrame:self.pivotViewContainer.bounds];
    self.pivotView.centered = NO;
    self.pivotView.delegate = self;
    self.pivotView.titles = [self pivotViewTitles];
    self.pivotView.translatesAutoresizingMaskIntoConstraints = YES;
    [self.pivotView update];
    [self.pivotViewContainer addSubview:self.pivotView];

    // instantiate and hide result view
    self.scanResultView = [PPScanResultView allocFromNibName:@"PPScanResultView"];
    self.scanResultView.hidden = YES;
    self.scanResultView.alpha = 0.0f;
    self.scanResultView.userInteractionEnabled = NO;
    [self.view insertSubview:self.scanResultView belowSubview:self.buttonNext];

    self.tapToFocusOverlaySubview = [[PPTapToFocusOverlaySubview alloc] initWithFrame:self.view.bounds];
    [self.view insertSubview:self.tapToFocusOverlaySubview atIndex:0];
    [self registerOverlaySubview:self.tapToFocusOverlaySubview];
}

- (void)viewDidLoad {
    [super viewDidLoad];

    [self setupSubviews];

    self.movingPivotView = NO;

    self.currentConstraints = [NSMutableArray array];

    self.currentElementIndex = 0;

    for (PPScanElement *element in self.scanElements) {
        element.scanned = NO;
        element.edited = NO;
    }

    PPScanElement *scanElement = ((PPScanElement *)[self.scanElements objectAtIndex:self.currentElementIndex]);

    self.labelTooltip.text = scanElement.localizedTooltip;

    [self setupSettingsForScanElement:scanElement];

    [self registerForKeyboardNotifications];
}

- (void)setupSettingsForScanElement:(PPScanElement *)scanElement {

    // remove all recognizers
    [self.coordinator.currentSettings.scanSettings removeAllRecognizerSettings];

    // Add BlinkOCR Recognizer
    self.ocrRecognizerSettings = [[PPBlinkOcrRecognizerSettings alloc] init];

    // set the keyboard type on scan result view
    self.scanResultView.textField.keyboardType = scanElement.keyboardType;

    [self.ocrRecognizerSettings addOcrParser:scanElement.factory name:scanElement.identifier];
    [self.coordinator.currentSettings.scanSettings addRecognizerSettings:self.ocrRecognizerSettings];

    // if scan element is for VIN numbers, add barcode scanner as well
    if ([scanElement.factory isKindOfClass:[PPVinOcrParserFactory class]]) {

        PPBarDecoderRecognizerSettings *barDecoderRecognizerSettings = [[PPBarDecoderRecognizerSettings alloc] init];
        barDecoderRecognizerSettings.scanCode39 = YES;
        barDecoderRecognizerSettings.scanCode128 = YES;

        [self.coordinator.currentSettings.scanSettings addRecognizerSettings:barDecoderRecognizerSettings];

        PPZXingRecognizerSettings *zxingRecognizerSettings = [[PPZXingRecognizerSettings alloc] init];
        zxingRecognizerSettings.scanQR = NO;
        zxingRecognizerSettings.scanDataMatrix = YES;

        [self.coordinator.currentSettings.scanSettings addRecognizerSettings:zxingRecognizerSettings];

    }

    self.coordinator.currentSettings.metadataSettings.currentFrame = YES;

    [self.coordinator applySettings];

}

- (NSArray *)pivotViewTitles {
    NSMutableArray *titles = [[NSMutableArray alloc] initWithCapacity:self.scanElements.count];
    for (PPScanElement *element in self.scanElements) {
        [titles addObject:element.localizedTitle];
    }
    return titles;
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    [self buttonSkipEnable:NO];

    self.labelNextButton.hidden = YES;
    self.labelNextButton.alpha = 0.0f;
}

- (void)buttonSkipEnable:(BOOL)enable {
    self.buttonSkip.enabled = enable;
    self.buttonSkip.hidden = !enable;
}

- (void)buttonNextEnable:(BOOL)enable {
    self.buttonNext.enabled = enable;
    self.buttonNext.hidden = !enable;
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];

    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    // hide light if not available on device
    if (![self.containerViewController overlayViewControllerShouldDisplayTorch:self]) {
        self.buttonLight.enabled = NO;
        self.buttonLight.alpha = 0.0f;
    }

#if TARGET_IPHONE_SIMULATOR
    self.scanResultView.textField.text = @"123,22";

    [self showResultView];
#endif
}

- (void)viewWillLayoutSubviews {
    [super viewWillLayoutSubviews];

    [self updateScanningRegionArea];
}

- (void)registerForKeyboardNotifications {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWasShown:) name:UIKeyboardDidShowNotification object:nil];

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillBeHidden:) name:UIKeyboardWillHideNotification object:nil];
}

- (void)keyboardWasShown:(NSNotification *)aNotification {

    [UIView animateWithDuration:self.pivotView.moveAnimationDuration
                          delay:0.0
                        options:UIViewAnimationOptionCurveEaseInOut
                     animations:^{
                       self.scanResultView.center = CGRectCenter([self scanResultViewWithKeyboardFrame]);
                       self.scanResultView.bounds = CGRectBounds([self scanResultViewWithKeyboardFrame]);
                       self.scanResultView.backgroundColor = [self.scanResultView.backgroundColor colorWithAlphaComponent:1.0f];

                       self.ocrResultOverlaySubview.alpha = 0.0f;
                     }
                     completion:nil];

    [[self containerViewController] pauseScanning];
}

- (void)keyboardWillBeHidden:(NSNotification *)aNotification {

    [UIView animateWithDuration:self.pivotView.moveAnimationDuration
                          delay:0.0
                        options:UIViewAnimationOptionCurveEaseInOut
                     animations:^{
                       self.scanResultView.center = CGRectCenter([self scanResultViewFrame]);
                       self.scanResultView.bounds = CGRectBounds([self scanResultViewFrame]);
                       self.scanResultView.backgroundColor = [self.scanResultView.backgroundColor colorWithAlphaComponent:0.7f];

                       self.ocrResultOverlaySubview.alpha = 1.0f;
                     }
                     completion:nil];

    PPScanElement *scanElement = ((PPScanElement *)[self.scanElements objectAtIndex:self.currentElementIndex]);
    scanElement.edited = YES;
    scanElement.scanned = NO;
    scanElement.value = self.scanResultView.textField.text;

    [[self containerViewController] resumeScanningAndResetState:NO];
}

- (void)updateScanningRegionArea {

    PPScanElement *currentElement = (PPScanElement *)[self.scanElements objectAtIndex:self.currentElementIndex];

    CGFloat borderWidth = self.view.bounds.size.width * currentElement.scanningRegionWidth;
    CGFloat xMargin = (self.view.bounds.size.width - borderWidth) / 2;

    for (NSLayoutConstraint *constraint in self.currentConstraints) {
        [self.view removeConstraint:constraint];
    }

    [self.currentConstraints removeAllObjects];

    [self.currentConstraints addObject:[NSLayoutConstraint constraintWithItem:self.viewfinder
                                                                    attribute:NSLayoutAttributeHeight
                                                                    relatedBy:NSLayoutRelationEqual
                                                                       toItem:self.view
                                                                    attribute:NSLayoutAttributeHeight
                                                                   multiplier:currentElement.scanningRegionHeight
                                                                     constant:0.0]];
    [self.currentConstraints addObject:[NSLayoutConstraint constraintWithItem:self.viewfinder
                                                                    attribute:NSLayoutAttributeLeading
                                                                    relatedBy:NSLayoutRelationEqual
                                                                       toItem:self.view
                                                                    attribute:NSLayoutAttributeLeading
                                                                   multiplier:1.0
                                                                     constant:xMargin]];
    [self.currentConstraints addObject:[NSLayoutConstraint constraintWithItem:self.viewfinder
                                                                    attribute:NSLayoutAttributeTrailing
                                                                    relatedBy:NSLayoutRelationEqual
                                                                       toItem:self.view
                                                                    attribute:NSLayoutAttributeTrailing
                                                                   multiplier:1.0
                                                                     constant:-xMargin]];

    for (NSLayoutConstraint *constraint in self.currentConstraints) {
        [self.view addConstraint:constraint];
    }

    self.scanningRegion = CGRectMake((self.viewfinder.frame.origin.x) / self.view.frame.size.width, (self.viewfinder.frame.origin.y) / self.view.frame.size.height,
                                     (self.viewfinder.frame.size.width) / self.view.frame.size.width, (self.viewfinder.frame.size.height) / self.view.frame.size.height);

}

- (void)updateScanningRegion {

    [self.view layoutIfNeeded];

    [self updateScanningRegionArea];

    [UIView animateWithDuration:0.4
                     animations:^{
                        [self.view layoutIfNeeded];
                     }];
}

#pragma mark - Status bar

- (BOOL)prefersStatusBarHidden {
    return NO;
}

- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleLightContent;
}

#pragma mark - instantiation

+ (instancetype)allocFromNibName:(NSString *)nibName {
    PPFormOcrOverlayViewController *vc = [[PPFormOcrOverlayViewController alloc] initWithNibName:nibName bundle:nil];
    return vc;
}

#pragma mark - UI interaction

- (IBAction)didPressClose:(id)sender {
    [self.delegate formOcrOverlayViewControllerWillClose:self];
}

- (IBAction)didPressLight:(id)sender {
    self.lightOn = [[self containerViewController] overlayViewController:self willSetTorch:!self.lightOn];
    self.buttonLight.selected = self.lightOn;
}

- (IBAction)didPressHelp:(id)sender {
    PPBlinkOcrHelpViewController *helpVC = [PPBlinkOcrHelpViewController allocFromStoryboardWithName:@"PPBlinkOcrHelp"];
    helpVC.delegate = self;
    helpVC.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
    [self presentViewController:helpVC animated:YES completion:nil];
}

- (IBAction)didTapNext:(id)sender {

    PPScanElement *scanElement = ((PPScanElement *)[self.scanElements objectAtIndex:self.currentElementIndex]);

    scanElement.value = self.scanResultView.textField.text;
    self.scanResultView.textField.text = @"";

    if (self.currentElementIndex < self.scanElements.count - 1) {
        [self.pivotView moveForward];
    } else {
        [self.delegate formOcrOverlayViewController:self didFinishScanningWithElements:self.scanElements];
    }
}

#pragma mark - PPBlinkOcrHelpViewControllerDelegate

- (void)blinkOcrHelpViewControllerDelegateWillClose:(PPBlinkOcrHelpViewController *)viewController {
    [viewController dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - PPPivotViewDelegate

- (void)pivotView:(PPPivotView *)pivotView willSelectIndex:(NSUInteger)index {

    self.buttonNext.userInteractionEnabled = NO;
    self.movingPivotView = YES;

    PPScanElement *oldScanElement = ((PPScanElement *)[self.scanElements objectAtIndex:self.currentElementIndex]);
    oldScanElement.scanned = NO;
    oldScanElement.edited = NO;

    PPScanElement *scanElement = ((PPScanElement *)[self.scanElements objectAtIndex:index]);

    self.labelNextButton.text = @"Skip";

    [self buttonNextEnable:NO];

    [UIView transitionWithView:self.labelTooltip
                      duration:self.pivotView.moveAnimationDuration
                       options:UIViewAnimationOptionTransitionCrossDissolve
                    animations:^{
                        self.labelTooltip.text = scanElement.localizedTooltip;
                    }
                    completion:nil];

    [self hideResultView];
}

- (void)pivotView:(PPPivotView *)pivotView didSelectIndex:(NSUInteger)index {

    self.buttonNext.userInteractionEnabled = YES;
    self.movingPivotView = NO;

    self.currentElementIndex = index;

    PPScanElement *scanElement = ((PPScanElement *)[self.scanElements objectAtIndex:self.currentElementIndex]);

    [self setupSettingsForScanElement:scanElement];

    [self updateScanningRegion];
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
            [self processOcrRecognizerResult:ocrRecognizerResult];
        }
        if ([result isKindOfClass:[PPBarDecoderRecognizerResult class]]) {
            PPBarDecoderRecognizerResult *barDecoderResult = (PPBarDecoderRecognizerResult *)result;
            [self processBarcodeResult:[barDecoderResult stringUsingGuessedEncoding]];
        }

        if ([result isKindOfClass:[PPZXingRecognizerResult class]]) {
            PPZXingRecognizerResult *zxingResult = (PPZXingRecognizerResult *)result;
            [self processBarcodeResult:[zxingResult stringUsingGuessedEncoding]];
        }
    }
}
- (BOOL)isValidResult:(NSString *)result {

    if (result == nil || [result length] == 0) {
        return NO;
    }

    PPScanElement *element = ((PPScanElement *)[self.scanElements objectAtIndex:self.currentElementIndex]);
    if (![element.factory isKindOfClass:[PPVinOcrParserFactory class]]) {
        return YES; // we only check VIN numbers
    }

    int countI = 0;

    for (int i = 0; i < [result length]; i++) {
        unichar c = [result characterAtIndex:i];
        if (c == 'i' || c == 'I' || c == '1' || c == 'j' || c == 'T' || c == 'U' || c == 'H') {
            countI++;
        }
    }

    if (countI / (float) [result length] > 0.8) {
        return NO;
    }
    
    return YES;
}

- (void)addImageToScanElement:(PPScanElement *)element {
    element.image = self.currentImageMetadata.image;
    element.imageQuality = self.currentImageMetadata.frameQuality;
}

- (void)processBarcodeResult:(NSString *)barcodeResult {

    if (self.movingPivotView) {
        return;
    }

    PPScanElement *element = ((PPScanElement *)[self.scanElements objectAtIndex:self.currentElementIndex]);

    if (element.edited) {
        return;
    }

    NSString *val = barcodeResult;
    if (![self isValidResult:val]) {
        return;
    }

    element.value = val;

    if (!element.scanned) {
        element.scanned = YES;

        self.scanResultView.textField.text = val;
        [self addImageToScanElement:element];

        [self buttonSkipEnable:NO];
        [self buttonNextEnable:YES];

        self.labelNextButton.text = @"Continue";

        [self showResultView];
    } else {
        if ([self.scanResultView.textField.text isEqualToString:val]) {
            CGFloat oldQuality = element.imageQuality;
            CGFloat newQuality = self.currentImageMetadata.frameQuality;
            if (oldQuality < newQuality) {
                [self addImageToScanElement:element];
            }
            return;
        }

        [self addImageToScanElement:element];

        [UIView transitionWithView:self.scanResultView.textField
                          duration:self.pivotView.moveAnimationDuration / 2
                           options:UIViewAnimationOptionTransitionCrossDissolve
                        animations:^{
                            self.scanResultView.textField.text = val;
                        }
                        completion:nil];
    }

}

- (void)processOcrRecognizerResult:(PPBlinkOcrRecognizerResult *)ocrRecognizerResult {

    if (self.movingPivotView) {
        return;
    }

    PPScanElement *element = ((PPScanElement *)[self.scanElements objectAtIndex:self.currentElementIndex]);

    if (element.edited) {
        return;
    }

    NSString *val = [ocrRecognizerResult parsedResultForName:element.identifier];
    if (![self isValidResult:val]) {
        return;
    }

    // Group IBAN characters into groups of 4
    if ([element.factory class] == [PPIbanOcrParserFactory class]) {
        NSMutableString *separatedIban = [val mutableCopy];
        for (int i = 0; i < val.length; i += 4) {
            [separatedIban insertString:@" " atIndex:i + i / 4];
        }
        val = separatedIban;
    }


    if (val == nil || [val length] == 0) {
        return;
    }

    element.value = val;

    if (!element.scanned) {
        element.scanned = YES;

        self.scanResultView.textField.text = val;
        [self addImageToScanElement:element];

        [self buttonSkipEnable:NO];
        [self buttonNextEnable:YES];

        self.labelNextButton.text = @"Continue";

        [self showResultView];
    } else {
        if ([self.scanResultView.textField.text isEqualToString:val]) {
            CGFloat oldQuality = element.imageQuality;
            CGFloat newQuality = self.currentImageMetadata.frameQuality;
            if (oldQuality < newQuality) {
                [self addImageToScanElement:element];
            }
            return;
        }

        [self addImageToScanElement:element];

        [UIView transitionWithView:self.scanResultView.textField
                          duration:self.pivotView.moveAnimationDuration / 2
                           options:UIViewAnimationOptionTransitionCrossDissolve
                        animations:^{
                          self.scanResultView.textField.text = val;
                        }
                        completion:nil];
    }
}

#pragma mark - UI stuff when displaying result

- (CGRect)scanResultViewFrame {

    CGFloat margin = 20;
    CGFloat top = self.viewfinder.frame.origin.y + self.viewfinder.frame.size.height + 2 * margin;

    return CGRectMake(margin, top, self.view.frame.size.width - 2 * margin, self.view.frame.size.height - top - margin);
}

- (CGRect)scanResultViewWithKeyboardFrame {
    CGFloat margin = 20;
    CGFloat top = self.pivotViewContainer.center.y + self.pivotView.frame.size.height / 2;

    return CGRectMake(margin, top, self.view.frame.size.width - 2 * margin, self.view.frame.size.height - margin - top);
}

- (void)showResultView {

    [self.scanResultView animateShowFromViewCenter:self.viewfinder
                                           toFrame:self.resultViewPlaceholder
                                 animationDuration:0.3
                                        completion:^(BOOL finished) {
                                          self.scanResultView.userInteractionEnabled = YES;
                                        }];
}

- (void)hideResultView {

    [self.scanResultView.textField endEditing:YES];

    self.scanResultView.userInteractionEnabled = NO;

    [self.scanResultView animateHideToViewCenter:self.buttonNext animationDuration:0.3 completion:nil];
}

#pragma mark - Autorotation

// If settings.uiSettings.autorotateOverlay is set to YES, this method defines supported orientations.
- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskAllButUpsideDown;
}

@end
