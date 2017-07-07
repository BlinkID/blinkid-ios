//
//  PPScanningOvershadowView.h
//  PhotoPay-Slovakia
//
//  Created by Luka Zuanovic on 09/11/2016.
//  Copyright © 2016 MicroBlink. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ShadowView : UIView

@property (strong, nonatomic) UIColor *shadowColor;

@property (assign, nonatomic) CGRect scanningRect;

@property (assign, nonatomic) CGFloat cornerRadius;


- (instancetype)initWithFrame:(CGRect)frame andShadowColor:(UIColor *)shadowColor andCornerRadius:(CGFloat)cornerRadius NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (void)updateViewWithRect:(CGRect)viewfinderRect;

@end
