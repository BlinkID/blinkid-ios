//
//  PPModernOcrResultOverlaySubview.h
//  PhotoPayFramework
//
//  Created by Marko Mihovilić on 05/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPOverlaySubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting status of OCR detection. Dots are displayed over locations of detected characters.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPModernOcrResultOverlaySubview : PPOverlaySubview

/**
 * Foreground color of dots.
 */
@property (strong, nonatomic) UIColor *foregroundColor;

/**
 * Border and shadow color of dots.
 */
@property (strong, nonatomic) UIColor *tintColor;

/**
 * If set YES, dots will not redraw until the animation is finished. This will make animation look much smoother on fast results.
 *
 * Default: NO
 */
@property (assign, nonatomic) BOOL shouldIgnoreFastResults;

/**
 * Duration of fade animation for each dot.
 *
 * Default: 0.25f
 */
@property (assign, nonatomic) CGFloat charFadeInDuration;

@end

NS_ASSUME_NONNULL_END
