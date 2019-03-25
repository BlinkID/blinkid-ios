//
// MBBruneiMilitaryIdBackRecognizer.h
//
// Created by juraskrlec on 20/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBBruneiMilitaryIdBackRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"
#import "MBSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBEncodeSignatureImage.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Brunei Military ID card.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBruneiMilitaryIdBackRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning BruneiMilitaryIdBackRecognizer
 */
@property (nonatomic, strong, readonly) MBBruneiMilitaryIdBackRecognizerResult *result;

/**
* Defines if date of expiry of Brunei Military ID card should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if date of issue of Brunei Military ID card should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

@end

NS_ASSUME_NONNULL_END
