//
//  MBCroatiaIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBCroatiaIdBackRecognizer_h
#define MBCroatiaIdBackRecognizer_h

#import "MBMicroBlinkDefines.h"
#import "MBLegacyRecognizer.h"
#import "MBMicroBlinkInitialization.h"
#import "MBCroatiaIdBackRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"

#import <Foundation/Foundation.h>

/**
 * Croatian ID Back Recognizer.
 *
 * Croatian ID Back recognizer is used for scanning back side of Croatian ID. It always extracts
 * MRZ zone and address of ID holder while extracting other elements is optional.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCroatiaIdBackRecognizer : MBLegacyRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage>

MB_INIT

/**
 * Croatian ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBCroatiaIdBackRecognizerResult *result;

/**
 * Defines if issuing authority of Croatian ID should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
 * Defines if date of issue of Croatian ID should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

@end

#endif /* MBCroatiaIdBackRecognizer_h */
