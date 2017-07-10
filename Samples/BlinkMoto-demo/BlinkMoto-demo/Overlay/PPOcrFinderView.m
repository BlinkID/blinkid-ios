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

@property (nonatomic) CGFloat originalViewfinderWidth;
@property (nonatomic) CGFloat originalViewfinderHeight;

@property (nonatomic) NSLayoutConstraint *shadeTopConstraintTop;
@property (nonatomic) NSLayoutConstraint *shadeTopConstraintLeft;
@property (nonatomic) NSLayoutConstraint *shadeTopConstraintRight;

@property (nonatomic) NSLayoutConstraint *shadeBottomConstraintBottom;
@property (nonatomic) NSLayoutConstraint *shadeBottomConstraintLeft;
@property (nonatomic) NSLayoutConstraint *shadeBottomConstraintRight;

@property (nonatomic) NSLayoutConstraint *shadeLeftConstraintLeft;
@property (nonatomic) NSLayoutConstraint *shadeRightConstraintRight;

@property (nonatomic, readonly) NSLayoutConstraint *resultImageViewHorizontalAlignmentConstraint;
@property (nonatomic, readonly) NSLayoutConstraint *resultImageVerticalAlignmentConstraint;
@property (nonatomic, readonly) NSLayoutConstraint *resultImageViewWidthConstraint;
@property (nonatomic, readonly) NSLayoutConstraint *resultImageViewHeightConstraint;

@end

static const CGFloat kShadeAlpha = 0.7f;
static const CGFloat kViewfinderMargin = 0.0f;
static const CGFloat kMessageMargin = 15.0;
static const CGFloat kButtonAcceptMargin = 16.0;

static NSString * const kTitleText = @"title_text";
static NSString * const kCancelText = @"cancel_text";
static NSString * const kRepeatText = @"repeat_text";
static NSString * const kAcceptText = @"accept_text";

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
    
    _message.translatesAutoresizingMaskIntoConstraints = NO;
    
    _message.alpha = 1;
    
    _message.textColor = [UIColor whiteColor];
    _message.textAlignment = NSTextAlignmentCenter;
    
    CGFloat textSize;
    
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        textSize = 20.0f;
    }
    else {
        textSize = 14.0f;
    }
    
    [_message setFont:[UIFont fontWithName:@"Helvetica" size:textSize]];
    _message.lineBreakMode = NSLineBreakByWordWrapping;
    _message.numberOfLines = 0;
        
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
                                              _messageConstraintWidth = [NSLayoutConstraint constraintWithItem:_message
                                                                           attribute:NSLayoutAttributeWidth
                                                                           relatedBy:NSLayoutRelationEqual
                                                                              toItem:_viewfinder
                                                                           attribute:NSLayoutAttributeWidth
                                                                          multiplier:1
                                                                            constant:0]
                                              
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
    
    CGFloat textSize;
    
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        textSize = 28.0f;
    }
    else {
        textSize = 22.0f;
    }
    
    [_resultMessage setFont:[UIFont fontWithName:@"Helvetica" size:textSize]];
    
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
                                                                              toItem:_viewfinder
                                                                           attribute:NSLayoutAttributeWidth
                                                                          multiplier:1
                                                                            constant:0],
                                              _resultMessageConstraintBottom = [NSLayoutConstraint constraintWithItem:_message
                                                                                                   attribute:NSLayoutAttributeBottom
                                                                                                   relatedBy:NSLayoutRelationGreaterThanOrEqual
                                                                                                      toItem:self
                                                                                                   attribute:NSLayoutAttributeBottom
                                                                                                  multiplier:1
                                                                                                    constant:70],
                                              
                                              ]];
}

