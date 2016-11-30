//
//  PPIDCardOverlayViewController.h
//  PhotoPayFramework
//
//  Created by Jura on 29/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPModernBaseOverlayViewController.h"

/**
 * Default overlay when using ID card recognizers.
 * This overlay contains PPModernOcrResultOverlaySubview and PPModernViewFinderOverlaySubview.
 *
 * @see PPModernOcrResultOverlaySubview
 * @see PPModernViewFinderOverlaySubview
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPIDCardOverlayViewController : PPModernBaseOverlayViewController

@property (nonatomic) UIImageView *viewfinderImageView;

@property (nonatomic) UILabel *tooltipLabel;

@end
