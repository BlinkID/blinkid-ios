//
//  ViewController.m
//  BlinkID-sample
//
//  Created by Jura on 03/04/15.
//  Copyright (c) 2015 MicroBlink. All rights reserved.
//

#import "ViewController.h"

#import <MicroBlink/MicroBlink.h>

@interface ViewController () <PPScanningDelegate>

@end

@implementation ViewController


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
    settings.licenseSettings.licenseKey = @"BWZYUA33-KUFQM5IO-FOL273UT-MG5POX5I-EID5JAMM-NIU7MMQC-LD5FPSCQ-ITKPMVG7";
    // This demo license key is valid until 2017-05-01


    /**
     * 3. Set up what is being scanned. See detailed guides for specific use cases.
     * Remove undesired recognizers (added below) for optimal performance.
     */

    { // Remove this if you're not using MRTD recognition

        // To specify we want to perform MRTD (machine readable travel document) recognition, initialize the MRTD recognizer settings
        PPMrtdRecognizerSettings *mrtdRecognizerSettings = [[PPMrtdRecognizerSettings alloc] init];
        mrtdRecognizerSettings.dewarpFullDocument = NO;

        /** You can modify the properties of mrtdRecognizerSettings to suit your use-case */

        // Add MRTD Recognizer setting to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:mrtdRecognizerSettings];
    }

    { // Remove this if you're not using USDL recognition

        // To specify we want to perform USDL (US Driver's license) recognition, initialize the USDL recognizer settings
        PPUsdlRecognizerSettings *usdlRecognizerSettings = [[PPUsdlRecognizerSettings alloc] init];

        /** You can modify the properties of usdlRecognizerSettings to suit your use-case */

        // Add USDL Recognizer setting to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:usdlRecognizerSettings];
    }

    // Add additional recognizers if necessary.
    // Check Microblink header files for all classes with RecognizerSettings suffix.

    /** 4. Initialize the Scanning Coordinator object */

    PPCameraCoordinator *coordinator = [[PPCameraCoordinator alloc] initWithSettings:settings];

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

    // allow rotation if VC is displayed as a modal view controller
    scanningViewController.autorotate = YES;
    scanningViewController.supportedOrientations = UIInterfaceOrientationMaskAll;

    /** Present the scanning view controller. You can use other presentation methods as well (instead of presentViewController) */
    [self presentViewController:scanningViewController animated:YES completion:nil];
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

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
              didOutputResults:(NSArray<PPRecognizerResult *> *)results {

    /**
     * Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.
     * Each member of results array will represent one result for a single processed image
     * Usually there will be only one result. Multiple results are possible when there are 2 or more detected objects on a single image
     * (i.e. pdf417 and QR code side by side)
     */

    // First we check that we received a valid result!
    if (results == nil || results.count == 0) {
        return;
    }

    // then, pause scanning until we process all the results
    [scanningViewController pauseScanning];

    NSString *message;
    NSString *title;

    // Collect data from the result
    for (PPRecognizerResult *result in results) {

        // default description
        message = [result description];

        title = @"Scan result";

        if ([result isKindOfClass:[PPMrtdRecognizerResult class]]) {
            /** MRTD was detected */
            PPMrtdRecognizerResult *mrtdResult = (PPMrtdRecognizerResult *)result;
            title = @"MRTD";
            message = [mrtdResult description];
        }
        if ([result isKindOfClass:[PPUsdlRecognizerResult class]]) {
            /** US drivers license was detected */
            PPUsdlRecognizerResult *usdlResult = (PPUsdlRecognizerResult *)result;
            title = @"USDL";
            message = [usdlResult description];
        }
        if ([result isKindOfClass:[PPEudlRecognizerResult class]]) {
            /** EU drivers license was detected */
            PPEudlRecognizerResult *eudlResult = (PPEudlRecognizerResult *)result;
            title = @"EUDL";
            message = [eudlResult description];
        }
        if ([result isKindOfClass:[PPMyKadRecognizerResult class]]) {
            /** MyKad was detected */
            PPMyKadRecognizerResult *myKadResult = (PPMyKadRecognizerResult *)result;
            title = @"MyKad";
            message = [myKadResult description];
        }
        if ([result isKindOfClass:[PPCroIDFrontRecognizerResult class]]) {
            /** MyKad was detected */
            PPCroIDFrontRecognizerResult *croIdFrontResult = (PPCroIDFrontRecognizerResult *)result;
            title = @"Cro ID Front";
            message = [croIdFrontResult description];
        }
        if ([result isKindOfClass:[PPCroIDBackRecognizerResult class]]) {
            /** MyKad was detected */
            PPCroIDBackRecognizerResult *croIdBackResult = (PPCroIDBackRecognizerResult *)result;
            title = @"Cro ID Back";
            message = [croIdBackResult description];
        }

        // don't forget to handle other results if you have them!
    };

    // present the alert view with scanned results
    UIAlertView *alertView =
        [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanninvViewController
    didFinishDetectionWithResult:(PPDetectorResult *)result {
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
             didOutputMetadata:(PPMetadata *)metadata {

    // Check if metadata obtained is image. You can set what type of image is outputed by setting different properties of PPMetadataSettings
    // (currently, dewarpedImage is set at line 57)
    if ([metadata isKindOfClass:[PPImageMetadata class]]) {

        PPImageMetadata *imageMetadata = (PPImageMetadata *)metadata;

        UIImage *image = [imageMetadata image];
        NSLog(@"We have image %@ with size %@", metadata.name, NSStringFromCGSize(image.size));

        if ([imageMetadata.name isEqualToString:[PPEudlRecognizerSettings FULL_DOCUMENT_IMAGE]]) {
            NSLog(@"This image is EUDL full document");
        } else if ([imageMetadata.name isEqualToString:[PPMrtdRecognizerSettings FULL_DOCUMENT_IMAGE]]) {
            NSLog(@"This image is full Machine readable travel document");
        } else if ([imageMetadata.name isEqualToString:[PPMrtdRecognizerSettings MRZ_IMAGE]]) {
            NSLog(@"This image is image of the MRZ zone");
            NSLog(@"This image becomes available if mrtdRecognizerSettings.dewarpFullDocument == NO");
        } else if ([imageMetadata.name isEqualToString:[PPMyKadRecognizerSettings FULL_DOCUMENT_IMAGE]]) {
            NSLog(@"This image is full MyKad");
        }
    }
}

// dismiss the scanning view controller when user presses OK.
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
