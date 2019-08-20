//
// MBBelgiumIdFrontRecognizer.h
//
// Created by juraskrlec on 13/08/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBBelgiumIdFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Belgium national ID card.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBelgiumIdFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning BelgiumIdFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBBelgiumIdFrontRecognizerResult *result;

@end

NS_ASSUME_NONNULL_END
