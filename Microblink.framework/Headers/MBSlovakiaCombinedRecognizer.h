//
//  MBSlovakiaCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSlovakiaCombinedRecognizerResult.h"

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

NS_ASSUME_NONNULL_BEGIN

/**
 * Slovak ID Combined Recognizer.
 *
 * Slovak ID Combined recognizer is used for scanning both front and back side of Slovak ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSlovakiaCombinedRecognizer : MBLegacyRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFullDocumentImage, MBSignatureImage, MBFaceImage, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBEncodeSignatureImage, MBDigitalSignature>

MB_INIT

/**
 * Slovak ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBSlovakiaCombinedRecognizerResult* result;

/**
 * Defines if owner's sex should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if owner's nationality should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if owner's date of birth should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if ID's date of expiry should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if ID's date of issue should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if issuing authority should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuedBy;

/**
 * Defines if issuing document number should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDocumentNumber;

/**
 * Defines if owner's surname at birth should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurnameAtBirth;

/**
 * Defines if owner's place of birth should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if owner's special remarks should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSpecialRemarks;

@end

NS_ASSUME_NONNULL_END
