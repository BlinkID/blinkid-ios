//
// MBSwitzerlandIdBackRecognizer.h
//
// Created by juraskrlec on 17/12/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBSwitzerlandIdBackRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Switzerland ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSwitzerlandIdBackRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning SwitzerlandIdBackRecognizer
 */
@property (nonatomic, strong, readonly) MBSwitzerlandIdBackRecognizerResult *result;

/**
* Defines if issuing authority of Switzerland ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAuthority;

/**
* Defines if date of expiry of Switzerland ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if date of issue of Switzerland ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if height of Switzerland ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractHeight;

/**
* Defines if place of origin of Switzerland ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPlaceOfOrigin;

/**
* Defines if sex of Switzerland ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
