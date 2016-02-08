//
//  PPQuadDetectorSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 04/02/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPDetectorSettings.h"

#import "PPDocumentDecodingInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings for Quad detectors
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPQuadDetectorSettings : PPDetectorSettings

/**
 * Each quad detector has decoding information which defines the regios of the image which will be decoded
 */
@property (nonatomic) PPDocumentDecodingInfo *info;

@end

NS_ASSUME_NONNULL_END
