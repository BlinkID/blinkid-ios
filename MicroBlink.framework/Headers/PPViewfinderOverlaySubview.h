//
//  PPOcrLineAnimationViewLayer.h
//  PhotoPayFramework
//
//  Created by Jurica Cerovec on 19/11/13.
//  Copyright (c) 2013 MicroBlink Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "PPOverlaySubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A wrapper around CAShapeLayer which is used for presenting a status about payslip and barcode detection.

 The layer is used to draw a scanning window with a viewwinder.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPViewfinderOverlaySubview : PPOverlaySubview

/* Animation layer for viewfinder */
@property (nonatomic, strong) CAShapeLayer *trackingLayer;

/** Initial margin of the viewfinder */
@property (nonatomic, assign) CGFloat initialViewfinderMargin;

/** Initial Color of the viewfinder */
@property (nonatomic, strong) UIColor *initialColor;

/** Success Color of the viewfinder */
@property (nonatomic, strong) UIColor *successColor;

/** Width of the dots */
@property (nonatomic, assign) CGFloat strokeWidth;

/** Duration of the animation */
@property (nonatomic, assign) CGFloat animationDuration;

/** YES if viewfinder should move on successful detection */
@property (nonatomic, assign) BOOL moveable;

/**
 Initializes the layer
 */
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
