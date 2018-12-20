//
// MBSwitzerlandPassportRecognizer.h
//
// Created by juraskrlec on 17/12/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBSwitzerlandPassportRecognizerResult.h"

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
* Recognizer which can scan Switzerland passport.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSwitzerlandPassportRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning SwitzerlandPassportRecognizer
 */
@property (nonatomic, strong, readonly) MBSwitzerlandPassportRecognizerResult *result;

/**
* Defines if issuing authority of Switzerland passport should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAuthority;

/**
* Defines if date of birth of Switzerland passport owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
* Defines if date of expiry of Switzerland passport should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if date of issue of Switzerland passport should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if given name of Switzerland passport owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractGivenName;

/**
* Defines if height of Switzerland passport owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractHeight;

/**
* Defines if passport number of Switzerland passport should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPassportNumber;

/**
* Defines if place of origin of Switzerland passport owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPlaceOfOrigin;

/**
* Defines if sex of Switzerland passport owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

/**
* Defines if surname of Switzerland passport owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
