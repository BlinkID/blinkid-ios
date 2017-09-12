//
//  PPQuadDetectorResultWithSize.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 30/08/2017.
//
//

#import "PPQuadDetectorResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Result of the detection of a Quad detector.
 * Quad results are results of detecting various rectangular objects.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPQuadDetectorResultWithSize : PPQuadDetectorResult

@property (nonatomic, assign) CGFloat physicalSizeInInches;

@end

NS_ASSUME_NONNULL_END
