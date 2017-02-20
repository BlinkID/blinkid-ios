//
//  PPIDCardOverlayViewController.h
//  PhotoPayFramework
//
//  Created by Jura on 29/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPModernBaseOverlayViewController.h"

#import "PPIdCardOverlaySubview.h"

/**
 * Default overlay when using ID card recognizers.
 * This overlay contains PPModernOcrResultOverlaySubview and PPIdCardOverlaySubview.
 *
 * @see PPModernOcrResultOverlaySubview
 * @see PPIdCardOverlaySubview
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPIDCardOverlayViewController : PPModernBaseOverlayViewController

/**
 * Subview which shows the viewfinder - the rectangle area in which the user needs to position the ID document
 */
@property (nonatomic) PPIdCardOverlaySubview *idCardSubview;

@end
