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

@implementation OverlayViewController

+ (instancetype)viewControllerFromStoryboard {
    return [[UIStoryboard storyboardWithName:@"Main" bundle:nil] instantiateViewControllerWithIdentifier:@"overlay"];
}

#pragma mark - Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];

    self.torchOnImage = [UIImage imageNamed:@"icSunOn"];
    self.torchOffImage = [UIImage imageNamed:@"icSunOff"];

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
    self.scanningRegion = scanningRegionForFrameInBounds(self.viewFinderView.frame, self.view.bounds);
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

- (void)setAllElementsToHidden:(BOOL)hidden {
    self.torchButton.hidden = hidden;
    self.shadowView.hidden = hidden;
    self.viewFinderView.hidden = hidden;
    self.closeButton.hidden = hidden;
    self.containerView.hidden = hidden;
    self.starbucksCardImageView.hidden = hidden;
    self.instuctionLabel.hidden = hidden;
}

#pragma mark - IBAction

- (IBAction)didTapTorchButton:(id)sender {
    self.torchOn = !self.isTorchOn;
}

- (IBAction)didTapCloseButton:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
