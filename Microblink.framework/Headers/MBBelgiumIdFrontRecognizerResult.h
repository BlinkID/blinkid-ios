//
// MBBelgiumIdFrontRecognizerResult.h
//
// Created by juraskrlec on 13/08/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front side of Belgium national ID card.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBelgiumIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The card number of the Belgium ID card.
*/
@property (nonatomic, readonly) NSString *cardNumber;

@end

NS_ASSUME_NONNULL_END
