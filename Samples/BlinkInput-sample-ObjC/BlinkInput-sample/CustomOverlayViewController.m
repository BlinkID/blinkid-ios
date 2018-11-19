//
//  CutomViewController.m
//  BlinkInput-sample
//
//  Created by Jura Skrlec on 09/11/2018.
//  Copyright © 2018 MicroBlink. All rights reserved.
//

#import "CustomOverlayViewController.h"

@interface CustomOverlayViewController()

@property (nonatomic, strong) NSString *titleAlert;
@property (nonatomic, strong) NSString *messageAlert;

@end

@implementation CustomOverlayViewController


+ (CustomOverlayViewController *)initFromStoryBoard {
    return [[UIStoryboard storyboardWithName:@"Main" bundle:nil] instantiateViewControllerWithIdentifier:@"CustomOverlayViewController"];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    super.scanningRecognizerRunnerViewControllerDelegate = self;
}

#pragma mark - MBScanningRecognizerRunnerViewControllerDelegate

- (void)recognizerRunnerViewController:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController didFinishScanningWithState:(MBRecognizerResultState)state {
    
    /** This is done on background thread */
    if (state == MBRecognizerResultStateValid) {
        [recognizerRunnerViewController pauseScanning];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            for (MBRecognizer *recognizer in self.recognizerCollection.recognizerList) {
                if (recognizer.baseResult.resultState == MBRecognizerResultStateValid) {
                    if ([recognizer isKindOfClass:[MBBarcodeRecognizer class]]) {
                        MBBarcodeRecognizer *barcodeRecognizer = (MBBarcodeRecognizer *)recognizer;
                        self.titleAlert = @"QR Code";
                        self.messageAlert = barcodeRecognizer.result.stringData;
                    }
                    else if ([recognizer isKindOfClass:[MBPdf417Recognizer class]]) {
                        MBPdf417Recognizer *pdf417Recognizer = (MBPdf417Recognizer *)recognizer;
                        self.titleAlert = @"PDF417";
                        self.messageAlert = pdf417Recognizer.result.stringData;
                    }
                    
                    UIAlertController * alert = [UIAlertController
                                                 alertControllerWithTitle:self.titleAlert
                                                 message:self.messageAlert
                                                 preferredStyle:UIAlertControllerStyleAlert];
                    
                    UIAlertAction* okButton = [UIAlertAction
                                                actionWithTitle:@"Ok"
                                                style:UIAlertActionStyleDefault
                                                handler:^(UIAlertAction * action) {
                                                    [self dismissViewControllerAnimated:YES completion:nil];
                                                }];
                    
                    [alert addAction:okButton];
                    
                    [self presentViewController:alert animated:YES completion:nil];
                }
            }
        });
    }
}

- (IBAction)didTapClose:(UIButton *)sender {
    [self.recognizerRunnerViewController overlayViewControllerWillCloseCamera:self];
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
