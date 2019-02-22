//
//  MBQuadWithSizeDetector.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 20/03/2018.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBQuadDetector.h"
#import "MBQuadWithSizeDetectorResult.h"
#import "MBMicroblinkInitialization.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all detectors  that are used for MBQuadrangle
 * detection and can also provide physical size of the detected document.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBQuadWithSizeDetector : MBQuadDetector

MB_INIT_UNAVAILABLE

/**
 * Quad with size detector result
 */
@property (nonatomic, weak, readonly) MBQuadWithSizeDetectorResult *quadWithSizeResult;

@end

NS_ASSUME_NONNULL_END
