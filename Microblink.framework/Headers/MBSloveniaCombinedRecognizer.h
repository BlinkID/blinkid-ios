//
// MBSloveniaCombinedRecognizer.h
//
// Created by juraskrlec on 19/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBSloveniaCombinedRecognizerResult.h"

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
* Recognizer which can scan front and back side of Slovenia national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSloveniaCombinedRecognizer : MBRecognizer<NSCopying, MBCombinedRecognizer, MBDigitalSignature, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning SloveniaCombinedRecognizer
 */
@property (nonatomic, strong, readonly) MBSloveniaCombinedRecognizerResult *result;

/**
* Defines if address of Slovenian ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if issuing administrative unit of Slovenian ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAdministrativeUnit;

/**
* Defines if date of expiry of Slovenian ID card should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if date of issue of Slovenian ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if given names of Slovenian ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractGivenNames;

/**
* Defines if nationality of Slovenian ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractNationality;

/**
* Defines if sex of Slovenian ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

/**
* Defines if surname of Slovenian ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
