//
//  RootViewController.m
//  DirectAPI-Sample
//
//  Created by Jura on 09/08/15.
//  Copyright © 2015 MicroBlink. All rights reserved.
//

#import "RootViewController.h"

#import <MobileCoreServices/MobileCoreServices.h>
#import <MicroBlink/MicroBlink.h>

@interface RootViewController () <UIImagePickerControllerDelegate, UINavigationControllerDelegate, PPCoordinatorDelegate>

@property (nonatomic) PPCoordinator *coordinator;

@end

@implementation RootViewController

static NSString *rawOcrParserId = @"RawOcrParser";

- (IBAction)openImagePicker:(id)sender {

    UIImagePickerController *imagePicker = [[UIImagePickerController alloc] init];

    imagePicker.sourceType = UIImagePickerControllerSourceTypeCamera;
    imagePicker.cameraDevice = UIImagePickerControllerCameraDeviceRear;

    // Displays a control that allows the user to choose only photos
    imagePicker.mediaTypes = [[NSArray alloc] initWithObjects:(NSString *)kUTTypeImage, nil];

    // Hides the controls for moving & scaling pictures, or for trimming movies.
    imagePicker.allowsEditing = NO;

    // Shows default camera control overlay over camera preview.
    imagePicker.showsCameraControls = YES;

    // set delegate
    imagePicker.delegate = self;

    [self presentViewController:imagePicker animated:YES completion:nil];
}

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info {
    NSString *mediaType = [info objectForKey:UIImagePickerControllerMediaType];

    // Handle a still image capture
    if (CFStringCompare((CFStringRef)mediaType, kUTTypeImage, 0) == kCFCompareEqualTo) {
        UIImage *originalImage = (UIImage *)[info objectForKey:UIImagePickerControllerOriginalImage];

        if (self.coordinator == nil) {
            [self createCoordinator];
        }

        PPImage *image = [PPImage imageWithUIImage:originalImage];
        image.cameraFrame = NO;
        image.orientation = PPProcessingOrientationLeft;
        [self.coordinator processImage:image];
    }

    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)createCoordinator {


    /** 1. Initialize the Scanning settings */

    // Initialize the scanner settings object. This initialize settings with all default values.
    PPSettings *settings = [[PPSettings alloc] init];


    /** 2. Setup the license key */

    // Visit www.microblink.com to get the license key for your app
    settings.licenseSettings.licenseKey = @"CXIHMIAT-BONQURGE-73JTZ2AE-3WQ4NKX7-JWH4EK72-RGNLB5FN-YVJUQG2A-7L24O4N7";
    // license key valid temporarily until 2017-05-01

    /**
     * 3. Set up what is being scanned. See detailed guides for specific use cases.
     * Here's an example for initializing raw OCR scanning.
     */

    // To specify we want to perform OCR recognition, initialize the OCR recognizer settings
    PPBlinkOcrRecognizerSettings *ocrRecognizerSettings = [[PPBlinkOcrRecognizerSettings alloc] init];

    // We want raw OCR parsing
    [ocrRecognizerSettings addOcrParser:[[PPRawOcrParserFactory alloc] init] name:rawOcrParserId];

    // Add the recognizer setting to a list of used recognizer
    [settings.scanSettings addRecognizerSettings:ocrRecognizerSettings];

    /** 4. Initialize the Scanning Coordinator object */

    PPCoordinator *coordinator = [[PPCoordinator alloc] initWithSettings:settings delegate:self];

    self.coordinator = coordinator;
}

- (void)coordinator:(PPCoordinator *)coordinator didOutputResults:(NSArray<PPRecognizerResult *> *)results {
    // Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.


    // Collect data from the result
    for (PPRecognizerResult *result in results) {

        if ([result isKindOfClass:[PPBlinkOcrRecognizerResult class]]) {
            PPBlinkOcrRecognizerResult *ocrRecognizerResult = (PPBlinkOcrRecognizerResult *)result;

            NSLog(@"OCR results are:");
            NSLog(@"Raw ocr: %@", [ocrRecognizerResult parsedResultForName:rawOcrParserId]);

            PPOcrLayout *ocrLayout = [ocrRecognizerResult ocrLayout];
            NSLog(@"Dimensions of ocrLayout are %@", NSStringFromCGRect([ocrLayout box]));
        }
    };
}

@end
