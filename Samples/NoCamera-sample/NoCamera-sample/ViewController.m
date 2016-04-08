//
//  ViewController.m
//  NoCamera-sample
//
//  Created by Jura on 28/04/15.
//  Copyright (c) 2015 MicroBlink. All rights reserved.
//

#import "ViewController.h"

#import <MobileCoreServices/MobileCoreServices.h>
#import <MicroBlink/MicroBlink.h>

@interface ViewController () <PPScanDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate>

@property (nonatomic, strong) PPCoordinator *coordinator;

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

    /** 1. Initialize the Scanning settings */

    // Initialize the scanner settings object. This initialize settings with all default values.
    PPSettings *settings = [[PPSettings alloc] init];


    /** 2. Setup the license key */

    // Visit www.microblink.com to get the license key for your app
    settings.licenseSettings.licenseKey = @"JLACBTUE-4ZVJ5QAL-VYS6LAUN-CXNQDTQ4-R6YGYBLQ-MZKL7KLF-LKTKBP5J-MVNNCHEO";


    /**
     * 3. Set up what is being scanned. See detailed guides for specific use cases.
     * Remove undesired recognizers (added below) for optimal performance.
     */


    { // Remove this if you're not using MRTD recognition

        // To specify we want to perform MRTD (machine readable travel document) recognition, initialize the MRTD recognizer settings
        PPMrtdRecognizerSettings *mrtdRecognizerSettings = [[PPMrtdRecognizerSettings alloc] init];

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

    /** 4. Initialize the Scanning Coordinator object */

    PPCoordinator *coordinator = [[PPCoordinator alloc] initWithSettings:settings];
    
    return coordinator;
}

- (IBAction)takePhoto:(id)sender {

    /** Instantiate the scanning coordinator */
    NSError *error;

    if (self.coordinator == nil) {
        self.coordinator = [self coordinatorWithError:&error];
    }

    /** If scanning isn't supported, present an error */
    if (self.coordinator == nil) {
        NSString *messageString = [error localizedDescription];
        [[[UIAlertView alloc] initWithTitle:@"Warning"
                                    message:messageString
                                   delegate:nil
                          cancelButtonTitle:@"OK"
                          otherButtonTitles:nil, nil] show];

        return;
    }

    UIImagePickerController *cameraUI = [[UIImagePickerController alloc] init];

    // Use rear camera
    cameraUI.sourceType = UIImagePickerControllerSourceTypeCamera;
    cameraUI.cameraDevice = UIImagePickerControllerCameraDeviceRear;

    // Displays a control that allows the user to choose only photos
    cameraUI.mediaTypes = [[NSArray alloc] initWithObjects: (NSString *)kUTTypeImage, nil];

    // Hides the controls for moving & scaling pictures, or for trimming movies.
    cameraUI.allowsEditing = NO;

    // Shows default camera control overlay over camera preview.
    cameraUI.showsCameraControls = YES;

    // set delegate
    cameraUI.delegate = self;

    // Show view
    [self presentViewController:cameraUI animated:YES completion:nil];
}

- (IBAction)openGallery:(id)sender {

    /** Instantiate the scanning coordinator */
    NSError *error;

    if (self.coordinator == nil) {
        self.coordinator = [self coordinatorWithError:&error];
    }

    /** If scanning isn't supported, present an error */
    if (self.coordinator == nil) {
        NSString *messageString = [error localizedDescription];
        [[[UIAlertView alloc] initWithTitle:@"Warning"
                                    message:messageString
                                   delegate:nil
                          cancelButtonTitle:@"OK"
                          otherButtonTitles:nil, nil] show];

        return;
    }

    UIImagePickerController *cameraUI = [[UIImagePickerController alloc] init];

    // Use photo library
    cameraUI.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;

    // Displays a control that allows the user to choose only photos
    cameraUI.mediaTypes = [[NSArray alloc] initWithObjects: (NSString *)kUTTypeImage, nil];

    // Hides the controls for moving & scaling pictures, or for trimming movies.
    cameraUI.allowsEditing = NO;

    // set delegate
    cameraUI.delegate = self;

    // Show view
    [self presentViewController:cameraUI animated:YES completion:nil];
}

#pragma mark - UIImagePickerControllerDelegate

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info {
    NSString *mediaType = [info objectForKey: UIImagePickerControllerMediaType];

    // Handle a still image capture
    if (CFStringCompare((CFStringRef) mediaType, kUTTypeImage, 0) == kCFCompareEqualTo) {
        UIImage *originalImage = (UIImage *)[info objectForKey: UIImagePickerControllerOriginalImage];

        // Process the selected image
        [self.coordinator processImage:originalImage
                        scanningRegion:CGRectMake(0.0, 0.0, 1.0, 1.0)
                              delegate:self];
    }

    [self dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - PPScanDelegate

- (void)scanningViewControllerUnauthorizedCamera:(UIViewController<PPScanningViewController>*)scanningViewController {
    // When using direct processing, this can never happen as no camera session is started inside the SDK
}

- (void)scanningViewController:(UIViewController<PPScanningViewController>*)scanningViewController
                  didFindError:(NSError*)error {
    // can be ignored
}

- (void)scanningViewControllerDidClose:(UIViewController<PPScanningViewController>*)scanningViewController {
    // When using direct processing, this can never happen as no scanning view controller is presented
}

- (void)scanningViewController:(UIViewController<PPScanningViewController>*)scanningViewController
              didOutputResults:(NSArray*)results {

    /**
     * Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.
     * Each member of results array will represent one result for a single processed image
     * Usually there will be only one result. Multiple results are possible when there are 2 or more detected objects on a single image (i.e. pdf417 and QR code side by side)
     */

    // first, pause scanning until we process all the results
    [scanningViewController pauseScanning];

    NSString* message = @"No results";
    NSString* title = @"No results";

    // Collect data from the result
    for (PPRecognizerResult* result in results) {

        if ([result isKindOfClass:[PPMrtdRecognizerResult class]]) {
            /** MRTD was detected */
            PPMrtdRecognizerResult* mrtdResult = (PPMrtdRecognizerResult*)result;
            title = @"MRTD";
            message = [mrtdResult description];
        }
        if ([result isKindOfClass:[PPUsdlRecognizerResult class]]) {
            /** USDL was detected */
            PPUsdlRecognizerResult* usdlResult = (PPUsdlRecognizerResult*)result;
            title = @"USDL";
            message = [usdlResult description];
        }
        if ([result isKindOfClass:[PPEudlRecognizerResult class]]) {
            /** EUDL was detected */
            PPEudlRecognizerResult* eudlResult = (PPEudlRecognizerResult*)result;
            title = @"EUDL";
            message = [eudlResult description];
        }
        if ([result isKindOfClass:[PPMyKadRecognizerResult class]]) {
            /** MyKad was detected */
            PPMyKadRecognizerResult* myKadResult = (PPMyKadRecognizerResult*)result;
            title = @"MyKad";
            message = [myKadResult description];
        }
    }

    // present the alert view with scanned results
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}

@end
