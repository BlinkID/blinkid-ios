//
//  MBQuadDetectorResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 19/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBDetectorResult.h"
#import "MBQuadrangle.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all detectors that are used for MBQuadrangle detection.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBQuadDetectorResult : MBDetectorResult <NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Returns the location of detected quadrilateral in coordinate system of image in which detection was performed.
 */
@property (nonatomic, nullable, strong, readonly) MBQuadrangle *quadrangle;

@end

NS_ASSUME_NONNULL_END
