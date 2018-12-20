//
// MBMalaysiaMyKasFrontRecognizer.h
//
// Created by juraskrlec on 17/12/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBMalaysiaMyKasFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Malaysian MyKAS cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBMalaysiaMyKasFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning MalaysiaMyKasFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBMalaysiaMyKasFrontRecognizerResult *result;

/**
* Defines if full name and address of Malaysian MyKAS owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFullNameAndAddress;

/**
* Defines if religion of Malaysian MyKAS owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractReligion;

/**
* Defines if sex of Malaysian MyKAS owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
