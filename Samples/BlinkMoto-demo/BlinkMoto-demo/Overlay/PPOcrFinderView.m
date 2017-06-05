//
//  PPOcrFinderView.m
//  BlinkMoto-demo
//
//  Created by Jura Skrlec on 02/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "PPOcrFinderView+Private.h"

@interface PPOcrFinderView()

@property (nonatomic) NSLayoutConstraint *messageConstraintTop;
@property (nonatomic) NSLayoutConstraint *resultMessageConstraintBottom;

@property (nonatomic) NSLayoutConstraint *messageConstraintWidth;
@property (nonatomic) NSLayoutConstraint *resultMessageConstraintWidth;


@property (nonatomic) UIImageView *viewfinderCornerTopLeft;
@property (nonatomic) UIImageView *viewfinderCornerTopRight;
@property (nonatomic) UIImageView *viewfinderCornerBottomLeft;
@property (nonatomic) UIImageView *viewfinderCornerBottomRight;

@property (nonatomic) UIView *shadeTop;
@property (nonatomic) UIView *shadeBottom;
@property (nonatomic) UIView *shadeLeft;
@property (nonatomic) UIView *shadeRight;

@property (nonatomic) CGFloat originalViewfinderWidth;
@property (nonatomic) CGFloat originalViewfinderHeight;

@property (nonatomic) CGFloat motionEstimationRegionWidth;
@property (nonatomic) CGFloat motionEstimationRegionHeight;

@property (nonatomic) NSLayoutConstraint *shadeTopConstraintTop;
@property (nonatomic) NSLayoutConstraint *shadeTopConstraintLeft;
@property (nonatomic) NSLayoutConstraint *shadeTopConstraintRight;

@property (nonatomic) NSLayoutConstraint *shadeBottomConstraintBottom;
@property (nonatomic) NSLayoutConstraint *shadeBottomConstraintLeft;
@property (nonatomic) NSLayoutConstraint *shadeBottomConstraintRight;

@property (nonatomic) NSLayoutConstraint *shadeLeftConstraintLeft;
@property (nonatomic) NSLayoutConstraint *shadeRightConstraintRight;
@end

static const CGFloat kShadeAlpha = 0.4f;
static const CGFloat kViewfinderMargin = 0.0f;
static const CGFloat kMessageMargin = 15.0;

@implementation PPOcrFinderView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self _init];
    }
    return self;
}

- (void)_initOcrFinderView {
    
    _viewfinder = [[UIView alloc] init];
    
    _viewfinder.translatesAutoresizingMaskIntoConstraints = NO;
    
    _viewfinder.layer.borderColor = [UIColor whiteColor].CGColor;
    
    _viewfinder.layer.borderWidth = 1.0f;
    
    [self addSubview:_viewfinder];
    
    _viewfinderHorizontalAlignmentConstraint = [NSLayoutConstraint constraintWithItem:_viewfinder
                                                                            attribute:NSLayoutAttributeCenterX
                                                                            relatedBy:NSLayoutRelationEqual
                                                                               toItem:self
                                                                            attribute:NSLayoutAttributeCenterX
                                                                           multiplier:1
                                                                             constant:0];
    
    _viewfinderVerticalAlignmentConstraint = [NSLayoutConstraint constraintWithItem:_viewfinder
                                                                          attribute:NSLayoutAttributeCenterY
                                                                          relatedBy:NSLayoutRelationEqual
                                                                             toItem:self
                                                                          attribute:NSLayoutAttributeCenterY
                                                                         multiplier:1
                                                                           constant:0];
    
    _viewfinderWidthConstraint = [NSLayoutConstraint constraintWithItem:_viewfinder
                                                              attribute:NSLayoutAttributeWidth
                                                              relatedBy:NSLayoutRelationEqual
                                                                 toItem:nil
                                                              attribute:NSLayoutAttributeNotAnAttribute
                                                             multiplier:1
                                                               constant:(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) ? 600.0f : 300.0f];
    
    _viewfinderHeightConstraint = [NSLayoutConstraint constraintWithItem:_viewfinder
                                                               attribute:NSLayoutAttributeHeight
                                                               relatedBy:NSLayoutRelationEqual
                                                                  toItem:nil
                                                               attribute:NSLayoutAttributeNotAnAttribute
                                                              multiplier:1
                                                                constant:80 /*these values are always overriden in initViewfinder*/];
    
    [NSLayoutConstraint activateConstraints:@[_viewfinderHorizontalAlignmentConstraint,
                                              _viewfinderVerticalAlignmentConstraint,
                                              _viewfinderWidthConstraint,
                                              _viewfinderHeightConstraint]];
}

