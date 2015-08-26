//
//  PPMrtdRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 26/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring MRTD Recognizer
 *
 * MRTD Recognizer recognizer is used for scanning and parsing Machine readable travel documents.
 * Typical MRTDs are passports, visas, ID cards. 
 * They can be recognized by two or three lines of monospace text, which contains all personal information.
 *
 * @see https://en.wikipedia.org/wiki/Machine-readable_passport
 */
@interface PPMrtdRecognizerSettings : PPRecognizerSettings

/**
 * Region of the image which will be OCR-ed.
 *
 * If detectMachineReadableZonePosition is set to YES, then the OCR area will be determined automatically, and this property
 * does not have any effect.
 *
 * Default:
 *  When device is in portrait: (0.0f, 0.52f, 1.0f, 0.18f);
 *  When device is in landscape: (0.15f, 0.535f, 0.7f, 0.315f);
 *
 * If you want to change this, keep in mind:
 *  - it might be a good idea to have different values for portrait and landscape
 *  - larger area means easier positioning of the device above the ID card or passport
 *  - larger area also means slower OCR process (time consumption depends roughly linearly to image size)
 */
@property (nonatomic, assign) CGRect mrtdRoi;

/**
 * If YES, MRTD recognizer will try to detect the position of Machine readable zone,
 * instead of using mrtdRoi as position. Effectively, if YES is used, value in mrtdRoi isn't used.
 * 
 * Default is YES.
 *
 * In general, if your UI is designed so that the user needs to place the camera
 * correctly above the ID document, then NO is OK. Otherwise use YES.
 */
@property (nonatomic, assign) BOOL detectMachineReadableZonePosition;

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
