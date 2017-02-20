//
//  PPMultiDetectorResult.h
//  BlinkIdFramework
//
//  Created by Jura on 10/01/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPDetectorResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Result of detection of multi detector object
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPMultiDetectorResult : PPDetectorResult

/**
 * Array of detector results
 */
@property (nonatomic) NSArray<__kindof PPDetectorResult *> *detectorResults;

/**
 * Obtains result at index
 *
 *  @param index of the result
 *
 *  @return detector result at given index
 */
- (PPDetectorResult *)resultAtIndex:(NSUInteger)index;

/**
 * number of results in multi detector result
 *
 *  @return number of results
 */
- (NSUInteger)count;

@end

NS_ASSUME_NONNULL_END