- (void)_initShades:(UIColor *)shadeColor {
    
    _shadeTop = [[UIView alloc] init];
    
    _shadeTop.translatesAutoresizingMaskIntoConstraints = NO;
    
    _shadeTop.backgroundColor = shadeColor;
    
    [self addSubview:_shadeTop];
    
    [NSLayoutConstraint activateConstraints:@[
                                              _shadeTopConstraintTop = [NSLayoutConstraint constraintWithItem:_shadeTop
                                                                                                    attribute:NSLayoutAttributeTop
                                                                                                    relatedBy:NSLayoutRelationEqual
                                                                                                       toItem:self
                                                                                                    attribute:NSLayoutAttributeTop
                                                                                                   multiplier:1
                                                                                                     constant:0],
                                              
                                              _shadeTopConstraintLeft = [NSLayoutConstraint constraintWithItem:_shadeTop
                                                                                                     attribute:NSLayoutAttributeLeft
                                                                                                     relatedBy:NSLayoutRelationEqual
                                                                                                        toItem:self
                                                                                                     attribute:NSLayoutAttributeLeft
                                                                                                    multiplier:1
                                                                                                      constant:0],
                                              
                                              _shadeTopConstraintRight = [NSLayoutConstraint constraintWithItem:_shadeTop
                                                                                                      attribute:NSLayoutAttributeRight
                                                                                                      relatedBy:NSLayoutRelationEqual
                                                                                                         toItem:self
                                                                                                      attribute:NSLayoutAttributeRight
                                                                                                     multiplier:1
                                                                                                       constant:0],
                                              
                                              [NSLayoutConstraint constraintWithItem:_shadeTop
                                                                           attribute:NSLayoutAttributeBottom
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:_viewfinder
                                                                           attribute:NSLayoutAttributeTop
                                                                          multiplier:1
                                                                            constant:-kViewfinderMargin]
                                              ]];
    
    _shadeBottom = [[UIView alloc] init];
    
    _shadeBottom.translatesAutoresizingMaskIntoConstraints = NO;
    
    _shadeBottom.backgroundColor = shadeColor;
    
    [self addSubview:_shadeBottom];
    
    [NSLayoutConstraint activateConstraints:@[
                                              [NSLayoutConstraint constraintWithItem:_shadeBottom
                                                                           attribute:NSLayoutAttributeTop
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:_viewfinder
                                                                           attribute:NSLayoutAttributeBottom
                                                                          multiplier:1
                                                                            constant:kViewfinderMargin],
                                              
                                              _shadeBottomConstraintLeft = [NSLayoutConstraint constraintWithItem:_shadeBottom
                                                                                                        attribute:NSLayoutAttributeLeft
                                                                                                        relatedBy:NSLayoutRelationEqual
                                                                                                           toItem:self
                                                                                                        attribute:NSLayoutAttributeLeft
                                                                                                       multiplier:1
                                                                                                         constant:0],
                                              
                                              _shadeBottomConstraintRight = [NSLayoutConstraint constraintWithItem:_shadeBottom
                                                                                                         attribute:NSLayoutAttributeRight
                                                                                                         relatedBy:NSLayoutRelationEqual
                                                                                                            toItem:self
                                                                                                         attribute:NSLayoutAttributeRight
                                                                                                        multiplier:1
                                                                                                          constant:0],
                                              
                                              _shadeBottomConstraintBottom = [NSLayoutConstraint constraintWithItem:_shadeBottom
                                                                                                          attribute:NSLayoutAttributeBottom
                                                                                                          relatedBy:NSLayoutRelationEqual
                                                                                                             toItem:self
                                                                                                          attribute:NSLayoutAttributeBottom
                                                                                                         multiplier:1
                                                                                                           constant:0]
                                              ]];
    
    _shadeLeft = [[UIView alloc] init];
    
    _shadeLeft.translatesAutoresizingMaskIntoConstraints = NO;
    
    _shadeLeft.backgroundColor = shadeColor;
    
    [self addSubview:_shadeLeft];
    
    [NSLayoutConstraint activateConstraints:@[
                                              [NSLayoutConstraint constraintWithItem:_shadeLeft
                                                                           attribute:NSLayoutAttributeTop
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:_shadeTop
                                                                           attribute:NSLayoutAttributeBottom
                                                                          multiplier:1
                                                                            constant:0],
                                              
                                              _shadeLeftConstraintLeft = [NSLayoutConstraint constraintWithItem:_shadeLeft
                                                                                                      attribute:NSLayoutAttributeLeft
                                                                                                      relatedBy:NSLayoutRelationEqual
                                                                                                         toItem:self
                                                                                                      attribute:NSLayoutAttributeLeft
                                                                                                     multiplier:1
                                                                                                       constant:0],
                                              
                                              [NSLayoutConstraint constraintWithItem:_shadeLeft
                                                                           attribute:NSLayoutAttributeRight
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:_viewfinder
                                                                           attribute:NSLayoutAttributeLeft
                                                                          multiplier:1
                                                                            constant:-kViewfinderMargin],
                                              
                                              [NSLayoutConstraint constraintWithItem:_shadeLeft
                                                                           attribute:NSLayoutAttributeBottom
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:_shadeBottom
                                                                           attribute:NSLayoutAttributeTop
                                                                          multiplier:1
                                                                            constant:0]
                                              ]];
    
    _shadeRight = [[UIView alloc] init];
    
    _shadeRight.translatesAutoresizingMaskIntoConstraints = NO;
    
    _shadeRight.backgroundColor = shadeColor;
    
    [self addSubview:_shadeRight];
    
    [NSLayoutConstraint activateConstraints:@[
                                              [NSLayoutConstraint constraintWithItem:_shadeRight
                                                                           attribute:NSLayoutAttributeTop
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:_shadeTop
                                                                           attribute:NSLayoutAttributeBottom
                                                                          multiplier:1
                                                                            constant:0],
                                              
                                              [NSLayoutConstraint constraintWithItem:_shadeRight
                                                                           attribute:NSLayoutAttributeLeft
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:_viewfinder
                                                                           attribute:NSLayoutAttributeRight
                                                                          multiplier:1
                                                                            constant:kViewfinderMargin],
                                              
                                              _shadeRightConstraintRight = [NSLayoutConstraint constraintWithItem:_shadeRight
                                                                                                        attribute:NSLayoutAttributeRight
                                                                                                        relatedBy:NSLayoutRelationEqual
                                                                                                           toItem:self
                                                                                                        attribute:NSLayoutAttributeRight
                                                                                                       multiplier:1
                                                                                                         constant:0],
                                              
                                              [NSLayoutConstraint constraintWithItem:_shadeRight
                                                                           attribute:NSLayoutAttributeBottom
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:_shadeBottom
                                                                           attribute:NSLayoutAttributeTop
                                                                          multiplier:1
                                                                            constant:0],
                                              ]];
}

