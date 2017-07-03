//
//  ViewController.m
//  Starbucks-sample
//
//  Created by Jure Cular on 29/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "MainViewController.h"
#import "OverlayViewController.h"
#import "StarbucksCardRecognizerSettings.h"

@interface MainViewController () <PPScanningDelegate>

@property (weak, nonatomic) IBOutlet UIButton *scanButton;

@property (strong, nonatomic) PPCameraCoordinator *coordinator;
@property (strong, nonatomic) StarbucksCardRecognizerSettings *starbucksRecognizerSettings;

@property (strong, nonatomic) UIViewController<PPScanningViewController> *scanningViewController;
@property (strong, nonatomic) OverlayViewController *overlayViewController;

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.scanButton.layer.cornerRadius = 4.f;
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
}
#pragma mark - ResultsViewControllerDelegate


@end
