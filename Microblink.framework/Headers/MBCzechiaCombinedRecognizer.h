//
// MBCzechiaCombinedRecognizer.h
//
// Created by juraskrlec on 18/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBCzechiaCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"
#import "MBDigitalSignature.h"

#import "MBGlareDetection.h"
#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"
#import "MBSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBEncodeSignatureImage.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front and back side of Czechia national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCzechiaCombinedRecognizer : MBRecognizer<NSCopying, MBCombinedRecognizer, MBDigitalSignature, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning CzechiaCombinedRecognizer
 */
@property (nonatomic, strong, readonly) MBCzechiaCombinedRecognizerResult *result;

/**
* Defines if Czech ID's issuing authority should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAuthority;

/**
* Defines if Czech ID owner's date of birth should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
* Defines if Czech ID's date of expiry should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if Czech ID's date of issue should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if Czech ID owner's given names should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractGivenNames;

/**
* Defines if Czech ID owner's permanent address should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPermanentStay;

/**
* Defines if Czech ID owner's personal number should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPersonalNumber;

/**
* Defines if Czech ID owner's place of birth should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
* Defines if Czech ID owner's sex should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

/**
* Defines if Czech ID owner's surname should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSurname;


@end

NS_ASSUME_NONNULL_END
