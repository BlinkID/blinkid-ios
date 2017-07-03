//
//  ViewController.m
//  Starbucks-sample
//
//  Created by Jure Cular on 29/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "MainViewController.h"
#import "OverlayViewController.h"
#import "ResultsViewController.h"
#import "StarbucksCardRecognizerSettings.h"

@interface MainViewController () <PPScanningDelegate, ResultsViewControllerDelegate>

@property (weak, nonatomic) IBOutlet UIButton *scanButton;

@property (strong, nonatomic) PPCameraCoordinator *coordinator;
@property (strong, nonatomic) StarbucksCardRecognizerSettings *starbucksRecognizerSettings;

@property (strong, nonatomic) UIViewController<PPScanningViewController> *scanningViewController;
@property (strong, nonatomic) OverlayViewController *overlayViewController;

@end

/* Graphical attributes */

// Scan button corner radius
static CGFloat const kScanButtonCornerRadius = 4.f;

/* String constants */

// License key, valid temporarily until 2017-07-29
static NSString *const kLicenseKey = @"VNTJKWGS-2X4DI2JT-KNSQWZAA-SM34XJOX-2E4IRXNR-VF3IBLRV-RDO3CCNF-34GMCKWM";

// Starbucks card number key title
static NSString *const kStarbucksCardNumberKey = @"Starbucks card number";

// Starbucks scan button label text
static NSString *const kScanButtonLabelText = @"SCAN";

@implementation MainViewController

#pragma mark - Lifecycle
- (void)viewDidLoad {
    [super viewDidLoad];

    self.scanButton.layer.cornerRadius = kScanButtonCornerRadius;
    self.scanButton.titleLabel.text = kScanButtonLabelText;

    self.navigationController.navigationBarHidden = YES;
}

- (PPCameraCoordinator *)coordinatorWithError:(NSError **)error {

    /** 0. Check if scanning is supported */

    if ([PPCameraCoordinator isScanningUnsupportedForCameraType:PPCameraTypeBack error:error]) {
        return nil;
    }

    /** 1. Initialize the Scanning settings */

    // Initialize the scanner settings object. This initialize settings with all default values.
    PPSettings *settings = [[PPSettings alloc] init];

    settings.metadataSettings.successfulFrame = YES;
    settings.metadataSettings.dewarpedImage = YES;

    /** 2. Setup the license key */

    // Visit www.microblink.com to get the license key for your app
    settings.licenseSettings.licenseKey = @"VNTJKWGS-2X4DI2JT-KNSQWZAA-SM34XJOX-2E4IRXNR-VF3IBLRV-RDO3CCNF-34GMCKWM";
    // License key is valid temporarily until 2017-05-01


    PPPdf417RecognizerSettings *pdf417RecognizerSettings = [[PPPdf417RecognizerSettings alloc] init];
    [settings.scanSettings addRecognizerSettings:pdf417RecognizerSettings];

    self.starbucksRecognizerSettings = [[StarbucksCardRecognizerSettings alloc] init];
    [settings.scanSettings addRecognizerSettings:self.starbucksRecognizerSettings];

    /** 4. Initialize the Scanning Coordinator object */
    PPCameraCoordinator *coordinator = [[PPCameraCoordinator alloc] initWithSettings:settings delegate:nil];

    return coordinator;
}

- (IBAction)didTapScanButton:(id)sender {

    /** Instantiate the scanning coordinator */
    NSError *error;

    if (!self.coordinator) {
        self.coordinator = [self coordinatorWithError:&error];
    }

    /** Create new scanning view controller */

    self.overlayViewController = [OverlayViewController viewControllerFromStoryboard];
    self.scanningViewController = [PPViewControllerFactory cameraViewControllerWithDelegate:self
                                                                      overlayViewController:self.overlayViewController
                                                                                coordinator:self.coordinator
                                                                                      error:nil];

    // allow rotation if VC is displayed as a modal view controller
    self.scanningViewController.autorotate = YES;
    self.scanningViewController.supportedOrientations = UIInterfaceOrientationMaskAll;

    /** Present the scanning view controller. You can use other presentation methods as well (instead of presentViewController) */
    [self presentViewController:self.scanningViewController animated:YES completion:nil];
}

