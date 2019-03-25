//
// MBRomaniaIdFrontRecognizer.h
//
// Created by juraskrlec on 18/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBRomaniaIdFrontRecognizerResult.h"
#import "MBGlareDetection.h"
#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front side of Romania ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBRomaniaIdFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning RomaniaIdFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBRomaniaIdFrontRecognizerResult *result;

/**
* Defines if address of Romania ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if date of expiry of Romania ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if date of issue of Romania ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if first name of Romania ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFirstName;

/**
* Defines if issuing authority of Romania ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractIssuedBy;

/**
* Defines if place of birth of Romania ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
* Defines if sex of Romania ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

/**
* Defines if surname of Romania ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
