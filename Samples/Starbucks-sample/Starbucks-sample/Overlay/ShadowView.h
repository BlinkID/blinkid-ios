//
//  PPScanningOvershadowView.h
//  PhotoPay-Slovakia
//
//  Created by Luka Zuanovic on 09/11/2016.
//  Copyright © 2016 MicroBlink. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ShadowView : UIView

@property UIColor *shadowColor;
@property CGRect scanningRect;
@property CGFloat cornerRadius;

- (instancetype)initWithFrame:(CGRect)frame
                  shadowColor:(UIColor *)shadowColor
                 scanningRect:(CGRect)scanningRect
                 cornerRadius:(CGFloat)cornerRadius;

- (void)updateOvershadow:(CGRect)scanningRect;
@end
