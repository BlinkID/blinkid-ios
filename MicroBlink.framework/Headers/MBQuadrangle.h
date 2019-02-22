//
//  MBQuadrangle.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 08/12/2017.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class represents the quadrangle (arbitrary geometric object with 4 different corner points
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBQuadrangle : NSObject

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

/**
 * Returns the center point of the Quadrangle
 * @return center point
 */
- (CGPoint)center;

@end

NS_ASSUME_NONNULL_END

