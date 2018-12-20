//
// MBMalaysiaIKadFrontRecognizer.h
//
// Created by juraskrlec on 17/12/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBMalaysiaIkadFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Malaysia iKad card.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBMalaysiaIkadFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning MalaysiaIKadFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBMalaysiaIkadFrontRecognizerResult *result;

/**
* Defines if address of Malaysian iKad owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if date of expiry of Malaysian iKad card should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if employer of Malaysian iKad owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractEmployer;

/**
* Defines if address of faculty, in which Malaysian iKad owner currently studies, should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFacultyAddress;

/**
* Defines if gender of Malaysian iKad owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractGender;

/**
* Defines if (full) name of Malaysian iKad owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractName;

/**
* Defines if nationality of Malaysian iKad owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractNationality;

/**
* Defines if passport number of Malaysian iKad owners passport should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPassportNumber;

/**
* Defines if sector in which  Malaysian iKad owner works should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSector;

@end

NS_ASSUME_NONNULL_END