#pragma mark - PPScanDelegate

- (void)scanningViewControllerUnauthorizedCamera:(UIViewController<PPScanningViewController> *)scanningViewController {
    // Add any logic which handles UI when app user doesn't allow usage of the phone's camera
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController didFindError:(NSError *)error {
    // Can be ignored. See description of the method
}

- (void)scanningViewControllerDidClose:(UIViewController<PPScanningViewController> *)scanningViewController {

    // As scanning view controller is presented full screen and modally, dismiss it
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController didOutputResults:(NSArray *)results {
    [scanningViewController pauseScanning];
    [scanningViewController pauseCamera];

    NSDictionary *resultsMap;

    // Collect data from the result
    for (PPRecognizerResult *result in results) {

        if ([result isKindOfClass:[PPPdf417RecognizerResult class]]) {
            PPPdf417RecognizerResult *ocrResult = (PPPdf417RecognizerResult *)result;
            resultsMap = @{kStarbucksCardNumberKey : [ocrResult stringUsingGuessedEncoding]};
            break;
        } else if ([result isKindOfClass:[PPBlinkOcrRecognizerResult class]]) {
            PPBlinkOcrRecognizerResult *ocrResult = (PPBlinkOcrRecognizerResult *)result;
            resultsMap = [self.starbucksRecognizerSettings extractMessageFromResult:ocrResult];
            break;
        }
    }

    [self.overlayViewController setAllElementsToHidden:YES];
    self.overlayViewController.pausedCameraImageView.hidden = NO;

    ResultsViewController *resultsViewController = [[ResultsViewController alloc] initWithLabelsMap:resultsMap];
    resultsViewController.delegate = self;

    [resultsViewController.view setTranslatesAutoresizingMaskIntoConstraints:NO];

    [scanningViewController addChildViewController:resultsViewController];
    [scanningViewController.view addSubview:resultsViewController.view];
    [resultsViewController didMoveToParentViewController:scanningViewController];

    [resultsViewController.view.centerXAnchor constraintEqualToAnchor:scanningViewController.view.centerXAnchor constant:0.f].active = YES;
    [resultsViewController.view.centerYAnchor constraintEqualToAnchor:scanningViewController.view.centerYAnchor constant:0.f].active = YES;
    [resultsViewController.view.widthAnchor constraintEqualToAnchor:scanningViewController.view.widthAnchor constant:0.f].active = YES;
    [resultsViewController.view.heightAnchor constraintEqualToAnchor:scanningViewController.view.heightAnchor constant:0.f].active = YES;

    [scanningViewController.view layoutIfNeeded];
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanninvViewController
    didFinishDetectionWithResult:(PPDetectorResult *)result {
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
             didOutputMetadata:(PPMetadata *)metadata {

    if ([metadata isKindOfClass:[PPImageMetadata class]]) {

        PPImageMetadata *imageMetadata = (PPImageMetadata *)metadata;
        self.overlayViewController.pausedCameraImageView.image = imageMetadata.image;
    }
}

#pragma mark - ResultsViewControllerDelegate

- (void)didTapSubmitButton:(ResultsViewController *)viewController {
    [self.scanningViewController dismissViewControllerAnimated:YES completion:nil];
}

- (void)didTapCloseButton:(ResultsViewController *)viewController {
    [self.overlayViewController setAllElementsToHidden:NO];
    self.overlayViewController.pausedCameraImageView.hidden = YES;

    [viewController willMoveToParentViewController:nil];
    [viewController.view removeFromSuperview];
    [viewController removeFromParentViewController];

    [self.scanningViewController resumeCamera];
    [self.scanningViewController resumeScanningAndResetState:YES];
}

@end