- (void)_initMessage {
    _message = [[UILabel alloc] init];
    
    _message.numberOfLines = 0;
    
    _message.translatesAutoresizingMaskIntoConstraints = NO;
    
    _message.alpha = 1;
    
    _message.adjustsFontSizeToFitWidth = YES;
    
    _message.textColor = [UIColor whiteColor];
    _message.textAlignment = NSTextAlignmentCenter;
    _message.text = @"Proba";
    
    _message.layer.shadowColor = [[UIColor blackColor] CGColor];
    _message.layer.shadowOpacity = 0.3;
    _message.layer.shadowRadius = 1;
    _message.layer.shadowOffset = CGSizeZero;
    
    [self addSubview:_message];
    
    [NSLayoutConstraint activateConstraints:@[
                                              [NSLayoutConstraint constraintWithItem:_message
                                                                           attribute:NSLayoutAttributeBottom
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:_viewfinder
                                                                           attribute:NSLayoutAttributeTop
                                                                          multiplier:1
                                                                            constant:-kMessageMargin],
                                              [NSLayoutConstraint constraintWithItem:_message
                                                                           attribute:NSLayoutAttributeCenterX
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:self
                                                                           attribute:NSLayoutAttributeCenterX
                                                                          multiplier:1
                                                                            constant:0],
                                              _messageConstraintWidth =[NSLayoutConstraint constraintWithItem:_message
                                                                           attribute:NSLayoutAttributeWidth
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:self
                                                                           attribute:NSLayoutAttributeWidth
                                                                          multiplier:1
                                                                            constant:_viewfinderWidthConstraint.constant],
                                              _messageConstraintTop = [NSLayoutConstraint constraintWithItem:_message
                                                                                                   attribute:NSLayoutAttributeTop
                                                                                                   relatedBy:NSLayoutRelationGreaterThanOrEqual
                                                                                                      toItem:self
                                                                                                   attribute:NSLayoutAttributeTop
                                                                                                  multiplier:1
                                                                                                    constant:70], // used to avoid overlap with control for switching between camera and calculator
                                              
                                              ]];
}

