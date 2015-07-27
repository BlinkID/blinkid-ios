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
 * Default is NO.
 *
 * In general, NO is the safe variant, if your UI is designed so that the user needs to place the camera
 * correctly above the ID document.
 */
@property (nonatomic, assign) BOOL detectMachineReadableZonePosition;

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
