//
//  PPMrtdDetectorSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 07/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPQuadDetectorSettings.h"

NS_ASSUME_NONNULL_BEGIN

PP_CLASS_AVAILABLE_IOS(6.0) @interface PPMrtdDetectorSettings : PPQuadDetectorSettings

/**
 * Initializes MRTD Detector settings with document decoding information
 *
 *  @param info information about parts of the image which will be decoded
 *
 *  @return initialized object
 */
- (instancetype)initWithDocumentDecodingInfo:(PPDocumentDecodingInfo *)info NS_DESIGNATED_INITIALIZER;

/**
 * Initializes MRTD detector with default document decoding information
 *
 * Default info contains:
 *    - One entry
 *    - location - CGRect(0.f, 0.f, 1.f, 1.f)
 *    - dewarped height - 700U
 *
 *
 * The exact code which initializes default info is:
 *     PPDocumentDecodingInfo *info = [[PPDocumentDecodingInfo alloc] init];
 *     [info addEntry:[[PPDocumentDecodingInfoEntry alloc] initWithLocation:CGRectMake(0.0, 0.0, 1.0, 1.0) dewarpedHeight:100U]];
 *
 *  @return initialized object
 */
- (instancetype)init;

// Unavailable initializer from superclass
- (instancetype)initWithSettings:(DetectorSettingsImpl*)settings NS_UNAVAILABLE;

/**
 * If YES, the whole document is detected, as opposed to just MRZ zone on the bottom of the document
 
 * Default: YES.
 */
@property (nonatomic) BOOL detectFullDocument;

@end

NS_ASSUME_NONNULL_END