- (void)_initResultMessage {
    _resultMessage = [[UILabel alloc] init];
    
    _resultMessage.numberOfLines = 0;
    
    _resultMessage.translatesAutoresizingMaskIntoConstraints = NO;
    
    _resultMessage.alpha = 1;
    
    _resultMessage.adjustsFontSizeToFitWidth = YES;
    
    _resultMessage.textColor = [UIColor whiteColor];
    _resultMessage.textAlignment = NSTextAlignmentCenter;
    _resultMessage.text = @"Proba";
    
    _resultMessage.layer.shadowColor = [[UIColor blackColor] CGColor];
    _resultMessage.layer.shadowOpacity = 0.3;
    _resultMessage.layer.shadowRadius = 1;
    _resultMessage.layer.shadowOffset = CGSizeZero;
    
    [self addSubview:_resultMessage];
    
    [NSLayoutConstraint activateConstraints:@[
                                              [NSLayoutConstraint constraintWithItem:_resultMessage
                                                                           attribute:NSLayoutAttributeTop
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:_viewfinder
                                                                           attribute:NSLayoutAttributeBottom
                                                                          multiplier:1
                                                                            constant:kMessageMargin],
                                              [NSLayoutConstraint constraintWithItem:_resultMessage
                                                                           attribute:NSLayoutAttributeCenterX
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:self
                                                                           attribute:NSLayoutAttributeCenterX
                                                                          multiplier:1
                                                                            constant:0],
                                              _resultMessageConstraintWidth =[NSLayoutConstraint constraintWithItem:_resultMessage
                                                                           attribute:NSLayoutAttributeWidth
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:self
                                                                           attribute:NSLayoutAttributeWidth
                                                                          multiplier:1
                                                                            constant:_viewfinderWidthConstraint.constant],
                                              _resultMessageConstraintBottom = [NSLayoutConstraint constraintWithItem:_message
                                                                                                   attribute:NSLayoutAttributeBottom
                                                                                                   relatedBy:NSLayoutRelationGreaterThanOrEqual
                                                                                                      toItem:self
                                                                                                   attribute:NSLayoutAttributeBottom
                                                                                                  multiplier:1
                                                                                                    constant:70],
                                              
                                              ]];
}


- (void)_init {
    
    _scanningOrientation = UIInterfaceOrientationPortrait;
    
    [self _initOcrFinderView];
    
    UIColor *shadeColor = [UIColor colorWithWhite:0 alpha:kShadeAlpha];
    
    [self _initShades:shadeColor];
    
    [self _initMessage];
    
    [self _initResultMessage];

}

