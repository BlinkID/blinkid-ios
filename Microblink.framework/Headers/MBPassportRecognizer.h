//
// MBPassportRecognizer.h
//
// Created by juraskrlec on 23/04/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBPassportRecognizerResult.h"

#import "MBDigitalSignature.h"

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
* Recognizer which can scan all passports with MRZ.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBPassportRecognizer : MBRecognizer<NSCopying, MBDigitalSignature, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning PassportRecognizer
 */
@property (nonatomic, strong, readonly) MBPassportRecognizerResult *result;

/**
 * Defines whether to anonymize Netherlands MRZ
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL anonymizeNetherlandsMrz;

@end

NS_ASSUME_NONNULL_END
