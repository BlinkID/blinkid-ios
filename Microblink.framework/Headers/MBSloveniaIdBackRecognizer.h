//
// MBSloveniaIdBackRecognizer.h
//
// Created by juraskrlec on 19/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBSloveniaIdBackRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Slovenia ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSloveniaIdBackRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning SloveniaIdBackRecognizer
 */
@property (nonatomic, strong, readonly) MBSloveniaIdBackRecognizerResult *result;

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
* Defines if date of issue of Slovenian ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

@end

NS_ASSUME_NONNULL_END
