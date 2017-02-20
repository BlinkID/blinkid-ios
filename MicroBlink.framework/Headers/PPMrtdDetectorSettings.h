//
//  PPMrtdDetectorSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 07/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPQuadDetectorSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class used for detection of MRTD documents
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPMrtdDetectorSettings : PPQuadDetectorSettings

/**
 * Initializes MRTD Detector settings with decoding information array
 *
 *  @param decodingInfoArray information about parts of the image which will be decoded, each array object represents 1 decoded part of
 * image
 *
 *  @return initialized object
 */
- (instancetype)initWithDecodingInfoArray:(NSArray<PPDecodingInfo *> *)decodingInfoArray NS_DESIGNATED_INITIALIZER;

/**
 * Initializes MRTD detector with default decoding information
 *
 * Default info contains:
 *    - location - CGRect(0.f, 0.f, 1.f, 1.f)
 *    - dewarped height - 700U
 *
 *
 * The exact code which initializes default info is:
 * [decodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:CGRectMake(0.0, 0.0, 1.0, 1.0)
 *      dewarpedHeight:700U
 *      uniqueId:@"MRTD"]];     //decodingInfoArray is property of PPQuadDetectorSettings superclass
 *
 *  @return initialized object
 */
- (instancetype)init;

/**
 * If YES, the whole document is detected, as opposed to just MRZ zone on the bottom of the document

 * Default: YES.
 */
@property (nonatomic) BOOL detectFullDocument;

@end

NS_ASSUME_NONNULL_END
