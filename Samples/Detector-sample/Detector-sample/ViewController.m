//
//  ViewController.m
//  BlinkID-sample
//
//  Created by Jura on 03/04/15.
//  Copyright (c) 2015 MicroBlink. All rights reserved.
//

#import "ViewController.h"

#import <MicroBlink/MicroBlink.h>

#import "PPScannedViewController.h"

@interface ViewController () <PPScanningDelegate, PPScannedViewControllerDelegate>

@property (nonatomic, strong) UIViewController<PPScanningViewController> *cameraViewController;

@property (nonatomic, strong) PPUsdlRecognizerResult *usdlRecognizerResult;

@property (nonatomic, strong) PPImageMetadata *imageMetadata;

@property (nonatomic) CGFloat bestImageFrameQuality;

@property (nonatomic) NSUInteger numUpdates;

@property (nonatomic) BOOL frameQualityRising;

@end

@implementation ViewController

/**
 * Method allocates and initializes the Scanning coordinator object.
 * Coordinator is initialized with settings for scanning
 *
 *  @param error Error object, if scanning isn't supported
 *
 *  @return initialized coordinator
 */
- (PPCameraCoordinator *)coordinatorWithError:(NSError **)error {

    /** 0. Check if scanning is supported */

    if ([PPCameraCoordinator isScanningUnsupportedForCameraType:PPCameraTypeBack error:error]) {
        return nil;
    }


    /** 1. Initialize the Scanning settings */

    // Initialize the scanner settings object. This initialize settings with all default values.
    PPSettings *settings = [[PPSettings alloc] init];

    // tell which metadata you want to receive. Metadata collection takes CPU time - so use it only if necessary!
    settings.metadataSettings.dewarpedImage = YES; // get dewarped image of ID documents


    /** 2. Setup the license key */

    // Visit www.microblink.com to get the license key for your app
    settings.licenseSettings.licenseKey = @"ZJYY4UFT-5QDAH3LY-DP7PPMAT-U33LF3AF-ATLVMINT-5QCQJV2W-EGZ6ZJL3-MXI5JTZ4";
    // License key is valid temporarily until 2017-05-01


    /** 3. Set up what is being scanned. See detailed guides for specific use cases. */


    // Document Detector

    PPDocumentDetectorSettings *documentDetectorSettings = [[PPDocumentDetectorSettings alloc] initWithNumStableDetectionsThreshold:5];

    // ID1 specification

    PPDocumentSpecification *specificationId1 = [PPDocumentSpecification newFromPreset:PPDocumentPresetId1Card];

    NSMutableArray<PPDecodingInfo *> *documentDecodingId1 = [NSMutableArray<PPDecodingInfo *> array];
    [documentDecodingId1
        addObject:[[PPDecodingInfo alloc] initWithLocation:CGRectMake(0.0, 0.0, 1.0, 1.0) dewarpedHeight:700 uniqueId:@"ID1"]];
    [specificationId1 setDecodingInfo:documentDecodingId1];

    // ID2 specification

    PPDocumentSpecification *specificationId2 = [PPDocumentSpecification newFromPreset:PPDocumentPresetId2Card];

    NSMutableArray<PPDecodingInfo *> *documentDecodingId2 = [NSMutableArray<PPDecodingInfo *> array];
    [documentDecodingId2
        addObject:[[PPDecodingInfo alloc] initWithLocation:CGRectMake(0.0, 0.0, 1.0, 1.0) dewarpedHeight:800 uniqueId:@"ID2"]];
    [specificationId2 setDecodingInfo:documentDecodingId2];

    [documentDetectorSettings setDocumentSpecifications:@[ specificationId1, specificationId2 ]];


    // MRTD detector

    NSMutableArray<PPDecodingInfo *> *mrtdDecoding = [NSMutableArray<PPDecodingInfo *> array];
    [mrtdDecoding addObject:[[PPDecodingInfo alloc] initWithLocation:CGRectMake(0.0, 0.0, 1.0, 1.0) dewarpedHeight:700 uniqueId:@"MRTD"]];

    PPMrtdDetectorSettings *mrtdDetectorSettings = [[PPMrtdDetectorSettings alloc] initWithDecodingInfoArray:mrtdDecoding];


    // MULTI detector

    PPMultiDetectorSettings *multiDetectorSettings =
        [[PPMultiDetectorSettings alloc] initWithSettingsArray:@[ documentDetectorSettings, mrtdDetectorSettings ]];
    multiDetectorSettings.allowMultipleResults = YES;


    // Detector recognizer

    PPDetectorRecognizerSettings *detectorRecognizerSettings =
        [[PPDetectorRecognizerSettings alloc] initWithDetectorSettings:multiDetectorSettings];
    [settings.scanSettings addRecognizerSettings:detectorRecognizerSettings];

    /** 4. Initialize the Scanning Coordinator object */

    PPCameraCoordinator *coordinator = [[PPCameraCoordinator alloc] initWithSettings:settings delegate:nil];

    return coordinator;
}

