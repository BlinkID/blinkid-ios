//
//  MBDetector.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 19/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBEntity.h"
#import "MBDetectorResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all detectors
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDetector : MBEntity

/**
 * Base detector result
 */
@property (nonatomic, readonly, weak) MBDetectorResult *baseResult;

@end

NS_ASSUME_NONNULL_END
