//
// MBSlovakiaIdFrontRecognizer.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBSlovakiaIdFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Slovak national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSlovakiaIdFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning SlovakiaIdFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBSlovakiaIdFrontRecognizerResult *result;

/**
* Defines if date of birth of Slovak ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
* Defines if date of expiry of Slovak ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if date of issue of Slovak ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if document number of Slovak ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDocumentNumber;

/**
* Defines if first name of Slovak ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFirstName;

/**
* Defines if issuing authority of Slovak ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractIssuedBy;

/**
* Defines if last name of Slovak ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractLastName;

/**
* Defines if nationality of Slovak ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractNationality;

/**
* Defines if sex of Slovak ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
