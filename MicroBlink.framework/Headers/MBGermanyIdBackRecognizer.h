//
// MBGermanyIdBackRecognizer.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBGermanyIdBackRecognizerResult.h"


#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of German ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBGermanyIdBackRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning GermanyIdBackRecognizer
 */
@property (nonatomic, strong, readonly) MBGermanyIdBackRecognizerResult *result;

/**
* Defines if address of German ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if issuing authority of German ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAuthority;

/**
* Defines if colour of eyes of German ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractColourOfEyes;

/**
* Defines if date of issue of German ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if height of German ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractHeight;

@end

NS_ASSUME_NONNULL_END
