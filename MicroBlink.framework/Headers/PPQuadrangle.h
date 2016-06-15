//
//  PPQuadrangle.h
//  BlinkIdFramework
//
//  Created by Jura on 03/02/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class represents the quadrangle (arbitrary geometric object with 4 different corner points
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPQuadrangle : NSObject

/** Upper left point */
@property (nonatomic, assign) CGPoint upperLeft;

/** Upper right point */
@property (nonatomic, assign) CGPoint upperRight;

/** Lower left point */
@property (nonatomic, assign) CGPoint lowerLeft;

/** Lower right point */
@property (nonatomic, assign) CGPoint lowerRight;

/**
 * Designated initializer which initializes all four corners of the quadrangle
 *
 *  @param upperLeft  upper left corner of the quadrangle
 *  @param upperRight upper right corner of the quadrangle
 *  @param lowerLeft  lower left corner of the quadrangle
 *  @param lowerRight lower right corner of the quadrangle
 *
 *  @return initialized quadrangle with four corners
 */
- (instancetype)initWithUpperLeft:(CGPoint)upperLeft
                       upperRight:(CGPoint)upperRight
                        lowerLeft:(CGPoint)lowerLeft
                       lowerRight:(CGPoint)lowerRight;

/**
 * Returns points of the quadrangle in array in the following order:
 * - upperLeft, upperRight, lowerLeft, lowerRight.
 *
 * The array contains object obtained by, e.g: [NSValue valueWithCGPoint:CGPointMake(0.0, 1.0)]
 *
 *  @return points of the quadrangle in an array
 */
- (NSArray *)toPointsArray;

/**
 * Creates new quadrangle from this quadrangle, transformed by specified affine transformation.
 */
- (instancetype)quadrangleWithTransformation:(CGAffineTransform)transform;

@end

NS_ASSUME_NONNULL_END
