//
//  PPQuadDetectorSettingsWithSize.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 18/10/2017.
//

#import "PPDetectorSettings.h"

#import "PPDecodingInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings for Quad detector with size, used for rectangular objects.
 * This class is an abstract class.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPQuadDetectorSettingsWithSize : PPDetectorSettings

/**
 * This is an abstract class. Please use one of concrete classes.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
