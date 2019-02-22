//
// MBMalaysiaMyTenteraFrontRecognizer.h
//
// Created by juraskrlec on 13/11/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBMalaysiaMyTenteraFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Malaysian MyTentera cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBMalaysiaMyTenteraFrontRecognizer : MBRecognizer <NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning MalaysiaMyTenteraFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBMalaysiaMyTenteraFrontRecognizerResult *result;

/**
* Defines if full name and address of Malaysian MyTentera owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFullNameAndAddress;

/**
* Defines if religion of Malaysian MyTentera owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractReligion;


@end

NS_ASSUME_NONNULL_END