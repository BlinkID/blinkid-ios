//
//  PPModernBaseOverlayViewController.h
//  PhotoPayFramework
//
//  Created by Jura on 10/10/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPBaseOverlayViewController.h"

NS_ASSUME_NONNULL_BEGIN

PP_CLASS_AVAILABLE_IOS(6.0) @interface PPModernBaseOverlayViewController : PPBaseOverlayViewController

@property (nonatomic, strong) UIButton *cancelButton;
@property (nonatomic, strong) UIButton *torchButton;

- (void)applyViewShadow:(UIView*)view;

- (void)applyViewShadow:(UIView*)view radius:(CGFloat)radius;

- (void)applyFrameWithTouchInset:(UIButton*)button frame:(CGRect)frame inset:(CGSize)inset;

@end

NS_ASSUME_NONNULL_END