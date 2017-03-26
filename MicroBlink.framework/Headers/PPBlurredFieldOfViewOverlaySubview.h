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
 * The subview is presented as unblurred view on blurred background, where unblurred location animates to detection location.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPBlurredFieldOfViewOverlaySubview : PPOverlaySubview

- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

/** Duration of the animation */
@property (nonatomic, assign) CGFloat animationDuration;

@end

NS_ASSUME_NONNULL_END
