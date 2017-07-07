//
//  PPScanningOvershadowView.m
//  PhotoPay-Slovakia
//
//  Created by Luka Zuanovic on 09/11/2016.
//  Copyright © 2016 MicroBlink. All rights reserved.
//

#import "ShadowView.h"

@implementation ShadowView

#pragma mark - Lifecycle

- (instancetype)initWithFrame:(CGRect)frame andShadowColor:(UIColor *)shadowColor andCornerRadius:(CGFloat)cornerRadius {
    self = [super initWithFrame:frame];
    if (self) {
        _shadowColor = shadowColor;
        _cornerRadius = cornerRadius;

        self.opaque = NO;
        self.userInteractionEnabled = NO;
    }
    return self;
}

- (void)drawRect:(CGRect)rect {
    [super drawRect:rect];

    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextClearRect(context, rect);

    UIBezierPath *clipPath = [UIBezierPath bezierPathWithRect:self.bounds];
    UIBezierPath *scanningPath = [UIBezierPath bezierPathWithRoundedRect:self.scanningRect cornerRadius:self.cornerRadius];
    [clipPath appendPath:scanningPath];

    clipPath.usesEvenOddFillRule = YES;
    [clipPath addClip];
    [self.shadowColor setFill];
    [clipPath fill];
}

#pragma mark - Private

- (void)updateViewWithRect:(CGRect)viewfinderRect {
    self.scanningRect = viewfinderRect;
    [self setNeedsDisplay];
}

@end
