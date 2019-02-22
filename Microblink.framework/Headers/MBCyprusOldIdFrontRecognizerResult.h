//
// MBCyprusOldIdFrontRecognizerResult.h
//
// Created by juraskrlec on 17/12/2018
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
* Recognizer which can scan front side of old Cyprus national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCyprusOldIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The document number of old Cyprus ID card.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The ID number of the old Cyprus ID card.
*/
@property (nonatomic, readonly) NSString *idNumber;

/**
* The name of old Cyprus ID card owner.
*/
@property (nonatomic, readonly) NSString *name;

/**
* The surname of old Cyprus ID card owner.
*/
@property (nonatomic, readonly) NSString *surname;

@end

NS_ASSUME_NONNULL_END
