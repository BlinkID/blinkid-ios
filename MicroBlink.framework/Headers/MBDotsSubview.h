//
//  PPDotsAnimationLayer.h
//  BarcodeFramework
//
//  Created by Jura on 06/06/14.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "MBSubview.h"
#import "MBPointDetectorSubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A wrapper around CAShapeLayer which is used for presenting a status about barcode detections

 The layer is used to draw dots representing barcodes
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDotsSubview : MBSubview <MBPointDetectorSubview>

/* Animation layer for barcode tracking */
@property (nonatomic, strong) CAShapeLayer *dotsLayer;

/** Color of the dots */
@property (nonatomic, strong) UIColor *dotsColor;

/** Width of the dots */
@property (nonatomic, assign) CGFloat dotsStrokeWidth;

/** Radius of dots */
@property (nonatomic, assign) CGFloat dotsRadius;

/** Duration of the animation */
@property (nonatomic, assign) CGFloat animationDuration;

/**
 Initializes the layer
 */
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
