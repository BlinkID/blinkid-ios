//
// MBEgyptIdFrontRecognizer.h
//
// Created by juraskrlec on 18/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBEgyptIdFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Egypt ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBEgyptIdFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning EgyptIdFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBEgyptIdFrontRecognizerResult *result;

/**
* Defines if national number of Egypt ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractNationalNumber;

@end

NS_ASSUME_NONNULL_END
