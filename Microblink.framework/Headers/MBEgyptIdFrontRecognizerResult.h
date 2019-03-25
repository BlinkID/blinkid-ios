//
// MBEgyptIdFrontRecognizerResult.h
//
// Created by juraskrlec on 18/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front side of Egypt ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBEgyptIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The document number of Egypt ID.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The national number of Egypt ID.
*/
@property (nonatomic, readonly) NSString *nationalNumber;

@end

NS_ASSUME_NONNULL_END
