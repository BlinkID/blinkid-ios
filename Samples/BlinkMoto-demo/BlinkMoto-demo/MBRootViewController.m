//
//  ViewController.m
//  BlinkVIN
//
//  Created by Jura on 16/09/16.
//  Copyright © 2016 MicroBlink. All rights reserved.
//

#import "MBRootViewController.h"

#import "PPOcrOverlayViewController.h"

@interface MBRootViewController () <PPOcrOverlayViewControllerDelegate>

@property (weak, nonatomic) IBOutlet UIImageView *imageProductLogo;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintImageProductLogoCenterY;

@property (weak, nonatomic) IBOutlet UIButton *buttonScanVin;
@property (weak, nonatomic) IBOutlet UIButton *buttonResults;
@property (weak, nonatomic) IBOutlet UIButton *buttonScanLicensePlates;

@end

@implementation MBRootViewController

#pragma mark - Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];

    [self hideScanButton];

    [self hideResultsButton:YES];

    self.navigationController.navigationBar.tintColor =
        [UIColor colorWithRed:22.f / 256.f green:145.f / 256.f blue:192.f / 256.f alpha:1.0];

    self.navigationController.navigationBar.titleTextAttributes =
        [NSDictionary dictionaryWithObject:[UIColor colorWithRed:22.f / 256.f green:145.f / 256.f blue:192.f / 256.f alpha:1.0]
                                    forKey:NSForegroundColorAttributeName];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    [self.navigationController setNavigationBarHidden:YES animated:animated];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];

    [self animateIntro];
}

#pragma mark - Animate intro

- (void)animateIntro {
    [self.view layoutIfNeeded];

    [UIView animateWithDuration:0.4f
        delay:0.0f
        usingSpringWithDamping:1.0f
        initialSpringVelocity:0.0f
        options:0
        animations:^{
            [self.view removeConstraint:self.constraintImageProductLogoCenterY];
            [self.view addConstraint:[NSLayoutConstraint constraintWithItem:self.imageProductLogo
                                                                  attribute:NSLayoutAttributeCenterY
                                                                  relatedBy:NSLayoutRelationEqual
                                                                     toItem:self.view
                                                                  attribute:NSLayoutAttributeBottom
                                                                 multiplier:0.3f
                                                                   constant:0.0f]];

            self.imageProductLogo.transform = CGAffineTransformMakeScale(0.8f, 0.8f);

            [self.view layoutIfNeeded];
        }
        completion:^(BOOL finished) {
            nil;
        }];

    [self showScanButton];
}

- (void)hideScanButton {
    self.buttonScanVin.hidden = YES;
    self.buttonScanVin.alpha = 0.0f;
}

- (void)showScanButton {
    [UIView animateWithDuration:0.4f
        animations:^{
            self.buttonScanVin.hidden = NO;
            self.buttonScanVin.alpha = 1.0f;
        }
        completion:^(BOOL finished) {
            nil;
        }];
}

- (void)hideResultsButton:(BOOL)hidden {

    self.buttonResults.hidden = hidden;
    self.buttonResults.alpha = hidden ? 0.0f : 1.0f;
}

#pragma mark - Button handlers

- (IBAction)buttonScanDidTap:(id)sender {
    PPCameraCoordinator *coordinator = [self createCordinator];
    [self presentFormScannerWithCoordinator:coordinator andOcrParserType:VIN];

    [self hideResultsButton:YES];
}

- (IBAction)buttonScanLicensePlateDidTap:(id)sender {
    PPCameraCoordinator *coordinator = [self createCordinator];
    [self presentFormScannerWithCoordinator:coordinator andOcrParserType:LicensePlate];
    
    [self hideResultsButton:YES];
}

- (IBAction)buttonResultsDidTap:(id)sender {
}

#pragma mark - Scanning

- (PPCameraCoordinator *)createCordinator {

    NSError *error;

    if ([PPCameraCoordinator isScanningUnsupportedForCameraType:PPCameraTypeBack error:&error]) {
        NSString *messageString = [error localizedDescription];
        [[[UIAlertView alloc] initWithTitle:@"Warning"
                                    message:messageString
                                   delegate:nil
                          cancelButtonTitle:@"OK"
                          otherButtonTitles:nil, nil] show];
        return nil;
    }

    PPSettings *settings = [[PPSettings alloc] init];
    settings.licenseSettings.licenseKey = @LICENSE_KEY;
    settings.metadataSettings.successfulFrame = YES;
    PPCameraCoordinator *coordinator = [[PPCameraCoordinator alloc] initWithSettings:settings];
    return coordinator;
}


- (void)presentFormScannerWithCoordinator:(PPCameraCoordinator *)coordinator andOcrParserType:(OcrRecognizerType)ocrRecognizerType {

    if (coordinator == nil) {
        return;
    }
    
    NSDictionary *translation = @{@"title_text" : @"Bitte die FIN / VIN oder Barcode in diesem Bereich erfassen",
                                  @"cancel_text" : @"Abbrechen",
                                  @"repeat_text" : @"Wiederholen",
                                  @"accept_text" : @"Übernehmen"};
    
    PPOcrOverlayViewController *overlayVC = [[PPOcrOverlayViewController alloc] initWithOcrRecognizerType:ocrRecognizerType andTranslation:translation];
    overlayVC.coordinator = coordinator;
    overlayVC.delegate = self;

    UIViewController<PPScanningViewController> *scanningViewController =
        [PPViewControllerFactory cameraViewControllerWithDelegate:nil
                                            overlayViewController:overlayVC
                                                      coordinator:coordinator
                                                            error:nil];
    scanningViewController.autorotate = YES;
    scanningViewController.supportedOrientations = UIInterfaceOrientationMaskAllButUpsideDown;
    overlayVC.scanningViewController = scanningViewController;
    [self presentViewController:scanningViewController animated:YES completion:nil];

    
}

#pragma mark - PPOcrOverlayViewControllerDelegate 
- (void)ocrOverlayViewControllerWillClose:(PPOcrOverlayViewController *)vc {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)ocrOverlayViewControllerDidReturnResult:(NSString *)scanResult {
    [self dismissViewControllerAnimated:YES completion:nil];
    
    [[[UIAlertView alloc] initWithTitle:@"Ergebnis"
                                message:scanResult
                               delegate:nil
                      cancelButtonTitle:@"OK"
                      otherButtonTitles:nil, nil] show];
}

@end
