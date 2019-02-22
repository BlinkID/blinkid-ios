//
//  MBDetectorResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 19/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBDetectionStatus.h"

/**
 * Enum for type of detection status.
 */
typedef NS_ENUM(NSUInteger, MBDetectionCode) {
    /**
     * Object detection has failed.
     */
    MBDetectionCodeFail = 0,
    
    /**
     * Object was detected partially. Only some PhotoPay detectors support this.
     */
    MBDetectionCodeFallback,
    
    /**
     * Object detection has succeded.
     */
    MBDetectionCodeSuccess,
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all detectors results
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDetectorResult : NSObject

@property (nonatomic, assign, readonly) MBDetectionCode detectionCode;
@property (nonatomic, assign, readonly) MBDetectionStatus detectionStatus;

@end

NS_ASSUME_NONNULL_END

