//
//  PPModernOcrResultSubview.h
//  PhotoPayFramework
//
//  Created by Marko Mihovilić on 05/09/14.
//  Copyright (c) 2014 Microblink Ltd. All rights reserved.
//

#import "MBSubview.h"
#import "MBPointDetectorSubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting status of OCR detection. Dots are displayed over locations of detected characters.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDotsResultSubview : MBSubview <MBPointDetectorSubview>

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
 * Default: YES
 */
@property (assign, nonatomic) BOOL shouldIgnoreFastResults;

/**
 * Duration of fade animation for each dot.
 *
 * Default: 0.25f
 */
@property (assign, nonatomic) CGFloat charFadeInDuration;

/**
 * Maximum number of dots shown on screen. This count has to be in range [20,50].
 *
 * Default: 50
 */
@property (assign, nonatomic) NSUInteger dotCount;

@end

NS_ASSUME_NONNULL_END
