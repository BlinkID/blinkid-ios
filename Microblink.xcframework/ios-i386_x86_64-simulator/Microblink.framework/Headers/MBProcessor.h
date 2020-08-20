//
//  MBProcessor.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 02/03/2018.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBEntity.h"
#import "MBProcessorResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all processors
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBProcessor : MBEntity

/**
 * Base processor result
 */
@property (nonatomic, readonly, weak) MBProcessorResult *baseResult;

@end

NS_ASSUME_NONNULL_END

