//
//  PPDetectorResult.h
//  BlinkIdFramework
//
//  Created by Jura on 10/01/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPDetectionStatus.h"
#import "PPMicroBlinkDefines.h"

/**
 * Enum for type of detection status.
 */
typedef NS_ENUM(NSUInteger, PPDetectionCode) {
    /**
     * Object detection has failed.
     */
    PPDetectionCodeFail = 0,
    
    /**
     * Object was detected partially. Only some PhotoPay detectors support this.
     */
    PPDetectionCodeFallback,
    
    /**
     * Object detection has succeded.
     */
    PPDetectionCodeSuccess,
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Abstract detector result objet
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPDetectorResult : NSObject

/**
 * Detection code which describes the status of detecton
 */
@property (nonatomic, assign, readonly) PPDetectionCode code;

/**
 * Detection status which describes the status of detecton
 */
@property (nonatomic, assign, readonly) PPDetectionStatus status;

/**
 * Tranformation matrix which transforms the coordinate system in which the OCR layout is given
 * (i.e. coordinate system of the image) to the coordinate system of the device screen.
 */
@property (nonatomic, assign) CGAffineTransform transform;

/**
 * Initializes the result with result code
 *
 *  @return initialized object
 */
- (instancetype)initWithCode:(PPDetectionCode)code status:(PPDetectionStatus)status NS_DESIGNATED_INITIALIZER;

/**
 * Please use designated initializer.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
