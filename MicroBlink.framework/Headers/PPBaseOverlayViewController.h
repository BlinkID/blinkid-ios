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
 * Common base class for default overlay view controllers
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPBaseOverlayViewController : PPOverlayViewController

/**
 * Registers a subview for PPOverlaySubview protocol events.
 */
- (void)registerOverlaySubview:(UIView<PPOverlaySubview> *)subview;

/**
 * Unregisters a subview for PPOverlaySubview protocol events.
 */
- (void)unregisterOverlaySubview:(UIView<PPOverlaySubview> *)subview;

/**
 * Delegate for subview animation events.
 */
@property (nonatomic, weak) id<PPOverlaySubviewDelegate> overlaySubviewsDelegate;

@end

NS_ASSUME_NONNULL_END
