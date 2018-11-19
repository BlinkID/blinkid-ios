//
// MBGermanyIdFrontRecognizerResult.h
//
// Created by juraskrlec on 13/11/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front side of Germany national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The CAN number of Germany ID.
*/
@property (nonatomic, readonly) NSString *canNumber;

/**
* The date of birth of Germany ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of Germany ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The document number of Germany ID.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The given names of Germany ID owner.
*/
@property (nonatomic, readonly) NSString *givenNames;

/**
* The nationality of Germany ID owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The place of birth of Germany ID owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
* The surname of Germany ID owner.
*/
@property (nonatomic, readonly) NSString *surname;


@end

NS_ASSUME_NONNULL_END