- (void)_initButtons {
    
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    CGFloat screenHeight = screenRect.size.height;
    CGFloat screenWidth = screenRect.size.width;
    CGFloat wantedWidthForAllButtonContainer;
    if (screenHeight > screenWidth) { //Portrait mode
        wantedWidthForAllButtonContainer = screenWidth / 2.0f;
    }
    else { // Landscape mode
        wantedWidthForAllButtonContainer = screenHeight / 2.0f;
    }
    CGFloat wantedButtonContainerWidth = wantedWidthForAllButtonContainer + wantedWidthForAllButtonContainer/2.0f;
    CGFloat wantedButtonWidth = wantedButtonContainerWidth / 3.0f;
    
    {
        _acceptButton = [[UIButton alloc] init];
        
        _acceptButton.backgroundColor = [UIColor colorWithRed:22.0f/256.0f green:145.0f/256.0f blue:192.0f/256.0f alpha:1.0f];
        _acceptButton.translatesAutoresizingMaskIntoConstraints = NO;
        
        [_acceptButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [_acceptButton.titleLabel setFont:[UIFont fontWithName:@"Helvetica" size:12.0f]];
        [_acceptButton addTarget:self action:@selector(acceptButtonDidTap:) forControlEvents:UIControlEventTouchUpInside];
        
        [self addSubview:_acceptButton];
        
        [NSLayoutConstraint activateConstraints:@[
                                                  [NSLayoutConstraint constraintWithItem:_acceptButton
                                                                               attribute:NSLayoutAttributeBottom
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:self
                                                                               attribute:NSLayoutAttributeBottom
                                                                              multiplier:1
                                                                                constant:-kButtonAcceptMargin],
                                                  [NSLayoutConstraint constraintWithItem:_acceptButton
                                                                               attribute:NSLayoutAttributeRight
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:self
                                                                               attribute:NSLayoutAttributeRight
                                                                              multiplier:1
                                                                                constant:-kButtonAcceptMargin],
                                                  [NSLayoutConstraint constraintWithItem:_acceptButton
                                                                               attribute:NSLayoutAttributeWidth
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:nil
                                                                               attribute:NSLayoutAttributeNotAnAttribute
                                                                              multiplier:1
                                                                                constant:wantedButtonWidth],
                                                  [NSLayoutConstraint constraintWithItem:_acceptButton
                                                                               attribute:NSLayoutAttributeHeight
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:nil
                                                                               attribute:NSLayoutAttributeNotAnAttribute
                                                                              multiplier:1
                                                                                constant:40.0f],
                                                  
                                                  ]];
    }
    
    {
        _repeatButton = [[UIButton alloc] init];
        
        _repeatButton.backgroundColor = [UIColor lightGrayColor];
        _repeatButton.translatesAutoresizingMaskIntoConstraints = NO;
        
        _repeatButton.enabled = NO;
        
        [_repeatButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_repeatButton setTitleColor:[UIColor grayColor] forState:UIControlStateDisabled];
        [_repeatButton.titleLabel setFont:[UIFont fontWithName:@"Helvetica" size:12.0f]];
        
        [_repeatButton addTarget:self action:@selector(repeatButtonDidTap:) forControlEvents:UIControlEventTouchUpInside];
        
        [self addSubview:_repeatButton];
        
        [NSLayoutConstraint activateConstraints:@[
                                                  [NSLayoutConstraint constraintWithItem:_repeatButton
                                                                               attribute:NSLayoutAttributeBottom
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:self
                                                                               attribute:NSLayoutAttributeBottom
                                                                              multiplier:1
                                                                                constant:-kButtonAcceptMargin],
                                                  [NSLayoutConstraint constraintWithItem:_repeatButton
                                                                               attribute:NSLayoutAttributeRight
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:_acceptButton
                                                                               attribute:NSLayoutAttributeLeft
                                                                              multiplier:1
                                                                                constant:-8.0f],
                                                  [NSLayoutConstraint constraintWithItem:_repeatButton
                                                                               attribute:NSLayoutAttributeWidth
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:nil
                                                                               attribute:NSLayoutAttributeNotAnAttribute
                                                                              multiplier:1
                                                                                constant:wantedButtonWidth],
                                                  [NSLayoutConstraint constraintWithItem:_repeatButton
                                                                               attribute:NSLayoutAttributeHeight
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:nil
                                                                               attribute:NSLayoutAttributeNotAnAttribute
                                                                              multiplier:1
                                                                                constant:40.0f],
                                                  
                                                  ]];    }
    
    {
        _cancelButton = [[UIButton alloc] init];
        
        _cancelButton.backgroundColor = [UIColor lightGrayColor];
        _cancelButton.translatesAutoresizingMaskIntoConstraints = NO;
        
        [_cancelButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_cancelButton.titleLabel setFont:[UIFont fontWithName:@"Helvetica" size:12.0f]];
        
        [_cancelButton addTarget:self action:@selector(cancelButtonDidTap:) forControlEvents:UIControlEventTouchUpInside];
        
        [self addSubview:_cancelButton];
        
        [NSLayoutConstraint activateConstraints:@[
                                                  [NSLayoutConstraint constraintWithItem:_cancelButton
                                                                               attribute:NSLayoutAttributeBottom
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:self
                                                                               attribute:NSLayoutAttributeBottom
                                                                              multiplier:1
                                                                                constant:-kButtonAcceptMargin],
                                                  [NSLayoutConstraint constraintWithItem:_cancelButton
                                                                               attribute:NSLayoutAttributeRight
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:_repeatButton
                                                                               attribute:NSLayoutAttributeLeft
                                                                              multiplier:1
                                                                                constant:-8.0f],
                                                  [NSLayoutConstraint constraintWithItem:_cancelButton
                                                                               attribute:NSLayoutAttributeWidth
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:nil
                                                                               attribute:NSLayoutAttributeNotAnAttribute
                                                                              multiplier:1
                                                                                constant:wantedButtonWidth],
                                                  [NSLayoutConstraint constraintWithItem:_cancelButton
                                                                               attribute:NSLayoutAttributeHeight
                                                                               relatedBy:NSLayoutRelationEqual
                                                                                  toItem:nil
                                                                               attribute:NSLayoutAttributeNotAnAttribute
                                                                              multiplier:1
                                                                                constant:40.0f],
                                                  
                                                  ]];
    }
}

- (void)_initResultImageView {
    _resultImageView = [[UIImageView alloc] init];
    
    _resultImageView.translatesAutoresizingMaskIntoConstraints = NO;

    _resultImageView.hidden = YES;
    
    _resultImageView.layer.borderColor = [UIColor whiteColor].CGColor;
    
    _resultImageView.layer.borderWidth = 1.0f;
    
    [self addSubview:_resultImageView];
    
    _resultImageViewHorizontalAlignmentConstraint = [NSLayoutConstraint constraintWithItem:_resultImageView
                                                                            attribute:NSLayoutAttributeCenterX
                                                                            relatedBy:NSLayoutRelationEqual
                                                                               toItem:self
                                                                            attribute:NSLayoutAttributeCenterX
                                                                           multiplier:1
                                                                             constant:0];
    
    _resultImageVerticalAlignmentConstraint = [NSLayoutConstraint constraintWithItem:_resultImageView
                                                                          attribute:NSLayoutAttributeCenterY
                                                                          relatedBy:NSLayoutRelationEqual
                                                                             toItem:self
                                                                          attribute:NSLayoutAttributeCenterY
                                                                         multiplier:1
                                                                           constant:0];
    
    _resultImageViewWidthConstraint = [NSLayoutConstraint constraintWithItem:_resultImageView
                                                              attribute:NSLayoutAttributeWidth
                                                              relatedBy:NSLayoutRelationEqual
                                                                 toItem:nil
                                                              attribute:NSLayoutAttributeNotAnAttribute
                                                             multiplier:1
                                                               constant:(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) ? 600.0f : 300.0f];
    
    _resultImageViewHeightConstraint = [NSLayoutConstraint constraintWithItem:_resultImageView
                                                               attribute:NSLayoutAttributeHeight
                                                               relatedBy:NSLayoutRelationEqual
                                                                  toItem:nil
                                                               attribute:NSLayoutAttributeNotAnAttribute
                                                              multiplier:1
                                                                constant:80 /*these values are always overriden in initViewfinder*/];
    
    [NSLayoutConstraint activateConstraints:@[_resultImageViewHorizontalAlignmentConstraint,
                                              _resultImageVerticalAlignmentConstraint,
                                              _resultImageViewWidthConstraint,
                                              _resultImageViewHeightConstraint]];
}


- (void)_init {
    
    _scanningOrientation = UIInterfaceOrientationPortrait;
    
    [self _initOcrFinderView];
    
    UIColor *shadeColor = [UIColor colorWithWhite:0 alpha:kShadeAlpha];
    
    [self _initShades:shadeColor];
    
    [self _initMessage];
    
    [self _initResultMessage];
    
    [self _initButtons];
    
    [self _initResultImageView];

}

- (void)setButtonsSizeToFitText {
    
    [_acceptButton sizeToFit];
    [_cancelButton sizeToFit];
    [_repeatButton sizeToFit];

}

- (void)initViewfinderForPortrait {
    
    self.viewfinderWidthConstraint.constant = self.bounds.size.width - 50;
    self.viewfinderHeightConstraint.constant = 80;
    
    self.resultImageViewWidthConstraint.constant = self.bounds.size.width - 50;
    self.resultImageViewHeightConstraint.constant = 80;
    
    self.viewfinderVerticalAlignmentConstraint.constant = 0;
    self.viewfinderHorizontalAlignmentConstraint.constant = 0;
    
    self.resultImageViewHorizontalAlignmentConstraint.constant = 0;
    self.resultImageVerticalAlignmentConstraint.constant = 0;
    
    // Adjust vertical positioning on small screen devices
    if (self.bounds.size.height < 500) { // small screen iphone 4/4s
        self.viewfinderVerticalAlignmentConstraint.constant += 20;
        self.resultImageVerticalAlignmentConstraint.constant += 20;
    }
    
    // Override width to fixed size when appropriate
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        self.viewfinderWidthConstraint.constant = 600;
        self.resultImageViewWidthConstraint.constant = 600;
    }
    
    [self layoutIfNeeded];
}

