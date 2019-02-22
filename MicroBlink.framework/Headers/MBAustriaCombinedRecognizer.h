//
//  MBAustriaCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBMicroblinkDefines.h"
#import "MBRecognizer.h"
#import "MBMicroblinkInitialization.h"
#import "MBAustriaCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBFaceImage.h"
#import "MBFaceImageDpi.h"

#import "MBDigitalSignature.h"

#import "MBEncodeFaceImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBEncodeSignatureImage.h"

#import "MBFullDocumentImageExtensionFactors.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Austrian ID Combined Recognizer.
 *
 * Austrian ID Combined recognizer is used for scanning both front and back side of Austrian ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBAustriaCombinedRecognizer : MBRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFullDocumentImage, MBFullDocumentImageDpi, MBSignatureImage, MBSignatureImageDpi, MBFaceImage, MBFaceImageDpi, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBEncodeSignatureImage, MBDigitalSignature, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Austrian ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBAustriaCombinedRecognizerResult* result;

/**
 * Defines if issuing authority should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
 * Defines if date of issuance should be extracted from back side of Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssuance;

/**
 * Defines if owner's place of birth should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if owner's principal residence should be extracted from back side of Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPrincipalResidence;

/**
 * Defines if owner's height should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractHeight;

/**
 * Defines if owner's sex should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if owner's surname should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if owner's given name should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractGivenName;

/**
 * Defines if ownder's date of birth should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if owner's nationality should be extracted from Austrian Passport
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if date of issue should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if passport number should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPassportNumber;

/**
 * Defines if date of expiry should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

@end

NS_ASSUME_NONNULL_END
