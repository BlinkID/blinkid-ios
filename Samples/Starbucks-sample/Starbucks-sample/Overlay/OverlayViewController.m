//
//  OverlayViewController.m
//  Starbucks-sample
//
//  Created by Jure Cular on 29/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "OverlayViewController.h"
#import "UIColor+MBAdditions.h"
#import "ShadowView.h"

@interface OverlayViewController ()

@property (weak, nonatomic) IBOutlet UIButton *closeButton;
@property (weak, nonatomic) IBOutlet UIButton *torchButton;

@property (strong, nonatomic) UIImage *torchOffImage;
@property (strong, nonatomic) UIImage *torchOnImage;

@property (nonatomic, getter=isTorchOn) BOOL torchOn;

@property (weak, nonatomic) IBOutlet UIView *containerView;

@property (weak, nonatomic) IBOutlet UILabel *instuctionLabel;
@property (weak, nonatomic) IBOutlet UIImageView *starbucksCardImageView;

@property (weak, nonatomic) IBOutlet UIView *viewFinderView;

@property (strong, nonatomic) ShadowView *shadowView;

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

+ (instancetype)viewControllerFromStoryboard {
    return [[UIStoryboard storyboardWithName:kStoryboardName bundle:nil] instantiateViewControllerWithIdentifier:kViewControllerIdentifier];
}

- (BOOL)prefersStatusBarHidden {
    return NO;
}

- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleLightContent;
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

    self.shadowView = [[ShadowView alloc] initWithFrame:self.view.bounds];
    self.shadowView.shadowColor = [UIColor MB_shadowColor];
    self.shadowView.backgroundColor = [UIColor clearColor];
    self.shadowView.cornerRadius = kViewFinderCornerRadius;

    [self.view insertSubview:self.shadowView atIndex:0];

    self.viewFinderView.layer.borderColor = [UIColor MB_emeraldColor].CGColor;
    self.viewFinderView.layer.cornerRadius = kViewFinderCornerRadius;
    self.viewFinderView.layer.borderWidth = kViewFinderBorderWIdth;

    self.containerView.layer.cornerRadius = kContainerViewCornerRadius;
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    self.shadowView.frame = self.view.bounds;
    [self.shadowView updateOvershadow:self.viewFinderView.frame];
}

#pragma mark - Setters

- (void)setTorchOn:(BOOL)torchOn {
    BOOL success = [self.containerViewController overlayViewController:self willSetTorch:torchOn];
    if (success && torchOn) {
        [self.torchButton setImage:self.torchOnImage forState:UIControlStateNormal];
    } else {
        [self.torchButton setImage:self.torchOffImage forState:UIControlStateNormal];
    }
    _torchOn = torchOn;
}

#pragma mark - IBAction

- (IBAction)didTapTorchButton:(id)sender {
    self.torchOn = !self.isTorchOn;
}

- (IBAction)didTapCloseButton:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
