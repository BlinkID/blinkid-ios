//
//  PPBaseOverlayViewController.h
//  BarcodeFramework
//
//  Created by Jura on 06/06/14.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPOverlayViewController.h"
#import "PPOverlaySubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Common base class for PhotoPay default overlay view controllers
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPBaseOverlayViewController : PPOverlayViewController

/**
 * Registers a subview for overlay events.
 */
- (void)registerOverlaySubview:(UIView<PPOverlaySubview>*)subview;

/**
 * Unregisters a subview for overlay events.
 */
- (void)unregisterOverlaySubview:(UIView<PPOverlaySubview>*)subview;

/**
 * Delegate for subview animation events.
 */
@property (nonatomic, weak) id<PPOverlaySubviewDelegate> overlaySubviewsDelegate;

@end

NS_ASSUME_NONNULL_END