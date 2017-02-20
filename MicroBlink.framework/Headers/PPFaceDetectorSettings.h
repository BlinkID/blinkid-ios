//
//  PPFaceDetectorSettings.h
//  BlinkIdFramework
//
//  Created by Dino on 09/05/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPQuadDetectorSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class used for Face Detection (commonly used in detecting images on IDs)
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPFaceDetectorSettings : PPDetectorSettings

/**
 * Initializes Face Detector with desired decoding info. When using default initializer, default decoding info will be used:
 *      returning whole image with dewarp height of 300
 *
 *  @param decodingInfo information about part of the image which will be decoded
 *
 *  @return initialized object
 */
- (instancetype)initWithDecodingInfo:(PPDecodingInfo *)decodingInfo NS_DESIGNATED_INITIALIZER;

/**
 * Initializes Face Detector with default decoding info. Default decoding info is as follows.
 * This will can be used to output the part of the image which eaxactly matches the part of the image with a face, and is
 * dewarped to a dewarp height 300px.
 *
 *   PPDecodingInfo *decodingInfo = [[PPDecodingInfo alloc] initWithLocation:CGRectMake(0.0, 0.0, 1.0, 1.0)
 *                                                            dewarpedHeight:300U
 *                                                                  uniqueId:@"Face"];
 *
 *  @return initialized object
 */
- (instancetype)init;

/**
 * Decoding info of Face detector
 */
@property (nonatomic) PPDecodingInfo *decodingInfo;

@end

NS_ASSUME_NONNULL_END
