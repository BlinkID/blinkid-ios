//
// MBCzechiaIdFrontRecognizerResult.h
//
// Created by juraskrlec on 21/01/2019
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
* Recognizer which can scan the front side of Czech IDs.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCzechiaIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of Czech ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of Czech ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The date of issue of Czech ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The document number of Czech ID.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The given names of Czech ID owner.
*/
@property (nonatomic, readonly) NSString *givenNames;

/**
* The place of birth of Czech ID owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
* The sex of Czech ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The surname of Czech ID owner.
*/
@property (nonatomic, readonly) NSString *surname;


@end

NS_ASSUME_NONNULL_END
