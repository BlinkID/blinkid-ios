//
// MBJordanIdBackRecognizer.h
//
// Created by juraskrlec on 18/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBJordanIdBackRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Jordan ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBJordanIdBackRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning JordanIdBackRecognizer
 */
@property (nonatomic, strong, readonly) MBJordanIdBackRecognizerResult *result;

/**
* Defines if full name of the Jordan ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFullName;

@end

NS_ASSUME_NONNULL_END