- (void)resetMetadata {
    self.imageMetadata = nil;
    self.bestImageFrameQuality = -INFINITY;
    self.numUpdates = 0;
    self.frameQualityRising = YES;
}

- (IBAction)didTapScan:(id)sender {

    [self resetMetadata];

    /** Instantiate the scanning coordinator */
    NSError *error;
    PPCameraCoordinator *coordinator = [self coordinatorWithError:&error];

    /** If scanning isn't supported, present an error */
    if (coordinator == nil) {
        NSString *messageString = [error localizedDescription];
        [[[UIAlertView alloc] initWithTitle:@"Warning"
                                    message:messageString
                                   delegate:nil
                          cancelButtonTitle:@"OK"
                          otherButtonTitles:nil, nil] show];

        return;
    }

    /** Allocate and present the scanning view controller */
    self.cameraViewController = [PPViewControllerFactory cameraViewControllerWithDelegate:self coordinator:coordinator error:nil];

    // allow rotation if VC is displayed as a modal view controller
    self.cameraViewController.autorotate = YES;
    self.cameraViewController.supportedOrientations = UIInterfaceOrientationMaskAll;

    /** You can use other presentation methods as well */
    [self addChildViewController:self.cameraViewController];
    self.cameraViewController.view.frame = self.view.bounds;
    [self.view addSubview:self.cameraViewController.view];
    [self.cameraViewController didMoveToParentViewController:self];
}

#pragma mark - PPScanDelegate

- (void)scanningViewControllerUnauthorizedCamera:(UIViewController<PPScanningViewController> *)scanningViewController {
    // Add any logic which handles UI when app user doesn't allow usage of the phone's camera
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController didFindError:(NSError *)error {
    // Can be ignored. See description of the method
}

- (void)scanningViewControllerDidClose:(UIViewController<PPScanningViewController> *)scanningViewController {

    [scanningViewController willMoveToParentViewController:nil];
    [scanningViewController.view removeFromSuperview];
    [scanningViewController removeFromParentViewController];
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
             didOutputMetadata:(PPMetadata *)metadata {

    // Check if metadata obtained is image
    if ([metadata isKindOfClass:[PPImageMetadata class]]) {
        PPImageMetadata *imageMetadata = (PPImageMetadata *)metadata;

        CGFloat currentFrameQuality = imageMetadata.frameQuality;

        if (currentFrameQuality < 0.9 * self.bestImageFrameQuality) {
            self.frameQualityRising = NO;
        } else if (currentFrameQuality > self.bestImageFrameQuality) {
            self.imageMetadata = imageMetadata;
            self.bestImageFrameQuality = imageMetadata.frameQuality;
            self.numUpdates++;
        }
    }
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController didOutputResults:(NSArray *)results {

    // Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.

    // Collect data from the result
    for (PPRecognizerResult *result in results) {

        if ([result isKindOfClass:[PPDetectorRecognizerResult class]] && self.numUpdates > 2 && !self.frameQualityRising) {
            PPDetectorRecognizerResult *detectorRecognizerResult = (PPDetectorRecognizerResult *)result;
            [self showDetectorResult:detectorRecognizerResult scanningViewController:scanningViewController];
            return;
        }
    };
}

// dismiss the scanning view controller when user presses OK.
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)showDetectorResult:(PPDetectorRecognizerResult *)result
    scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController {

    // pause scanning to avoid obtaining new detector results
    [scanningViewController pauseScanning];

    PPScannedViewController *scannedVc =
        [PPScannedViewController viewControllerFromStoryboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    scannedVc.imageMetadata = self.imageMetadata;
    scannedVc.delegate = self;

    [self addChildViewController:scannedVc];
    scannedVc.view.frame = self.view.bounds;
    [self.view addSubview:scannedVc.view];
    [scannedVc didMoveToParentViewController:self];
}

#pragma mark - PPScannedViewControlerDelegate

- (void)scannedViewControllerWillClose:(PPScannedViewController *)scannedViewController {
    [UIView animateWithDuration:0.4f
        animations:^{
            scannedViewController.view.alpha = 0.0f;
        }
        completion:^(BOOL finished) {
            [scannedViewController willMoveToParentViewController:nil];
            [scannedViewController.view removeFromSuperview];
            [scannedViewController removeFromParentViewController];

            [self.cameraViewController resumeScanningAndResetState:YES];

            [self resetMetadata];
        }];
}

@end
