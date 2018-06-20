//
//  MBCroatiaIdFrontRecognizer.h
//  Showcase
//
//  Created by DoDo on 09/04/2018.
//  Copyright © 2018 MicroBlink Ltd. All rights reserved.
//

#ifndef MBCroatiaIdFrontRecognizer_h
#define MBCroatiaIdFrontRecognizer_h

#import "MBMicroBlinkDefines.h"
#import "MBLegacyRecognizer.h"
#import "MBMicroBlinkInitialization.h"
#import "MBCroatiaIdFrontRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBSignatureImage.h"
#import "MBFaceImage.h"

#import <Foundation/Foundation.h>

/**
 * Croatian ID Front Recognizer.
 *
 * Croatian ID Front recognizer is used for scanning front side of Croatian ID. It always extracts
 * identity card number, first and last name of ID holder while extracting other elements is optional.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCroatiaIdFrontRecognizer : MBLegacyRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBSignatureImage, MBFaceImage>

MB_INIT

/**
 * Croatian ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBCroatiaIdFrontRecognizerResult *result;

/**
 *  Defines if sex of Croatian ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if citizenship of Croatian ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCitizenship;

/**
 * Defines if date of birth of Croatian ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if date of expiry should be extracted from Croatian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

@end


#endif /* MBCroatiaIdFrontRecognizer_h */
