//
// MBVisaRecognizerResult.h
//
// Created by juraskrlec on 13/08/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBMrzResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan all visas with MRZ.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBVisaRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The data extracted from the machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;

@end

NS_ASSUME_NONNULL_END
