//
//  PPDetectorResult.h
//  BlinkIdFramework
//
//  Created by Jura on 10/01/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPMicroBlinkDefines.h"

typedef NS_ENUM(NSUInteger, PPDetectionCode) {
    PPDetectionCodeFail = 0,
    PPDetectionCodeFallback,
    PPDetectionCodeSuccess,
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Abstract detector result objet
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPDetectorResult : NSObject

/**
 * Detection code which describes the status of detecton
 */
@property (nonatomic, assign, readonly) PPDetectionCode code;

/**
 * Initializes the result with result code
 *
 *  @return initialized object
 */
- (instancetype)initWithCode:(PPDetectionCode)code NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
