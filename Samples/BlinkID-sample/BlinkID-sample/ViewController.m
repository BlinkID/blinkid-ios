//
//  ViewController.m
//  BlinkID-sample
//
//  Created by Jura on 03/04/15.
//  Copyright (c) 2015 MicroBlink. All rights reserved.
//

#import "ViewController.h"

#import <MicroBlink/MicroBlink.h>

@interface ViewController () <PPScanDelegate>

@property (nonatomic, strong) UIViewController<PPScanningViewController>* cameraViewController;

@property (nonatomic, strong) PPUsdlRecognizerResult *usdlRecognizerResult;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/**
 * Method allocates and initializes the Scanning coordinator object.
 * Coordinator is initialized with settings for scanning
 *
 *  @param error Error object, if scanning isn't supported
 *
 *  @return initialized coordinator
 */
- (PPCoordinator *)coordinatorWithError:(NSError**)error {

    /** 0. Check if scanning is supported */

    if ([PPCoordinator isScanningUnsupported:error]) {
        return nil;
    }


    /** 1. Initialize the Scanning settings */

    // Initialize the scanner settings object. This initialize settings with all default values.
    PPSettings *settings = [[PPSettings alloc] init];


    /** 2. Setup the license key */

    // Visit www.microblink.com to get the license key for your app
    settings.licenseSettings.licenseKey = @"NO3GLCN2-65O6NDWH-KFJ7IEAD-747A4K4K-XVTN2CYR-IXRWTKNZ-7JLWRKSV-BDQWXFQG"; // Valid temporarily


    /** 3. Set up what is being scanned. See detailed guides for specific use cases. */

    { // Remove this if you're not using MRTD recognition

        // To specify we want to perform MRTD (machine readable travel document) recognition, initialize the MRTD recognizer settings
        PPMrtdRecognizerSettings *mrtdRecognizerSettings = [[PPMrtdRecognizerSettings alloc] init];

        // Add MRTD Recognizer setting to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:mrtdRecognizerSettings];
    }

    { // Remove this if you're not using USDL recognition

        // To specify we want to perform USDL (US Driver's license) recognition, initialize the USDL recognizer settings
        PPUsdlRecognizerSettings *usdlRecognizerSettings = [[PPUsdlRecognizerSettings alloc] init];

        // Add USDL Recognizer setting to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:usdlRecognizerSettings];
    }

    { // Remove this if you're not using UKDL recognition

        // To specify we want to perform UKDL (UK Driver's license) recognition, initialize the UKDL recognizer settings
        PPUkdlRecognizerSettings *ukdlRecognizerSettings = [[PPUkdlRecognizerSettings alloc] init];

        // Add UKDL Recognizer setting to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:ukdlRecognizerSettings];
    }

    { // Remove this if you're not using MyKad recognition

        // To specify we want to perform MyKad (Malysian ID document) recognition, initialize the MyKad recognizer settings
        PPMyKadRecognizerSettings *mykadRecognizerSettings = [[PPMyKadRecognizerSettings alloc] init];

        // Add UKDL Recognizer setting to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:mykadRecognizerSettings];
    }


    /** 4. Initialize the Scanning Coordinator object */

    PPCoordinator *coordinator = [[PPCoordinator alloc] initWithSettings:settings];

    return coordinator;
}

- (IBAction)didTapScan:(id)sender {

    /** Instantiate the scanning coordinator */
    NSError *error;
    PPCoordinator *coordinator = [self coordinatorWithError:&error];

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
    UIViewController<PPScanningViewController>* scanningViewController = [coordinator cameraViewControllerWithDelegate:self];

    // allow rotation if VC is displayed as a modal view controller
    scanningViewController.autorotate = YES;
    scanningViewController.supportedOrientations = UIInterfaceOrientationMaskAll;

    /** You can use other presentation methods as well */
    [self presentViewController:scanningViewController animated:YES completion:nil];
}

#pragma mark - PPScanDelegate

- (void)scanningViewControllerUnauthorizedCamera:(UIViewController<PPScanningViewController> *)scanningViewController {
    // Add any logic which handles UI when app user doesn't allow usage of the phone's camera
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
                  didFindError:(NSError *)error {
    // Can be ignored. See description of the method
}

- (void)scanningViewControllerDidClose:(UIViewController<PPScanningViewController> *)scanningViewController {

    // As scanning view controller is presented full screen and modally, dismiss it
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
              didOutputResults:(NSArray *)results {

    // Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.

    // first, pause scanning until we process all the results
    [scanningViewController pauseScanning];

    NSString* message;
    NSString* title;

    // Collect data from the result
    for (PPRecognizerResult* result in results) {

        if ([result isKindOfClass:[PPMrtdRecognizerResult class]]) {
            PPMrtdRecognizerResult* mrtdResult = (PPMrtdRecognizerResult*)result;
            title = @"MRTD";
            message = [mrtdResult description];
        }
        if ([result isKindOfClass:[PPUsdlRecognizerResult class]]) {
            PPUsdlRecognizerResult* usdlResult = (PPUsdlRecognizerResult*)result;
            title = @"USDL";
            message = [usdlResult description];
        }
        if ([result isKindOfClass:[PPUkdlRecognizerResult class]]) {
            PPUkdlRecognizerResult* ukdlResult = (PPUkdlRecognizerResult*)result;
            title = @"UKDL";
            message = [ukdlResult description];
        }
        if ([result isKindOfClass:[PPMyKadRecognizerResult class]]) {
            PPMyKadRecognizerResult *myKadResult = (PPMyKadRecognizerResult *)result;
            title = @"MyKad";
            message = [myKadResult description];
        }
    };

    // present the alert view with scanned results
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}

// dismiss the scanning view controller when user presses OK.
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
