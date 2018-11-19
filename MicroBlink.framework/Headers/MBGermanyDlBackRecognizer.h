//
// MBGermanyDlBackRecognizer.h
//
// Created by juraskrlec on 13/11/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBGermanyDlBackRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of German DL cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBGermanyDlBackRecognizer : MBRecognizer <NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning GermanyDlBackRecognizer
 */
@property (nonatomic, strong, readonly) MBGermanyDlBackRecognizerResult *result;


@end

NS_ASSUME_NONNULL_END