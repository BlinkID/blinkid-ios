//
//  OverlayViewController.m
//  Starbucks-sample
//
//  Created by Jure Cular on 29/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "OverlayViewController.h"
#import "ShadowView.h"
#import "UIColor+MBAdditions.h"

@interface OverlayViewController ()

@property (weak, nonatomic) IBOutlet UIView *containerView;
@property (weak, nonatomic) IBOutlet UILabel *instuctionLabel;
@property (weak, nonatomic) IBOutlet UIImageView *starbucksCardImageView;

@property (weak, nonatomic) IBOutlet UIView *viewFinderView;

@property (weak, nonatomic) IBOutlet UIButton *closeButton;
@property (weak, nonatomic) IBOutlet UIButton *torchButton;

@property (strong, nonatomic) UIImage *torchOffImage;
@property (strong, nonatomic) UIImage *torchOnImage;

@property (strong, nonatomic) ShadowView *shadowView;

@property (assign, nonatomic, getter=isTorchOn) BOOL torchOn;

@end

/* Graphical attributes */

// Viewfinder corner radius
static CGFloat const kViewFinderCornerRadius = 10.f;

// Viewfinder border width
static CGFloat const kViewFinderBorderWIdth = 3.f;

// Container view corner radius
static CGFloat const kContainerViewCornerRadius = 12.f;

/* String constants */

// Storyboard name
static NSString *const kStoryboardName = @"Main";

// ViewController identifier
static NSString *const kViewControllerIdentifier = @"overlay";

// Torch off image identifier
static NSString *const kTorchOffImage = @"icSunOff";

// Torch on image identifier
static NSString *const kTorchOnImage = @"icSunOn";

// Card canning instructions
static NSString *const kCardScanInstructions = @"Position the device above Starbucks card and wait for scanning.";

@implementation OverlayViewController

#pragma mark - Public

+ (instancetype)viewControllerFromStoryboard {
    return [[UIStoryboard storyboardWithName:kStoryboardName bundle:nil] instantiateViewControllerWithIdentifier:kViewControllerIdentifier];
}

#pragma mark - Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];

    self.instuctionLabel.text = kCardScanInstructions;

    self.torchOnImage = [UIImage imageNamed:kTorchOnImage];
    self.torchOffImage = [UIImage imageNamed:kTorchOffImage];

    PPModernOcrResultOverlaySubview *dotsOverlaySubview = [[PPModernOcrResultOverlaySubview alloc] initWithFrame:self.view.bounds];
    [self registerOverlaySubview:dotsOverlaySubview];
    [self.view addSubview:dotsOverlaySubview];

    self.shadowView =
        [[ShadowView alloc] initWithFrame:self.view.frame andShadowColor:[UIColor MB_shadowColor] andCornerRadius:kViewFinderCornerRadius];
    [self.view insertSubview:self.shadowView atIndex:0];

    [self.shadowView setTranslatesAutoresizingMaskIntoConstraints:NO];
    [self.shadowView.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor].active = YES;
    [self.shadowView.centerYAnchor constraintEqualToAnchor:self.view.centerYAnchor].active = YES;
    [self.shadowView.widthAnchor constraintEqualToAnchor:self.view.widthAnchor].active = YES;
    [self.shadowView.heightAnchor constraintEqualToAnchor:self.view.heightAnchor].active = YES;

    self.viewFinderView.layer.borderColor = [UIColor MB_emeraldColor].CGColor;
    self.viewFinderView.layer.cornerRadius = kViewFinderCornerRadius;
    self.viewFinderView.layer.borderWidth = kViewFinderBorderWIdth;

    self.containerView.layer.cornerRadius = kContainerViewCornerRadius;
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    [self.shadowView updateViewWithRect:self.viewFinderView.frame];
}

- (BOOL)prefersStatusBarHidden {
    return NO;
}

- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleLightContent;
}

#pragma mark - Custom Accessors

- (void)setTorchOn:(BOOL)torchOn {
    BOOL success = [self.containerViewController overlayViewController:self willSetTorch:torchOn];
    if (success && torchOn) {
        [self.torchButton setImage:self.torchOnImage forState:UIControlStateNormal];
    } else {
        [self.torchButton setImage:self.torchOffImage forState:UIControlStateNormal];
    }
    _torchOn = torchOn;
}

#pragma mark - Actions

- (IBAction)didTapTorchButton:(id)sender {
    self.torchOn = !self.isTorchOn;
}

- (IBAction)didTapCloseButton:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
