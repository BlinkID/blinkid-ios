//
//  ViewController.m
//  pdf417-sample
//
//  Created by Jura on 16/07/15.
//  Copyright (c) 2015 MicroBlink. All rights reserved.
//

#import "ViewController.h"

#import <MicroBlink/MicroBlink.h>

#import "PPCameraOverlayViewController.h"

@interface ViewController () <PPScanningDelegate, UIAlertViewDelegate>

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
 * Modify this method to include only those recognizer settings you need. This will give you optimal performance
 *
 *  @param error Error object, if scanning isn't supported
 *
 *  @return initialized coordinator
 */
- (PPCameraCoordinator *)coordinatorWithError:(NSError **)error {

    /** 0. Check if scanning is supported */

    if ([PPCameraCoordinator isScanningUnsupportedForCameraType:PPCameraTypeBack error:nil]) {
        return nil;
    }


    /** 1. Initialize the Scanning settings */

    // Initialize the scanner settings object. This initialize settings with all default values.
    PPSettings *settings = [[PPSettings alloc] init];


    /** 2. Setup the license key */

    // Visit www.microblink.com to get the license key for your app
    settings.licenseSettings.licenseKey = @"3OUAORDH-JWEQTP73-EUL75IZD-KKYNCCCE-MBAPJB5V-FGNPPGKJ-O5KARZHJ-FR4YOPHD";
    // license key is valid temporarily - until 2017-06-24


    /**
     * 3. Set up what is being scanned. See detailed guides for specific use cases.
     * Remove undesired recognizers (added below) for optimal performance.
     */


    // Remove this code if you don't need to scan Pdf417
    {
        // To specify we want to perform PDF417 recognition, initialize the PDF417 recognizer settings
        PPPdf417RecognizerSettings *pdf417RecognizerSettings = [[PPPdf417RecognizerSettings alloc] init];

        /** You can modify the properties of pdf417RecognizerSettings to suit your use-case */

        // Add PDF417 Recognizer setting to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:pdf417RecognizerSettings];
    }

    // Remove this code if you don't need to scan QR codes
    {
        // To specify we want to perform recognition of other barcode formats, initialize the ZXing recognizer settings
        PPZXingRecognizerSettings *zxingRecognizerSettings = [[PPZXingRecognizerSettings alloc] init];

        /** You can modify the properties of zxingRecognizerSettings to suit your use-case (i.e. add other types of barcodes like QR, Aztec
         * or EAN)*/
        zxingRecognizerSettings.scanQR = YES; // we use just QR code


        // Add ZXingRecognizer setting to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:zxingRecognizerSettings];
    }

    // Remove this code if you don't need Aztec scanning
    {
        // To specify we want to perform recognition of Aztec barcodes, initialize Aztec recognizer settings
        // You can obta
        PPAztecRecognizerSettings *aztecRecognizerSettings = [[PPAztecRecognizerSettings alloc] initWithManateeLibKey:@"l2CsULemUMlhwDWyYSo7Yy+2O2n+KDrlN3ZsYcP98so="];

        // Add AztecRecognizerSettings to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:aztecRecognizerSettings];
    }

    PPCameraCoordinator *coordinator = [[PPCameraCoordinator alloc] initWithSettings:settings delegate:nil];

    return coordinator;
}

- (IBAction)didTapScan:(id)sender {

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

    /** Create new scanning view controller */
    UIViewController<PPScanningViewController> *scanningViewController =
        [PPViewControllerFactory cameraViewControllerWithDelegate:self coordinator:coordinator error:nil];

    // Allow scanning view controller to autorotate
    scanningViewController.autorotate = YES;
    scanningViewController.supportedOrientations = UIInterfaceOrientationMaskAllButUpsideDown;

    /** Present the scanning view controller. You can use other presentation methods as well (instead of presentViewController) */
    [self presentViewController:scanningViewController animated:YES completion:nil];
}

- (IBAction)didTapScanCustomUI:(id)sender {
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

    /** Present the scanning view controller */

    /** Init scanning view controller custom overlay */
    PPCameraOverlayViewController *overlayVC = [[PPCameraOverlayViewController alloc] init];

    /** Create new scanning view controller with desired custom overlay */
    UIViewController<PPScanningViewController> *scanningViewController =
        [PPViewControllerFactory cameraViewControllerWithDelegate:self overlayViewController:overlayVC coordinator:coordinator error:nil];

    // You can use other presentation methods as well
    [self presentViewController:scanningViewController animated:YES completion:nil];
}

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

    /**
     * Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.
     * Each member of results array will represent one result for a single processed image
     * Usually there will be only one result. Multiple results are possible when there are 2 or more detected objects on a single image
     * (i.e. pdf417 and QR code side by side)
     */

    // Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.

    // first, pause scanning until we process all the results
    [scanningViewController pauseScanning];

    NSString *message;
    NSString *title;

    // Collect data from the result
    for (PPRecognizerResult *result in results) {
        if ([result isKindOfClass:[PPZXingRecognizerResult class]]) {
            /** One of ZXing codes was detected */

            PPZXingRecognizerResult *zxingResult = (PPZXingRecognizerResult *)result;

            title = @"QR code";

            // Save the string representation of the code
            message = [zxingResult stringUsingGuessedEncoding];
        }
        if ([result isKindOfClass:[PPPdf417RecognizerResult class]]) {
            /** Pdf417 code was detected */

            PPPdf417RecognizerResult *pdf417Result = (PPPdf417RecognizerResult *)result;

            title = @"PDF417";

            // Save the string representation of the code
            message = [pdf417Result stringUsingGuessedEncoding];
        }
        if ([result isKindOfClass:[PPAztecRecognizerResult class]]) {
            /** Aztec barcode was detected */

            PPAztecRecognizerResult *aztecResult = (PPAztecRecognizerResult *)result;

            title = @"Aztec";

            // Save the string representation of the code
            message = [aztecResult barcodeStringWithGuessedEncoding];
        }

    }

    // present the alert view with scanned results
    UIAlertView *alertView =
        [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}

// dismiss the scanning view controller when user presses OK.
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
