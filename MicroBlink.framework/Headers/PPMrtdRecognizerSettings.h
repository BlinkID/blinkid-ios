//
//  PPMrtdRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 26/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring MRTD Recognizer
 *
 * MRTD Recognizer recognizer is used for scanning and parsing Machine readable travel documents.
 * Typical MRTDs are passports, visas, ID cards. 
 * They can be recognized by two or three lines of monospace text, which contains all personal information.
 *
 * @see https://en.wikipedia.org/wiki/Machine-readable_passport
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPMrtdRecognizerSettings : PPRecognizerSettings

/**
 * If YES, MrtdRecognizer will return MRTD results even if they are not parsed.
 *
 * Default NO.
 *
 * Setting this to YES will give you the chance to parse MRZ result, if Mrtd recognizer wasn't
 * successful in parsing (this can happen since MRZ isn't always formatted accoring to ICAO Document 9303 standard.
 * @see http://www.icao.int/Security/mrtd/pages/Document9303.aspx
 *
 * When YES, MrtdRecognizerResult will be returned with isParsed property set to NO, and with rawOcrLayout property set
 * to the PPOcrLayout object which was the result of the OCR process.
 *
 * However, you should be careful when this property is set to YES, since obtained OcrLayout can contain OCR errors (for example
 * (0 <-> O, 2 <-> Z, etc.). If you set this to YES, then you need to perform your own parsing and error correction.
 *
 * If you set this to YES, we suggest the following approach in your result callback
 *
 *    - obtain mrtdResult
 *    - if [mrtdResult isParsed]
 *        - present result and return
 *    - else if mrtdResult can be parsed with your custom parsing algorithm
 *        - present your custom results and return
 *    - else continue scanning since MRTD result cannot be parsed at all
 */
@property (nonatomic, assign) BOOL allowUnparsedResults;

/**
 * If YES, and detectMachineReadableZonePosition is YES, MRTD recognizer will determine the position of the whole
 * MRTD document, based on the position of the machine readable zone. 
 *
 * Also, MRTD recognizer will dewarp and crop the image around the MRTD.
 *
 * This is useful if you're at the same time obtaining Dewarped image metadata, since it allows you to obtain dewarped and cropped
 * images of MRTD documents. Dewarped images are returned to scanningViewController:didOutputMetadata: callback, 
 * as PPImageMetadata objects with name @"MRTD"
 *
 * If NO, or if detectMachineReadableZonePosition is NO, this logic is not performed.
 *
 * Default: NO.
 */
@property (nonatomic, assign) BOOL dewarpFullDocument;

@end

NS_ASSUME_NONNULL_END
