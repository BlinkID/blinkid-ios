//
// MBSlovakiaIdFrontRecognizerResult.h
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
* Recognizer which can scan front side of Slovak national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSlovakiaIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of the Slovak ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of the Slovak ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The date of issue of the Slovak ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The document number of the Slovak ID card.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The first name of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *firstName;

/**
* The issuing authority of the Slovak ID card.
*/
@property (nonatomic, readonly) NSString *issuedBy;

/**
* The last name of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *lastName;

/**
* The nationality of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The personal number of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *personalNumber;

/**
* The sex of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

@end

NS_ASSUME_NONNULL_END