- (void)initViewfinderForPortrait {
    
    self.viewfinderWidthConstraint.constant = self.bounds.size.width - 50;
    self.viewfinderHeightConstraint.constant = 80;
    
    self.motionEstimationRegionWidth = self.viewfinderWidthConstraint.constant + 25;
    self.motionEstimationRegionHeight = self.viewfinderHeightConstraint.constant + 50;
    
    self.viewfinderVerticalAlignmentConstraint.constant = 0;
    self.viewfinderHorizontalAlignmentConstraint.constant = 0;
    
    // Adjust vertical positioning on small screen devices
    if (self.bounds.size.height < 500) { // small screen iphone 4/4s
        self.viewfinderVerticalAlignmentConstraint.constant += 20;
    }
    
    // Override width to fixed size when appropriate
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        self.viewfinderWidthConstraint.constant = 600;
        self.motionEstimationRegionWidth = self.viewfinderWidthConstraint.constant + 230;
        self.motionEstimationRegionHeight = self.viewfinderHeightConstraint.constant + 160;
    }
    
    self.messageConstraintTop.constant = 70; // menu on top of screen
    self.messageConstraintWidth.constant = self.viewfinderWidthConstraint.constant;
    self.resultMessageConstraintWidth.constant = self.viewfinderWidthConstraint.constant;

}

- (void)initViewfinderForLandscape {
    self.viewfinderWidthConstraint.constant = self.bounds.size.width * 0.9;
    self.viewfinderHeightConstraint.constant = self.bounds.size.height * 0.35;
    
    self.viewfinderHorizontalAlignmentConstraint.constant = -self.bounds.size.width / 2 * (self.viewfinderHorizontalAlignmentConstraint.multiplier - 1);
    
    self.viewfinderVerticalAlignmentConstraint.constant = 0;
    
    self.motionEstimationRegionWidth = 2 * self.viewfinderWidthConstraint.constant / 3;
    
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        self.motionEstimationRegionHeight = self.viewfinderHeightConstraint.constant + 50;
    }
    
    self.messageConstraintTop.constant = 0; // we hide menu in landscape
    self.messageConstraintWidth.constant = self.viewfinderWidthConstraint.constant;
    self.resultMessageConstraintWidth.constant = self.viewfinderWidthConstraint.constant;
}

- (void)initViewfinder {
    
    if (self.originalViewfinderWidth == 0 && self.originalViewfinderHeight == 0) {
        
        [self initViewfinderForPortrait];
        
        [self layoutIfNeeded];
        
        // Initial viewfinder region sync
        [self.delegate viewfinderViewUpdatedScanningRegion:self];
        
        self.originalViewfinderWidth = self.viewfinderWidthConstraint.constant;
        self.originalViewfinderHeight = self.viewfinderHeightConstraint.constant;
        
        self.viewfinderWidthConstraint.constant = self.bounds.size.width * 0.9;
        self.viewfinderHeightConstraint.constant = self.bounds.size.height * 0.5;
        
        self.shadeTop.alpha = 0;
        self.shadeLeft.alpha = 0;
        self.shadeRight.alpha = 0;
        self.shadeBottom.alpha = 0;
        
        self.viewfinder.alpha = 0;
        
        [self layoutIfNeeded];
    }
}

