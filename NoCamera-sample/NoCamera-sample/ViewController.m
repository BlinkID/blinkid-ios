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

- (IBAction)takePhoto:(id)sender {
    NSLog(@"Take photo!");

    // Check if scanning is supported
    NSError *error;
    if ([PPCoordinator isScanningUnsupported:&error]) {
        NSString *messageString = [error localizedDescription];
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Warning"
                                                        message:messageString
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil, nil];
        [alert show];
        return;
    }

    /** 1. Initialize the Scanning settings */

    // Initialize the scanner settings object. This initialize settings with all default values.
    PPSettings *settings = [[PPSettings alloc] init];

    /** 2. Setup the license key */
    settings.licenseSettings.licenseKey = @"EAXLMDEB-URKOOROZ-J5TI22S2-CPPBDB4N-NJNBHXQR-Q6GWUWQT-3YIYPDLK-LIJ2TAVI";


    /** 3. Set up what is being scanned. See detailed guides for specific use cases. Here's an example for initializing raw and price OCR scanning. */

    PPMrtdRecognizerSettings *mrtdRecognizerSettings = [[PPMrtdRecognizerSettings alloc] init];
    mrtdRecognizerSettings.mrtdRoi = CGRectMake(0.0, 0.75, 1.0, 0.25);
    [settings.scanSettings addRecognizerSettings:mrtdRecognizerSettings];

    // get coordinator
    self.coordinator = [[PPCoordinator alloc] initWithSettings:settings];

    UIImagePickerController *cameraUI = [[UIImagePickerController alloc] init];

    // Use rear camera
    cameraUI.sourceType = UIImagePickerControllerSourceTypeCamera;
    cameraUI.cameraDevice = UIImagePickerControllerCameraDeviceRear;

    // Displays a control that allows the user to choose only photos
    cameraUI.mediaTypes = [[NSArray alloc] initWithObjects: (NSString *)kUTTypeImage, nil];

    // Hides the controls for moving & scaling pictures, or for trimming movies.
    cameraUI.allowsEditing = NO;

    // Shows default camera control overlay over camera preview.
    // TODO: set this to NO and provide custom overlay
    cameraUI.showsCameraControls = YES;

    // set delegate
    cameraUI.delegate = self;

    [self.coordinator initializeRecognizers];

    // Show view
    // in iOS7 (as of DP6) this shows a bugged status bar (see https://devforums.apple.com/message/861462#861462)
    // TODO: iOS 6 should be tested
    // iOS5 works OK, just like Facebook app
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
    // Perform your logic here

    for (PPRecognizerResult *result in results) {
        if ([result isKindOfClass:[PPMrtdRecognizerResult class]]) {
            PPMrtdRecognizerResult* mrtdRecognizerResult = (PPMrtdRecognizerResult*)result;

            NSString* message = [NSString stringWithFormat:@"%@ %@", [mrtdRecognizerResult primaryId], [mrtdRecognizerResult secondaryId]];

            UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"MRTD result"
                                                                message:message
                                                               delegate:nil
                                                      cancelButtonTitle:@"OK"
                                                      otherButtonTitles: nil];

            [alertView show];
        }
    };
}

@end