- (void)initViewfinderForLandscape {
    self.viewfinderWidthConstraint.constant = (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) ? self.bounds.size.width : self.bounds.size.width * 0.95;
    self.viewfinderHeightConstraint.constant = (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) ?  self.bounds.size.height * 0.1 : self.bounds.size.height * 0.3;
    
    self.resultImageViewWidthConstraint.constant = (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) ? self.bounds.size.width : self.bounds.size.width * 0.95;
    self.resultImageViewHeightConstraint.constant = (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) ?  self.bounds.size.height * 0.1 : self.bounds.size.height * 0.3;
    
    self.viewfinderHorizontalAlignmentConstraint.constant = 0;
    self.viewfinderVerticalAlignmentConstraint.constant = 0;
    
    self.resultImageViewHorizontalAlignmentConstraint.constant = 0;
    self.resultImageVerticalAlignmentConstraint.constant = 0;
    
    [self layoutIfNeeded];
}

- (void)initViewfinder {
    
    if (self.originalViewfinderWidth == 0 && self.originalViewfinderHeight == 0) {
        
        [self initViewfinderForPortrait];
        
        [self layoutIfNeeded];
        
        self.originalViewfinderWidth = self.viewfinderWidthConstraint.constant;
        self.originalViewfinderHeight = self.viewfinderHeightConstraint.constant;
        
        self.viewfinderWidthConstraint.constant = self.bounds.size.width * 0.9;
        self.viewfinderHeightConstraint.constant = self.bounds.size.height * 0.5;
        
        self.resultImageViewWidthConstraint.constant = self.bounds.size.width * 0.9;
        self.resultImageViewHeightConstraint.constant = self.bounds.size.height * 0.5;

        self.shadeTop.alpha = 0;
        self.shadeLeft.alpha = 0;
        self.shadeRight.alpha = 0;
        self.shadeBottom.alpha = 0;
        
        self.viewfinder.alpha = 0;
        
        [self layoutIfNeeded];
    }
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
    CGRect scanningRegion = CGRectMake(self.viewfinder.frame.origin.x / self.frame.size.width,
                                       self.viewfinder.frame.origin.y / self.frame.size.height,
                                       self.viewfinder.frame.size.width / self.frame.size.width,
                                       self.viewfinder.frame.size.height / self.frame.size.height);
    
    // We need to ensure that the region is always in the image coordinate space
    // Processing code uses the scanningOrientation to rectify the roi-ed image if needed
    return [self transformRegionIfNecessary:scanningRegion];
}

