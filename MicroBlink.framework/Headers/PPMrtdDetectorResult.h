//
//  PPOcrLineDetectorResult.h
//  BlinkIdFramework
//
//  Created by Jura on 10/01/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPQuadDetectorResultWithSize.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Detection code for MRTD detection
 */
typedef NS_ENUM(NSUInteger, PPMrtdDetectionCode) {

    /** Failed detection */
    PPMrtdDetectionCodeFail,

    /** Machine Readable Zone, three Machine Readable Lines with 30 characters each */
    PPMrtdDetectionCodeMRZTD1,

    /** Machine Readable Zone, two Machine Readable Lines with 36 characters each */
    PPMrtdDetectionCodeMRZTD2,

    /** Machine Readable Zone, two Machine Readable Lines with 44 characters each */
    PPMrtdDetectionCodeMRZTD3,

    /** Machine Readable Travel Document (Full Card), three Machine Readable Lines with 30 characters each */
    PPMrtdDetectionCodeMRTDTD1,

    /** Machine Readable Travel Document (Full Card), two Machine Readable Lines with 36 characters each */
    PPMrtdDetectionCodeMRTDTD2,

    /**Machine Readable Travel Document (Full Card), two Machine Readable Lines with 44 characters each */
    PPMrtdDetectionCodeMRTDTD3,

};

/**
 * Result of MRTD detector
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPMrtdDetectorResult : PPQuadDetectorResultWithSize

/**
 * Detection code of MRTD detection
 */
@property (nonatomic) PPMrtdDetectionCode mrtdDetectionCode;

@end

NS_ASSUME_NONNULL_END
