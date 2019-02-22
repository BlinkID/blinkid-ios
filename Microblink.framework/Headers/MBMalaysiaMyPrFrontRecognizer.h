//
// MBMalaysiaMyPrFrontRecognizer.h
//
// Created by juraskrlec on 17/12/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBMalaysiaMyPrFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Malaysian MyPR cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBMalaysiaMyPrFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning MalaysiaMyPrFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBMalaysiaMyPrFrontRecognizerResult *result;

/**
* Defines if full name and address of Malaysian MyPR owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFullNameAndAddress;

/**
* Defines if religion of Malaysian MyPR owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractReligion;

/**
* Defines if sex of Malaysian MyPR owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
