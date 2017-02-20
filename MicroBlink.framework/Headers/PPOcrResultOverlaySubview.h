//
//  PPOcrResultView.h
//  PhotoPayFramework
//
//  Created by Jura on 01/02/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PPOverlaySubview.h"

NS_ASSUME_NONNULL_BEGIN

@class PPOcrLayout;

/**
 * Overlay subview presenting status of OCR detection. OCR results are displayed as green characters over detected locations.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPOcrResultOverlaySubview : PPOverlaySubview

@end

NS_ASSUME_NONNULL_END
