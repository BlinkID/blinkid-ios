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

- (IBAction)startScanning:(id)sender {

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

    PPSettings *settings = [[PPSettings alloc] init];
    settings.cameraSettings.cameraPreset = PPCameraPresetMax;
    settings.cameraSettings.cameraAutofocusRestriction = PPCameraAutofocusRestrictionNone;
    settings.licenseSettings.licenseKey = @"UN2A-BHCE-VARH-A6PJ-FPPY-V3CJ-BI35-F4U6";

    [settings.scanSettings addRecognizerSettings:[[PPMrtdRecognizerSettings alloc] init]];
    [settings.scanSettings addRecognizerSettings:[[PPUsdlRecognizerSettings alloc] init]];

    // get coordinator
    PPCoordinator *rec = [[PPCoordinator alloc] initWithSettings:settings];

    // get camera view controller
    self.cameraViewController = [rec cameraViewControllerWithDelegate:self];

    // present it modally
    [self presentViewController:self.cameraViewController animated:YES completion:nil];
}

#pragma mark - PPScanDelegate

- (void)scanningViewControllerDidClose:(UIViewController<PPScanningViewController> *)scanningViewController {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController didFindError:(NSError *)error {

}

- (void)scanningViewControllerUnauthorizedCamera:(UIViewController<PPScanningViewController> *)scanningViewController {
    // TODO: handle unauthorized cameras
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController didOutputResults:(NSArray *)results {

    for (PPRecognizerResult *result in results) {
        if ([result isKindOfClass:[PPMrtdRecognizerResult class]]) {
            PPMrtdRecognizerResult* mrtdResult = (PPMrtdRecognizerResult*)result;
            [self processMrtdResult:mrtdResult scanningViewController:scanningViewController];
        } else if ([result isKindOfClass:[PPUsdlRecognizerResult class]]) {
            PPUsdlRecognizerResult* usdlResult = (PPUsdlRecognizerResult*)result;
            [self processUSDLResult:usdlResult scanningViewController:scanningViewController];
        }
    }
}

- (void)processUSDLResult:(PPUsdlRecognizerResult*)result
   scanningViewController:(id<PPScanningViewController>)scanningViewController {

    [scanningViewController pauseScanning];

    NSString *title = @"USDL";
    NSString* message = [result description];

    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:title
                                                        message:message
                                                       delegate:self
                                              cancelButtonTitle:@"Close"
                                              otherButtonTitles: nil];

    [alertView show];
}

- (void)processMrtdResult:(PPMrtdRecognizerResult*)result
   scanningViewController:(id<PPScanningViewController>)scanningViewController {

    [scanningViewController pauseScanning];

    NSString *title = @"MRTD result";
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
    [self.cameraViewController resumeScanningAndResetState:YES];
}

@end