- (void)setOcrResultSucces:(BOOL)succes withResult:(NSString *)result andImage:(UIImage *)resultImage {
    
    self.repeatButton.enabled = succes;
    self.resultImageView.hidden = !succes;
    self.resultImageView.image = succes ? resultImage : nil;
    self.resultMessage.text = result;
}

- (NSString *)getScanningResult {
    return self.resultMessage.text;
}

- (void)resetScanningState {
    self.resultImageView.image = nil;
    self.resultImageView.hidden = YES;
    self.repeatButton.enabled = NO;
    self.resultMessage.text = @"";
}

- (void)setTranslation:(NSDictionary *)translation {
    
    self.message.text = [translation objectForKey:kTitleText];
    [self.message sizeToFit];

    [self.acceptButton setTitle:[translation objectForKey:kAcceptText] forState:UIControlStateNormal];
    [self.cancelButton setTitle:[translation objectForKey:kCancelText] forState:UIControlStateNormal];
    [self.repeatButton setTitle:[translation objectForKey:kRepeatText] forState:UIControlStateNormal];
}

#pragma mark - UIButton actions
-(void)repeatButtonDidTap:(UIButton *)sender {
    [self.delegate viewfinderViewDidTapRepeatButton:sender];
}

-(void)cancelButtonDidTap:(UIButton *)sender {
    [self.delegate viewfinderViewDidTapCancelButton:sender];
}

-(void)acceptButtonDidTap:(UIButton *)sender {
    [self.delegate viewfinderViewDidTapAcceptButton:sender];
}


@end
