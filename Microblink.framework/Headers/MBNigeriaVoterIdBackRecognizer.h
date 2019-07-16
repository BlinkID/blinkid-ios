//
// MBNigeriaVoterIdBackRecognizer.h
//
// Created by juraskrlec on 09/07/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBNigeriaVoterIdBackRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Nigeria voter ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBNigeriaVoterIdBackRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning NigeriaVoterIdBackRecognizer
 */
@property (nonatomic, strong, readonly) MBNigeriaVoterIdBackRecognizerResult *result;

@end

NS_ASSUME_NONNULL_END
