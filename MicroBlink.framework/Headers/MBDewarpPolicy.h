//
//  MBDewarpPolicy.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 21/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all dewarp policies
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDewarpPolicy : NSObject

- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
