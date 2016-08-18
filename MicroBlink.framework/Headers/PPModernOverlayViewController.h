//
//  PPModernOverlayViewController.h
//  PhotoPayFramework
//
//  Created by Marko Mihovilić on 01/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPModernBaseOverlayViewController.h"

@class PPPhotoPayUiSettings;

/**
 * Default version of overlay view controller with modern design.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPModernOverlayViewController : PPModernBaseOverlayViewController

/**
 * Supported orientations mask
 */
@property (nonatomic, assign) UIInterfaceOrientationMask hudMask;

/**
 * Common photopay UI settings
 */
@property (nonatomic, strong, readonly) PPPhotoPayUiSettings* uiSettings;

/**
 * Designated intializer.
 *
 *  @param uiSettings PPPhotoPayUiSettings object
 *
 *  @return initialized overlayViewController
 */
- (instancetype)initWithUiSettings:(PPPhotoPayUiSettings *)uiSettings;

@end
