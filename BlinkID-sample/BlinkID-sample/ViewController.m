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

    NSLog(@"Version is %@", [PPCoordinator getBuildVersionString]);

    return coordinatorSettings;
}

#pragma mark - PPPhotoPayDelegate

- (void)cameraViewController:(UIViewController<PPScanningViewController> *)cameraViewController didFinishWithError:(NSError *)error {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)cameraViewControllerUnauthorizedCamera:(UIViewController<PPScanningViewController> *)cameraViewController {

    CGFloat W = cameraViewController.view.frame.size.width;
    CGFloat H = cameraViewController.view.frame.size.height;
    CGFloat w = 300;
    CGFloat h = 70;

    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(cameraViewController.view.frame.origin.x + W/2 - w/2, cameraViewController.view.frame.origin.y + H/2 - h/2, w, h)];
    label.text = @"Camera not authorized.\nPlease authorize it in:\nSettings->Privacy->Camera.";
    label.textColor = [UIColor lightGrayColor];
    label.font = [UIFont systemFontOfSize:15.f];
    label.numberOfLines = 3;

    if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0")) {
        label.textAlignment = NSTextAlignmentCenter;
    }

    label.autoresizingMask = UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleBottomMargin;

    [[cameraViewController view] addSubview:label];
}

- (void)cameraViewController:(UIViewController<PPScanningViewController> *)cameraViewController didOutputResults:(NSArray *)results {

    if (results == nil) {
        // close camera view controller
        [self dismissViewControllerAnimated:YES completion:nil];
    }

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
