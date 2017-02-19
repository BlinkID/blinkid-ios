//
//  PPModernViewfinderOverlaySubview.h
//  PhotoPayFramework
//
//  Created by Marko Mihovilić on 02/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPOverlaySubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting the status of detection.
 * The subview is presented as green corners located on edges of detection points.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPModernViewfinderOverlaySubview : PPOverlaySubview

/**
 * Denotes if view finder is moveable. Viewfinder will move whenever something is detected and will return to default position if no object
 * is detected for some time.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL moveable;

/**
 * Margins between overlay bounds and default corner positions while in portrait orientation.
 */
@property (nonatomic) UIEdgeInsets portraitMargins;

/**
 * Margins between overlay bounds and default corner positions while in landscape orientation.
 */
@property (nonatomic) UIEdgeInsets landscapeMargins;

@end

NS_ASSUME_NONNULL_END