- (void)setScanningOrientation:(UIInterfaceOrientation)scanningOrientation animated:(BOOL)animated {
    
    if (self.scanningOrientation == scanningOrientation) {
        return;
    }
    
    const CGFloat offset = (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) ? [UIScreen mainScreen].bounds.size.height : [UIScreen mainScreen].bounds.size.height/2;  // TODO Better algorithm to determine minimum offset per shade that prevents transition artefacts
    
    _shadeTopConstraintTop.constant = -offset;
    _shadeTopConstraintLeft.constant = -offset;
    _shadeTopConstraintRight.constant = offset;
    
    _shadeBottomConstraintBottom.constant = offset;
    _shadeBottomConstraintLeft.constant = -offset;
    _shadeBottomConstraintRight.constant = offset;
    
    _shadeLeftConstraintLeft.constant = -offset;
    _shadeRightConstraintRight.constant = offset;
    
    [self layoutIfNeeded];
    
    [UIView animateWithDuration:animated ? 0.3 : 0 animations:^{
        if (UIInterfaceOrientationIsLandscape(scanningOrientation)) {
            
            if (!UIInterfaceOrientationIsLandscape(self.scanningOrientation)) {
                self.bounds = CGRectMake(self.bounds.origin.y, self.bounds.origin.x, self.bounds.size.height, self.bounds.size.width);
                
                [self initViewfinderForLandscape];
            }
            
            if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
                self.transform = CGAffineTransformMakeRotation(scanningOrientation == UIInterfaceOrientationLandscapeRight ? -2*M_PI : 2*M_PI);
            }
            else {
                self.transform = CGAffineTransformMakeRotation(scanningOrientation == UIInterfaceOrientationLandscapeRight ? -M_PI/2 : M_PI/2);
            }
            
            [self layoutIfNeeded];
        } else if (UIInterfaceOrientationIsPortrait(scanningOrientation)) {
            if (!UIInterfaceOrientationIsPortrait(self.scanningOrientation)) {
                self.transform = CGAffineTransformIdentity;
                
                self.bounds = CGRectMake(self.bounds.origin.y, self.bounds.origin.x, self.bounds.size.height, self.bounds.size.width);
                
                [self initViewfinderForPortrait];
                
                [self layoutIfNeeded];
            }
        }
    } completion:^(BOOL finished) {
        _shadeTopConstraintTop.constant = 0;
        _shadeTopConstraintLeft.constant = 0;
        _shadeTopConstraintRight.constant = 0;
        
        _shadeBottomConstraintBottom.constant = 0;
        _shadeBottomConstraintLeft.constant = 0;
        _shadeBottomConstraintRight.constant = 0;
        
        _shadeLeftConstraintLeft.constant = 0;
        _shadeRightConstraintRight.constant = 0;
        
        [self.delegate viewfinderViewUpdatedScanningRegion:self];
    }];
    
    _scanningOrientation = scanningOrientation;
}


- (CGRect)transformRegionIfNecessary:(CGRect)region {
    if (self.scanningOrientation == UIInterfaceOrientationLandscapeLeft) {
        region = CGRectMake(1 - region.origin.y - region.size.height, region.origin.x, region.size.height, region.size.width);
    } else if (self.scanningOrientation == UIInterfaceOrientationLandscapeRight) {
        region = CGRectMake(region.origin.y, region.origin.x, region.size.height, region.size.width);
    }
    
    return region;
}

- (CGRect)scanningRegion {
    CGRect scanningRegion = CGRectMake(self.viewfinder.frame.origin.x / self.bounds.size.width,
                                       self.viewfinder.frame.origin.y / self.bounds.size.height,
                                       self.viewfinder.frame.size.width / self.bounds.size.width,
                                       self.viewfinder.frame.size.height / self.bounds.size.height);
    
    // We need to ensure that the region is always in the image coordinate space
    // Processing code uses the scanningOrientation to rectify the roi-ed image if needed
    return [self transformRegionIfNecessary:scanningRegion];
}

- (CGRect)motionEstimationRegion {
    CGRect motionEstimationFrame = [self motionEstimationFrame];
    
    CGRect region = CGRectMake(motionEstimationFrame.origin.x / self.bounds.size.width,
                               motionEstimationFrame.origin.y / self.bounds.size.height,
                               motionEstimationFrame.size.width / self.bounds.size.width,
                               motionEstimationFrame.size.height / self.bounds.size.height);
    
    // We need to ensure that the region is always in the image coordinate space
    // Processing code uses the scanningOrientation to rectify the roi-ed image if needed
    return [self transformRegionIfNecessary:region];
}

- (CGRect)motionEstimationFrame {
    
    CGFloat const x = self.viewfinder.center.x - self.motionEstimationRegionWidth / 2;
    CGFloat const y = self.viewfinder.center.y - self.motionEstimationRegionHeight / 2;
    
    return CGRectMake(x, y, self.motionEstimationRegionWidth, self.motionEstimationRegionHeight);
}

@end
