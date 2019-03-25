//
// MBBruneiMilitaryIdFrontRecognizer.h
//
// Created by juraskrlec on 20/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBBruneiMilitaryIdFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Brunei Military ID card.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBruneiMilitaryIdFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning BruneiMilitaryIdFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBBruneiMilitaryIdFrontRecognizerResult *result;

/**
* Defines if full name of Brunei Military ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFullName;

/**
* Defines if military rank of Brunei Military ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractRank;

@end

NS_ASSUME_NONNULL_END
