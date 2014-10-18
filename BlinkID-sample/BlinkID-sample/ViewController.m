//
//  ViewController.m
//  BlinkID-sample
//
//  Created by Jura on 18/10/14.
//  Copyright (c) 2014 MicroBlink. All rights reserved.
//

#import "ViewController.h"

#import <BlinkIDFramework/PPBlinkID.h>

@interface ViewController () <PPPhotoPayDelegate, UIAlertViewDelegate>

@property (nonatomic, strong) UIViewController<PPScanningViewController>* cameraViewController;

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

- (IBAction)scanPressed:(id)sender {

    // Check if scanning is supported
    NSError *error;
    if ([PPCoordinator isPhotoPayUnsupported:&error]) {
        NSString *messageString = [error localizedDescription];
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Warning"
                                                        message:messageString
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil, nil];
        [alert show];
        return;
    }
    
    // get coordinator
    PPCoordinator *rec = [[PPCoordinator alloc] initWithSettings:[self coordinatorSettings]];

    // get camera view controller
    self.cameraViewController = [rec cameraViewControllerWithDelegate:self];

    // present it modally
    [self presentViewController:self.cameraViewController animated:YES completion:nil];
}

#pragma mark - BlinkID

- (NSMutableDictionary*)coordinatorSettings {
    NSMutableDictionary* coordinatorSettings = [[NSMutableDictionary alloc] init];

    [coordinatorSettings setValue:@(YES) forKey:kPPUseVideoPresetHigh];
    [coordinatorSettings setValue:@(YES) forKey:kPPPresentModal];
    [coordinatorSettings setValue:@(1000) forKey:kPPPartialRecognitionTimeoutInterval];

    [coordinatorSettings setValue:@(YES) forKey:kPPRecognizeUSDLKey];
    [coordinatorSettings setValue:@(YES) forKey:kPPRecognizeIdCardMrtd];

    [coordinatorSettings setValue:@(YES) forKey:kPPAutofocusFull];

    [coordinatorSettings setValue:@(YES) forKey:kPPOverlayShouldAutorotate];

    [coordinatorSettings setValue:@(YES) forKey:kPPShowOcrResults];

    [coordinatorSettings setValue:@"UN2A-BHCE-VARH-A6PJ-FPPY-V3CJ-BI35-F4U6" forKey:kPPLicenseKey];

    // Define the sound filename played on successful recognition
    NSString* soundPath = [[NSBundle mainBundle] pathForResource:@"beep" ofType:@"mp3"];
    [coordinatorSettings setValue:soundPath forKey:kPPSoundFile];

    return coordinatorSettings;
}

#pragma mark - PPBarcodeDelegate

- (void)cameraViewControllerWasClosed:(id<PPScanningViewController>)cameraViewController {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)cameraViewController:(UIViewController<PPScanningViewController> *)cameraViewController didOutputResults:(NSArray *)results {

    for (PPBaseResult* result in results) {
        if ([result resultType] == PPBaseResultTypeIDCard && [result isKindOfClass:[PPIdCardResult class]]) {
            PPIdCardResult* idCardResult = (PPIdCardResult*)result;
            [self processIdResult:idCardResult cameraViewController:cameraViewController];
        } else if ([result resultType] == PPBaseResultTypeUSDL && [result isKindOfClass:[PPUSDLResult class]]) {
            PPUSDLResult* usdlResult = (PPUSDLResult*)result;
            [self processUSDLResult:usdlResult cameraViewController:cameraViewController];
        }
    }
}

- (void)processUSDLResult:(PPUSDLResult*)result
     cameraViewController:(id<PPScanningViewController>)cameraViewController {

    [cameraViewController pauseScanning];

    NSString *title = @"USDL";
    NSString* message = [result description];

    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:title
                                                        message:message
                                                       delegate:self
                                              cancelButtonTitle:@"Close"
                                              otherButtonTitles: nil];

    [alertView show];
}

- (void)processIdResult:(PPIdCardResult*)result
   cameraViewController:(id<PPScanningViewController>)cameraViewController {

    [cameraViewController pauseScanning];

    NSString *title = @"ID card";
    NSString* message = [result description];

    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:title
                                                        message:message
                                                       delegate:self
                                              cancelButtonTitle:@"Close"
                                              otherButtonTitles: nil];

    [alertView show];

}

#pragma mark - Alert view

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    [self.cameraViewController resumeScanning];
}

@end
