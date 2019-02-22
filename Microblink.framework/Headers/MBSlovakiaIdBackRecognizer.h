//
// MBSlovakiaIdBackRecognizer.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBSlovakiaIdBackRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Slovak ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSlovakiaIdBackRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning SlovakiaIdBackRecognizer
 */
@property (nonatomic, strong, readonly) MBSlovakiaIdBackRecognizerResult *result;

/**
* Defines if address of Slovak ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if place of birth of Slovak ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
* Defines if special remarks of Slovak ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSpecialRemarks;

/**
* Defines if surname at birth of Slovak ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSurnameAtBirth;

@end

NS_ASSUME_NONNULL_END
