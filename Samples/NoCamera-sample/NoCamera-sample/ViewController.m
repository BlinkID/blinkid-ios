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
    settings.licenseSettings.licenseKey = @"JLACBTUE-4ZVJ5QAL-VYS6LAUN-CXNQDTQ4-R6YGYBLQ-MZKL7KLF-LKTKBP5J-MVNNCHEO";


    /**
     * 3. Set up what is being scanned. See detailed guides for specific use cases.
     * Here's an example for initializing MRTD and USDL scanning
     */

    // To specify we want to perform MRTD (machine readable travel document) recognition, initialize the MRTD recognizer settings
    PPMrtdRecognizerSettings *mrtdRecognizerSettings = [[PPMrtdRecognizerSettings alloc] init];

    // Add MRTD Recognizer setting to a list of used recognizer settings
    [settings.scanSettings addRecognizerSettings:mrtdRecognizerSettings];

    // To specify we want to perform USDL (US Driver's license) recognition, initialize the USDL recognizer settings
    PPUsdlRecognizerSettings *usdlRecognizerSettings = [[PPUsdlRecognizerSettings alloc] init];

    // Add USDL Recognizer setting to a list of used recognizer settings
    [settings.scanSettings addRecognizerSettings:usdlRecognizerSettings];


    /** 4. Initialize the Scanning Coordinator object */

    PPCoordinator *coordinator = [[PPCoordinator alloc] initWithSettings:settings];
    
    return coordinator;
}

- (IBAction)takePhoto:(id)sender {


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

    // set coordinator ivar
    self.coordinator = coordinator;

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

#pragma mark - UIImagePickerControllerDelegate

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info {
    NSString *mediaType = [info objectForKey: UIImagePickerControllerMediaType];

    // Handle a still image capture
    if (CFStringCompare((CFStringRef) mediaType, kUTTypeImage, 0) == kCFCompareEqualTo) {
        UIImage *originalImage = (UIImage *)[info objectForKey: UIImagePickerControllerOriginalImage];


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

    // Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.

    // first, pause scanning until we process all the results
    [scanningViewController pauseScanning];

    NSString* message = @"No results";
    NSString* title = @"No results";

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
    };

    // present the alert view with scanned results
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}

@end
