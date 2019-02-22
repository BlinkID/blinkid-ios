//
//  MBQuadDetector.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 19/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBDetector.h"
#import "MBQuadDetectorResult.h"
#import "MBMicroblinkInitialization.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all detectors that are used for MBQuadrangle detection.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBQuadDetector : MBDetector

MB_INIT_UNAVAILABLE

/**
 * Quad detector result
 */
@property (nonatomic, weak, readonly) MBQuadDetectorResult *quadResult;

@end

NS_ASSUME_NONNULL_END

