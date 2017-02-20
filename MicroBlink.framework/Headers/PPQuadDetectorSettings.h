//
//  PPQuadDetectorSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 04/02/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPDetectorSettings.h"

#import "PPDecodingInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings for Quad detector, used for rectangular objects.
 * This class is an abstract class.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPQuadDetectorSettings : PPDetectorSettings

/**
 * Each quad detector has decoding information which defines the regios of the image which will be decoded
 */
@property (nonatomic) NSArray<PPDecodingInfo *> *decodingInfoArray;

/**
 * This is an abstract class. Please use one of concrete classes.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
