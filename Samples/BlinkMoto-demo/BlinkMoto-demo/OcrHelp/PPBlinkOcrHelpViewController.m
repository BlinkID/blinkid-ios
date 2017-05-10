//
//  PPBlinkOcrHelpViewController.m
//  BlinkOCR-sample
//
//  Created by Jura on 10/03/15.
//  Copyright (c) 2015 MicroBlink. All rights reserved.
//

#import "PPBlinkOcrHelpViewController.h"

#import "PPBlinkOcrHelpPageViewController.h"

@interface PPBlinkOcrHelpViewController ()

@end

@implementation PPBlinkOcrHelpViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    PPBlinkOcrHelpPageViewController *pageVC = [self.storyboard instantiateViewControllerWithIdentifier:@"PPBlinkOcrHelpPageViewController"];

    [self addChildViewController:pageVC];
    [self.view insertSubview:pageVC.view belowSubview:self.closeButton];
    [pageVC didMoveToParentViewController:self];
}

- (IBAction)didTapClose:(id)sender {
    [self.delegate blinkOcrHelpViewControllerDelegateWillClose:self];
}

#pragma mark - instantiation

+ (instancetype)allocFromStoryboardWithName:(NSString *)storyboardName {
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:storyboardName bundle: nil];
    PPBlinkOcrHelpViewController *controller = (PPBlinkOcrHelpViewController*)[storyboard instantiateViewControllerWithIdentifier:@"PPBlinkOcrHelpViewController"];
    return controller;
}

#pragma mark - Status bar

- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleLightContent;
}

#pragma mark - orientation 

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}

@end
