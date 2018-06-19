//
//  MBPolandCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBPolandCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBSignatureImage.h"
#import "MBFaceImage.h"

#import "MBDigitalSignature.h"

#import "MBEncodeFaceImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBEncodeSignatureImage.h"

#import <Foundation/Foundation.h>

/**
 * Polish ID Combined Recognizer.
 *
 * Polish ID Combined recognizer is used for scanning both front and back side of Polish ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBPolandCombinedRecognizer : MBLegacyRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFullDocumentImage, MBFaceImage, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBDigitalSignature>

MB_INIT

/**
 * Polish ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBPolandCombinedRecognizerResult* result;

/**
 *  Defines if sex of Polish ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if citizenship of Polish ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if date of birth of Polish ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractGivenNames;

/**
 * Defines if date of expiry should be extracted from Polish ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFamilyName;

/**
 * Defines if date of expiry should be extracted from Polish ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractParentsGivenNames;

/**
 * Defines if date of expiry should be extracted from Polish ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

@end
