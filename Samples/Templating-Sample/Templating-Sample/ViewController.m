//
//  ViewController.m
//  Templating-Sample
//
//  Created by Dino on 08/06/16.
//  Copyright © 2016 Dino. All rights reserved.
//

#import "ViewController.h"
#import "CroIdRecognizerSettings.h"
#import "StarbucksCardRecognizerSettings.h"
#import "CustomOverlayViewController.h"

@import MicroBlink;

@interface ViewController () <PPScanningDelegate>

@end

@implementation ViewController
PPBlinkOcrRecognizerSettings *ocrSetttings;
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
- (PPCameraCoordinator *)coordinatorWithError:(NSError **)error withOcrSettings:(PPBlinkOcrRecognizerSettings *)ocrSettings {

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
    settings.licenseSettings.licenseKey = @"IT7ENADM-MJMB6M5R-K6FIAED5-YEMGIHG6-AVRYB2FL-P2SQ4A4R-WKVX4BLC-KMDNEMEK";
    // License key is valid temporarily until 2017-05-01


    /**********************************************************************************************************************/
    /**************  For Croatian ID sample images please check Croatian_ID_Images.xcassets in this project  **************/
    /**********************************************************************************************************************/


    /**
     * 3. Set up what is being scanned. See detailed guides for specific use cases.
     * Remove undesired recognizers (added below) for optimal performance.
     */

    [settings.scanSettings addRecognizerSettings:ocrSettings];


    /** 4. Initialize the Scanning Coordinator object */

    PPCameraCoordinator *coordinator = [[PPCameraCoordinator alloc] initWithSettings:settings delegate:nil];

    return coordinator;
}

- (IBAction)didTapScan:(id)sender {

    /** Instantiate the scanning coordinator */
    NSError *error;
    if (!ocrSetttings || [ocrSetttings isKindOfClass:[StarbucksCardRecognizerSettings class]]) {
        ocrSetttings = [[CroIdRecognizerSettings alloc] init];
    }
    PPCameraCoordinator *coordinator = [self coordinatorWithError:&error withOcrSettings:ocrSetttings];

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

- (IBAction)didTapScanStarbucks:(id)sender {

    /** Instantiate the scanning coordinator */
    NSError *error;
    if (!ocrSetttings || [ocrSetttings isKindOfClass:[CroIdRecognizerSettings class]]) {
        ocrSetttings = [[StarbucksCardRecognizerSettings alloc] init];
    }
    PPCameraCoordinator *coordinator = [self coordinatorWithError:&error withOcrSettings:self.ocrSetttings];

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

    PPModernBaseOverlayViewController *overlay = [[CustomOverlayViewController alloc] init];

    UIViewController<PPScanningViewController> *scanningViewController =
        [PPViewControllerFactory cameraViewControllerWithDelegate:self overlayViewController:overlay coordinator:coordinator error:nil];

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

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController didOutputResults:(NSArray *)results {

    /**
     * Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.
     * Each member of results array will represent one result for a single processed image
     * Usually there will be only one result. Multiple results are possible when there are 2 or more detected objects on a single image
     * (i.e. pdf417 and QR code side by side)
     */

    // first, pause scanning until we process all the results
    [scanningViewController pauseScanning];

    NSString *message;
    NSString *title = @"Results";

    // Collect data from the result
    for (PPRecognizerResult *result in results) {

        if ([result isKindOfClass:[PPBlinkOcrRecognizerResult class]]) {
            if ([ocrSetttings isKindOfClass:[CroIdRecognizerSettings class]]) {
                /** MRTD was detected */
                PPBlinkOcrRecognizerResult *ocrResult = (PPBlinkOcrRecognizerResult *)result;
                message = [(CroIdRecognizerSettings *)ocrSetttings extractMessageFromResult:ocrResult];
            } else if ([ocrSetttings isKindOfClass:[StarbucksCardRecognizerSettings class]]) {
                PPBlinkOcrRecognizerResult *ocrResult = (PPBlinkOcrRecognizerResult *)result;
                message = [(StarbucksCardRecognizerSettings *)ocrSetttings extractMessageFromResult:ocrResult];
            }
        }
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

        if ([imageMetadata.name isEqualToString:@"EUDL"]) {
            UIImage *eudlImage = [imageMetadata image];
            NSLog(@"We have dewarped and trimmed image of the EUDL, with size (%@, %@)", @(eudlImage.size.width), @(eudlImage.size.height));
        } else if ([imageMetadata.name isEqualToString:@"MRTD"]) {
            UIImage *mrtdImage = [imageMetadata image];
            NSLog(@"We have dewarped and trimmed image of the Machine readable travel document, with size (%@, %@)",
                  @(mrtdImage.size.width), @(mrtdImage.size.height));
        } else if ([imageMetadata.name isEqualToString:@"MyKad"]) {
            UIImage *myKadImage = [imageMetadata image];
            NSLog(@"We have dewarped and trimmed image of the MyKad, with size (%@, %@)", @(myKadImage.size.width),
                  @(myKadImage.size.height));
        } else {
            UIImage *image = [imageMetadata image];
            NSLog(@"We have image %@ with size (%@, %@)", metadata.name, @(image.size.width), @(image.size.height));
        }
    }
}

// dismiss the scanning view controller when user presses OK.
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    [self dismissViewControllerAnimated:YES completion:nil];
}


@end
