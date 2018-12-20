//
// MBCyprusOldIdFrontRecognizer.h
//
// Created by juraskrlec on 17/12/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBCyprusOldIdFrontRecognizerResult.h"

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
* Recognizer which can scan front side of old Cyprus national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCyprusOldIdFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning CyprusOldIdFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBCyprusOldIdFrontRecognizerResult *result;

/**
* Defines if document number of old Cyprus ID card should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDocumentNumber;

/**
* Defines if name of old Cyprus ID card owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractName;

/**
* Defines if surname of old Cyprus ID card owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
