//
//  PPScannedViewController.m
//  BlinkID
//
//  Created by Jura on 30/08/15.
//  Copyright (c) 2015 MicroBlink. All rights reserved.
//

#import "PPScannedViewController.h"

@interface PPScannedViewController () <UIScrollViewDelegate>

@end

@implementation PPScannedViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.scannedImage.image = [self.imageMetadata image];

    self.titleLabel.text = self.imageMetadata.name;

    self.scrollView.minimumZoomScale = 1.0;
    self.scrollView.maximumZoomScale = 6.0;
    self.scrollView.contentSize = self.scannedImage.frame.size;
    self.scrollView.delegate = self;

    self.view.alpha = 0.0f;
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];

    [UIView animateWithDuration:0.4f
                     animations:^{
        self.view.alpha = 1.0f;
    }];
}

- (IBAction)didTapRetake:(id)sender {
    [self.delegate scannedViewControllerWillClose:self];
}

- (IBAction)didTapSave:(id)sender {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        UIImageWriteToSavedPhotosAlbum(self.scannedImage.image, self, @selector(image:didFinishSavingWithError:contextInfo:), nil);
    });
}

- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo {
    dispatch_async(dispatch_get_main_queue(), ^{
        UIAlertView *av = [[UIAlertView alloc] initWithTitle:@"Success" message:@"Saved to Photos" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles: nil];
        [av show];
    });
}

#pragma mark UIScrollViewDelegate

- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView {
    return self.scannedImage;
}

#pragma mark factory methods

+ (PPScannedViewController *)viewControllerFromStoryboard:(UIStoryboard*)storyboard {
    return [storyboard instantiateViewControllerWithIdentifier:@"PPScannedViewController"];
}

+ (PPScannedViewController *)viewControllerFromStoryboardWithName:(NSString*)name
                                                           bundle:(NSBundle*)bundle {

    return [PPScannedViewController viewControllerFromStoryboard:[UIStoryboard storyboardWithName:name
                                                                                           bundle:bundle]];
}

@end
