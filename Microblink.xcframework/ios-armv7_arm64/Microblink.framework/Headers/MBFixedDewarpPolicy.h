//
//  MBFixedDewarpPolicy.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 21/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBDewarpPolicy.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Fixed dewarp policy. Dewarp height will be exactly as defined by its dewarpHeight.
 *
 * This policy is usually best for processor groups that use legacy BlinkOCR.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBFixedDewarpPolicy : MBDewarpPolicy

/**
 * Default dewarp height value used when using default constructor.
 */
- (instancetype)init;

/**
 * @param dewarpHeight Desired dewarp height in pixels. Note that if device does not support given
 *                     dewarp height, the max supported by the device will be used.
 */
- (instancetype)initWithDewarpHeight:(NSUInteger)dewarpHeight NS_DESIGNATED_INITIALIZER;

/**
 * Returns the desired dewarp height (in pixels) as specified by this policy.
 *
 * Default: 100
 */
@property (nonatomic, assign, readonly) NSUInteger dewarpHeight;

@end

NS_ASSUME_NONNULL_END
