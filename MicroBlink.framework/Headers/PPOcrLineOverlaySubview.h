//
//  PPOcrLineOverlayView.h
//  PhotoPayFramework
//
//  Created by Jurica Cerovec on 19/11/13.
//  Copyright (c) 2013 MicroBlink Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PPOverlaySubview.h"

NS_ASSUME_NONNULL_BEGIN

#define WINDOW_STROKE_COLOR_DETECTION_FAILED ([UIColor colorWithRed:202.f / 255.f green:0.0f / 255.f blue:12.f / 255.f alpha:1.0f])
#define WINDOW_STROKE_COLOR_DETECTION_SUCCESS ([UIColor colorWithRed:84.0f / 255.f green:176.f / 255.f blue:51.f / 255.f alpha:1.0f])

@class PPOcrLineAnimationViewLayer;
@class PPOcrLineHelpView;
@class PPOcrLineBackgroundView;

/**
 Class which wraps up
 - Background view (two gray parts of the UI)
 - Detection animation layer (which changes color upon successful payslip detection
 - and Help view
 */
@interface PPOcrLineOverlaySubview : PPOverlaySubview

/**
 Designated initializer. Sets the frame for the view, as well as
 position and size of the scanning window inside the frame.

 Position and size are given as percentages (e.g 0.4 = 40%), from the top
 of the frame
 */
- (instancetype)initWithFrame:(CGRect)frame
        startWindowPercentage:(CGFloat)startWindowPercentage
       heightWindowPercentage:(CGFloat)heightWindowPercentage NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

/**
 Toggles the help view
 */
- (void)toggleHelp;

@end

NS_ASSUME_NONNULL_END
