//
// MBCroatiaCombinedRecognizer.h
//
// Created by juraskrlec on 18/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBCroatiaCombinedRecognizerResult.h"

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
* Recognizer which can front and back side of Croatian national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCroatiaCombinedRecognizer : MBRecognizer<NSCopying, MBCombinedRecognizer, MBDigitalSignature, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning CroatiaCombinedRecognizer
 */
@property (nonatomic, strong, readonly) MBCroatiaCombinedRecognizerResult *result;

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
* Defines if date of expiry of Croatian ID document should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if date of issue of Croatian ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if first name of Croatian ID owner should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFirstName;

/**
* Defines if issuer of Croatian ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractIssuedBy;

/**
* Defines if last name of Croatian ID owner should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractLastName;

/**
* Defines if residence of Croatian ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractResidence;

/**
* Defines if sex of Croatian ID owner should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;


@end

NS_ASSUME_NONNULL_END
