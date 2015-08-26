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

/**
 * Common base class for PhotoPay default overlay view controllers
 */
@interface PPBaseOverlayViewController : PPOverlayViewController

- (NSArray*)overlaySubviews;

/**
 Array with overlay subviews (UIView subclasses implementing the PPOverlaySubview protocol)
 */
- (void)addOverlaySubview:(UIView<PPOverlaySubview>*)subview;
- (void)removeOverlaySubview:(UIView<PPOverlaySubview>*)subview;

@property (nonatomic, weak) id<PPOverlaySubviewDelegate> overlaySubviewsDelegate;

@end
