//
// MBGermanyDlFrontRecognizer.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBGermanyDlFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Germany national DL cards
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBGermanyDlFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning GermanyDlFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBGermanyDlFrontRecognizerResult *result;

/**
* Defines if date of birth of Germany DL owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
* Defines if date of expiry of Germany DL should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if date of issue of Germany DL should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if first name of Germany DL owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFirstName;

/**
* Defines if issuing authority of Germany DL should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
* Defines if last name of Germany DL owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractLastName;

/**
* Defines if licence categories of Germany DL should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractLicenceCategories;

/**
* Defines if place of birth of Germany DL owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

@end

NS_ASSUME_NONNULL_END
