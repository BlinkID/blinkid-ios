//
// MBCzechiaIdBackRecognizer.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBCzechiaIdBackRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan the back side of Czech IDs.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCzechiaIdBackRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning CzechiaIdBackRecognizer
 */
@property (nonatomic, strong, readonly) MBCzechiaIdBackRecognizerResult *result;

/**
* Defines if Czech ID's issuing authority should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAuthority;

/**
* Defines if Czech ID owner's permanent address should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPermanentStay;

/**
* Defines if Czech ID owner's personal number should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPersonalNumber;

@end

NS_ASSUME_NONNULL_END
