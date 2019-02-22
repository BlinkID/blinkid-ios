//
//  MBCroatiaIdBackRecognizer.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBCroatiaIdBackRecognizer_h
#define MBCroatiaIdBackRecognizer_h

#import "MBRecognizer.h"
#import "MBCroatiaIdBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

/**
 * Croatian ID Back Recognizer.
 *
 * Croatian ID Back recognizer is used for scanning back side of Croatian ID. It always extracts
 * MRZ zone and address of ID holder while extracting other elements is optional.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCroatiaIdBackRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Croatian ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBCroatiaIdBackRecognizerResult *result;

/**
 * Defines if residence of Croatian ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractResidence;

/**
 * Defines if issuer of Croatian ID should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuedBy;

/**
 * Defines if date of issue of Croatian ID should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

@end

#endif /* MBCroatiaIdBackRecognizer_h */
