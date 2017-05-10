//
//  PPScanResultView.m
//  BlinkOCR
//
//  Created by Jura on 01/03/15.
//  Copyright (c) 2015 PhotoPay. All rights reserved.
//

#import "PPScanResultView.h"

@interface PPScanResultView () <UITextFieldDelegate>

@property(nonatomic, strong) UIView *textContainerView;

@property(nonatomic, strong) UIView *borderView;

@property(nonatomic, assign) CGFloat topMargin;

@property(nonatomic) NSArray *currentConstraints;

@property(nonatomic) BOOL shown;

@end

@implementation PPScanResultView

- (void)animateShowFromViewCenter:(UIView *)startCenter
                          toFrame:(UIView *)bounds
                animationDuration:(NSTimeInterval)animationDuration
                       completion:(void (^)(BOOL finished))completion {

    self.alpha = 1.0f;
    self.hidden = NO;

    for (NSLayoutConstraint *constraint in self.currentConstraints) {
        [self.superview removeConstraint:constraint];
    }

    NSLayoutConstraint *centerXHidden = [NSLayoutConstraint constraintWithItem:self
                                                                     attribute:NSLayoutAttributeCenterX
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:startCenter
                                                                     attribute:NSLayoutAttributeCenterX
                                                                    multiplier:1.0
                                                                      constant:0.0];
    NSLayoutConstraint *centerYHidden = [NSLayoutConstraint constraintWithItem:self
                                                                     attribute:NSLayoutAttributeCenterY
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:startCenter
                                                                     attribute:NSLayoutAttributeCenterY
                                                                    multiplier:1.0
                                                                      constant:0.0];
    NSLayoutConstraint *heightHidden = [NSLayoutConstraint constraintWithItem:self
                                                                    attribute:NSLayoutAttributeHeight
                                                                    relatedBy:NSLayoutRelationEqual
                                                                       toItem:nil
                                                                    attribute:NSLayoutAttributeNotAnAttribute
                                                                   multiplier:1.0
                                                                     constant:0.0];
    NSLayoutConstraint *widthHidden = [NSLayoutConstraint constraintWithItem:self
                                                                   attribute:NSLayoutAttributeWidth
                                                                   relatedBy:NSLayoutRelationEqual
                                                                      toItem:nil
                                                                   attribute:NSLayoutAttributeNotAnAttribute
                                                                  multiplier:1.0
                                                                    constant:0.0];
    [self.superview addConstraint:centerXHidden];
    [self.superview addConstraint:centerYHidden];
    [self.superview addConstraint:widthHidden];
    [self.superview addConstraint:heightHidden];
    [self layoutIfNeeded];
    [self.superview removeConstraint:centerXHidden];
    [self.superview removeConstraint:centerYHidden];
    [self.superview removeConstraint:widthHidden];
    [self.superview removeConstraint:heightHidden];

    NSLayoutConstraint *centerXShown = [NSLayoutConstraint constraintWithItem:self
                                                                    attribute:NSLayoutAttributeCenterX
                                                                    relatedBy:NSLayoutRelationEqual
                                                                       toItem:bounds
                                                                    attribute:NSLayoutAttributeCenterX
                                                                   multiplier:1.0
                                                                     constant:0.0];
    NSLayoutConstraint *centerYShown = [NSLayoutConstraint constraintWithItem:self
                                                                    attribute:NSLayoutAttributeCenterY
                                                                    relatedBy:NSLayoutRelationEqual
                                                                       toItem:bounds
                                                                    attribute:NSLayoutAttributeCenterY
                                                                   multiplier:1.0
                                                                     constant:0.0];
    NSLayoutConstraint *heightShown = [NSLayoutConstraint constraintWithItem:self
                                                                   attribute:NSLayoutAttributeHeight
                                                                   relatedBy:NSLayoutRelationEqual
                                                                      toItem:bounds
                                                                   attribute:NSLayoutAttributeHeight
                                                                  multiplier:1.0
                                                                    constant:0.0];
    NSLayoutConstraint *widthShown = [NSLayoutConstraint constraintWithItem:self
                                                                  attribute:NSLayoutAttributeWidth
                                                                  relatedBy:NSLayoutRelationEqual
                                                                     toItem:bounds
                                                                  attribute:NSLayoutAttributeWidth
                                                                 multiplier:1.0
                                                                   constant:0.0];
    self.currentConstraints = @[ centerXShown, centerYShown, heightShown, widthShown ];

    for (NSLayoutConstraint *constraint in self.currentConstraints) {
        [self.superview addConstraint:constraint];
    }

    [UIView animateWithDuration:animationDuration
                          delay:0.0
                        options:UIViewAnimationOptionCurveEaseInOut
                     animations:^{
                       [self layoutIfNeeded];
                     }
                     completion:completion];
    self.shown = YES;
}

