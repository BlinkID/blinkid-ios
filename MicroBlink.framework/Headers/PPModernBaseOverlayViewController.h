//
//  PPModernBaseOverlayViewController.h
//  PhotoPayFramework
//
//  Created by Jura on 10/10/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPBaseOverlayViewController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class of all default overlays included in SDK. This class is an abstract class and should be subclassed.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPModernBaseOverlayViewController : PPBaseOverlayViewController

/**
 * Button to cancel scanning/dismiss view.
 */
@property (nonatomic, strong) UIButton *cancelButton;

/**
 * Button for displaying flash.
 */
@property (nonatomic, strong) UIButton *torchButton;

@end

NS_ASSUME_NONNULL_END