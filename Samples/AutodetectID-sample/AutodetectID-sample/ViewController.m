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

@property (weak, nonatomic) IBOutlet UIImageView *documentImageView;

@property (nonatomic) UIImage *faceImage;

@property (nonatomic) UIImage *fullDocumentImage;

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
    settings.licenseSettings.licenseKey = @"Y27IQ4D7-QXTKCKFO-QX4LDPTF-3BDN3OMH-3FO6KWZW-M5B6RKDZ-U7GESRYE-MADUYVQT";
    // This demo license key is valid until 2017-06-21


    /**
     * 3. Set up what is being scanned. See detailed guides for specific use cases.
     * Remove undesired recognizers (added below) for optimal performance.
     */

    { // USE Document Face recognizer

        // To specify we want to detect ID documents with face images, instantiate PPDocumentFaceRecognizerSettings object
        PPDocumentFaceRecognizerSettings *documentFaceRecognizerSettings = [[PPDocumentFaceRecognizerSettings alloc] init];
        documentFaceRecognizerSettings.returnFullDocument = YES;

        // Add Document Face Recognizer setting to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:documentFaceRecognizerSettings];
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

        if ([result isKindOfClass:[PPDocumentFaceRecognizerResult class]]) {
            /** Document face was detected */
            PPDocumentFaceRecognizerResult *documentFaceResult = (PPDocumentFaceRecognizerResult *)result;
            title = @"Document Face";
            message = [documentFaceResult description];
        }

        // don't forget to handle other results if you have them!
    };

    // present the alert view with scanned results
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanninvViewController
    didFinishDetectionWithResult:(PPDetectorResult *)result {
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
             didOutputMetadata:(PPMetadata *)metadata {

    // Check if metadata obtained is image. You can set what type of image is outputed by setting different properties of PPMetadataSettings
    // (currently, dewarpedImage is set
    if ([metadata isKindOfClass:[PPImageMetadata class]]) {

        PPImageMetadata *imageMetadata = (PPImageMetadata *)metadata;

        // UIImage is obtained here
        UIImage *image = imageMetadata.image;

        if ([imageMetadata.name isEqualToString:@"Face"]) {
            self.faceImage = image;
        }
        if ([imageMetadata.name isEqualToString:@"DocumentFaceFullDocument"]) {
            self.fullDocumentImage = image;
            self.documentImageView.image = image;
        }


        NSLog(@"Image returned with name %@, size %@", metadata.name, NSStringFromCGSize(image.size));
    }
}

// dismiss the scanning view controller when user presses OK.
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