- (void)animateHideToViewCenter:(UIView *)endCenter animationDuration:(NSTimeInterval)animationDuration completion:(void (^)(BOOL finished))completion {
    [self layoutIfNeeded];
    for (NSLayoutConstraint *constraint in self.currentConstraints) {
        [self.superview removeConstraint:constraint];
    }
    NSLayoutConstraint *centerX = [NSLayoutConstraint constraintWithItem:self
                                                               attribute:NSLayoutAttributeCenterX
                                                               relatedBy:NSLayoutRelationEqual
                                                                  toItem:endCenter
                                                               attribute:NSLayoutAttributeCenterX
                                                              multiplier:1.0
                                                                constant:0.0];
    NSLayoutConstraint *centerY = [NSLayoutConstraint constraintWithItem:self
                                                               attribute:NSLayoutAttributeCenterY
                                                               relatedBy:NSLayoutRelationEqual
                                                                  toItem:endCenter
                                                               attribute:NSLayoutAttributeCenterY
                                                              multiplier:1.0
                                                                constant:0.0];
    NSLayoutConstraint *heightHidden = [NSLayoutConstraint constraintWithItem:self
                                                                    attribute:NSLayoutAttributeHeight
                                                                    relatedBy:NSLayoutRelationEqual
                                                                       toItem:nil
                                                                    attribute:NSLayoutAttributeNotAnAttribute
                                                                   multiplier:1.0
                                                                     constant:0.0];
    NSLayoutConstraint *widthHidden = [NSLayoutConstraint constraintWithItem:self
                                                                   attribute:NSLayoutAttributeWidth
                                                                   relatedBy:NSLayoutRelationEqual
                                                                      toItem:nil
                                                                   attribute:NSLayoutAttributeNotAnAttribute
                                                                  multiplier:1.0
                                                                    constant:0.0];
    self.currentConstraints = @[ centerX, centerY, heightHidden, widthHidden ];
    for (NSLayoutConstraint *constraint in self.currentConstraints) {
        [self.superview addConstraint:constraint];
    }

    [UIView animateWithDuration:animationDuration
        delay:0.0
        options:UIViewAnimationOptionCurveEaseIn
        animations:^{
          [self layoutIfNeeded];
        }
        completion:^(BOOL finished) {
          self.hidden = YES;
          self.alpha = 0.0f;
          if (completion) {
              completion(finished);
          }
        }];
    self.shown = NO;
}

#pragma mark - TextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return NO;
}

+ (instancetype)allocFromNibName:(NSString *)nibName {

    PPScanResultView *resultView = [[[NSBundle mainBundle] loadNibNamed:nibName owner:self options:nil] lastObject];

    [resultView setTranslatesAutoresizingMaskIntoConstraints:NO];
    resultView.textField.delegate = resultView;
    resultView.textField.adjustsFontSizeToFitWidth = YES;
    resultView.labelResultTitle.text = @"";

    return resultView;
}

@end
