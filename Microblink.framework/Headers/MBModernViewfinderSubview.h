//
//  PPModernViewfinderSubview.h
//  PhotoPayFramework
//
//  Created by Marko Mihovilić on 02/09/14.
//  Copyright (c) 2014 Microblink Ltd. All rights reserved.
//

#import "MBSubview.h"
#import "MBQuadDetectorSubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting the status of detection.
 * The subview is presented as green corners located on edges of detection points.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBModernViewfinderSubview : MBSubview <MBQuadDetectorSubview>

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

/**
 * Resets the viewfinder position to it's initial position.
 */
- (void)resetPositions;

@end

NS_ASSUME_NONNULL_END
