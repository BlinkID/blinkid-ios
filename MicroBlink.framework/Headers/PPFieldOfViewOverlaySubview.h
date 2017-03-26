//
//  FieldOfViewOverlaySubview.h
//  PhotoPayFramework
//
//  Created by Jura on 18/06/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPOverlaySubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting the status of detection.
 * The subview is presented as untinted view on tinted background, where untinted location animates to detection location.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPFieldOfViewOverlaySubview : PPOverlaySubview

- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

/**
 * Corner coordinates of last detected location
 */
@property (nonatomic, strong) NSArray *cornerCoordinates;

/** Duration of the animation */
@property (nonatomic, assign) CGFloat animationDuration;

/**
 * Aspect ration of untinted view
 */
@property (nonatomic, assign) CGFloat aspectRatio;

/**
 * Minimal height as portion of overlay subview height (in ranges [0,1.0])
 */
@property (nonatomic, assign) CGFloat minHeight;

/**
 * Max height as portion of overlay subview height (in ranges [0,1.0])
 */
@property (nonatomic, assign) CGFloat maxHeight;

@property (nonatomic, assign) CGFloat width;

@property (nonatomic, assign) CGFloat height;

@property (nonatomic, assign) CGFloat centerHeight;

@end

NS_ASSUME_NONNULL_END
