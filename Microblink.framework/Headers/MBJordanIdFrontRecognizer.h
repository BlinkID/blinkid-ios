//
// MBJordanIdFrontRecognizer.h
//
// Created by juraskrlec on 18/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBJordanIdFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Jordan national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBJordanIdFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning JordanIdFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBJordanIdFrontRecognizerResult *result;

/**
* Defines if date of birth of Jordan ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
* Defines if name of Jordan ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractName;

/**
* Defines if sex of Jordan ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
