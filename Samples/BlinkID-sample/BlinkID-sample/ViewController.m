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
- (PPCoordinator *)coordinatorWithError:(NSError**)error {

    /** 0. Check if scanning is supported */

    if ([PPCoordinator isScanningUnsupportedForCameraType:PPCameraTypeBack error:error]) {
        return nil;
    }


    /** 1. Initialize the Scanning settings */

    // Initialize the scanner settings object. This initialize settings with all default values.
    PPSettings *settings = [[PPSettings alloc] init];

    // tell which metadata you want to receive. Metadata collection takes CPU time - so use it only if necessary!
    settings.metadataSettings.dewarpedImage = YES; // get dewarped image of ID documents


    /** 2. Setup the license key */

    // Visit www.microblink.com to get the license key for your app
    settings.licenseSettings.licenseKey = @"NO3GLCN2-65O6NDWH-KFJ7IEAD-747A4K4K-XVTN2CYR-IXRWTKNZ-7JLWRKSV-BDQWXFQG"; // Valid temporarily


    /**
     * 3. Set up what is being scanned. See detailed guides for specific use cases.
     * Remove undesired recognizers (added below) for optimal performance.
     */

    { // Remove this if you're not using MRTD recognition

        // To specify we want to perform MRTD (machine readable travel document) recognition, initialize the MRTD recognizer settings
        PPMrtdRecognizerSettings *mrtdRecognizerSettings = [[PPMrtdRecognizerSettings alloc] init];

        /** You can modify the properties of mrtdRecognizerSettings to suit your use-case */

        // tell the library to get full image of the document. Setting this to YES makes sense just if
        // settings.metadataSettings.dewarpedImage = YES, otherwise it wastes CPU time.
        mrtdRecognizerSettings.dewarpFullDocument = NO;

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

    { // Remove this if you're not using UKDL recognition

        // To specify we want to perform UKDL (UK Driver's license) recognition, initialize the UKDL recognizer settings
        PPUkdlRecognizerSettings *ukdlRecognizerSettings = [[PPUkdlRecognizerSettings alloc] init];

        /** You can modify the properties of ukdlRecognizerSettings to suit your use-case */

        // If you want to save the image of the UKDL, set this to YES
        ukdlRecognizerSettings.showFullDocument = YES;

        // Add UKDL Recognizer setting to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:ukdlRecognizerSettings];
    }

    { // Remove this if you're not using MyKad recognition

        // To specify we want to perform MyKad recognition, initialize the MyKad recognizer settings
        PPMyKadRecognizerSettings *myKadRecognizerSettings = [[PPMyKadRecognizerSettings alloc] init];

        /** You can modify the properties of myKadRecognizerSettings to suit your use-case */

        // Add UKDL Recognizer setting to a list of used recognizer settings
        [settings.scanSettings addRecognizerSettings:myKadRecognizerSettings];
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

    /** Create new scanning view controller */
    UIViewController<PPScanningViewController>* scanningViewController = [coordinator cameraViewControllerWithDelegate:self];

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

    /**
     * Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.
     * Each member of results array will represent one result for a single processed image
     * Usually there will be only one result. Multiple results are possible when there are 2 or more detected objects on a single image (i.e. pdf417 and QR code side by side)
     */

    // first, pause scanning until we process all the results
    [scanningViewController pauseScanning];

    NSString* message;
    NSString* title;

    // Collect data from the result
    for (PPRecognizerResult* result in results) {

        if ([result isKindOfClass:[PPMrtdRecognizerResult class]]) {
            /** MRTD was detected */
            PPMrtdRecognizerResult* mrtdResult = (PPMrtdRecognizerResult*)result;
            title = @"MRTD";
            message = [mrtdResult description];
        }
        if ([result isKindOfClass:[PPUsdlRecognizerResult class]]) {
            /** US drivers license was detected */
            PPUsdlRecognizerResult* usdlResult = (PPUsdlRecognizerResult*)result;
            title = @"USDL";
            message = [usdlResult description];
        }
        if ([result isKindOfClass:[PPUkdlRecognizerResult class]]) {
            /** UK drivers license was detected */
            PPUkdlRecognizerResult* ukdlResult = (PPUkdlRecognizerResult*)result;
            title = @"UKDL";
            message = [ukdlResult description];
        }
        if ([result isKindOfClass:[PPMyKadRecognizerResult class]]) {
            /** MyKad was detected */
            PPMyKadRecognizerResult *myKadResult = (PPMyKadRecognizerResult *)result;
            title = @"MyKad";
            message = [myKadResult description];
        }
    };

    // present the alert view with scanned results
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController didOutputMetadata:(PPMetadata *)metadata {

    // Check if metadata obtained is image. You can set what type of image is outputed by setting different properties of PPMetadataSettings (currently, dewarpedImage is set at line 57)
    if ([metadata isKindOfClass:[PPImageMetadata class]]) {

        PPImageMetadata *imageMetadata = (PPImageMetadata *)metadata;

        if ([imageMetadata.name isEqualToString:@"UKDL"]) {
            UIImage *ukdlImage = [imageMetadata image];
            NSLog(@"We have dewarped and trimmed image of the UKDL, with size (%@, %@)", @(ukdlImage.size.width), @(ukdlImage.size.height));
        } else if ([imageMetadata.name isEqualToString:@"MRTD"]) {
            UIImage *mrtdImage = [imageMetadata image];
            NSLog(@"We have dewarped and trimmed image of the Machine readable travel document, with size (%@, %@)", @(mrtdImage.size.width), @(mrtdImage.size.height));
        } else if ([imageMetadata.name isEqualToString:@"MyKad"]) {
            UIImage *myKadImage = [imageMetadata image];
            NSLog(@"We have dewarped and trimmed image of the MyKad, with size (%@, %@)", @(myKadImage.size.width), @(myKadImage.size.height));
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
