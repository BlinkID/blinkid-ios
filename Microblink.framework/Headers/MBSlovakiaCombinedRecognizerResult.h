//
// MBSlovakiaCombinedRecognizerResult.h
//
// Created by juraskrlec on 18/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBCombinedRecognizerResult.h"
#import "MBDigitalSignatureResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBCombinedFullDocumentImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front and back side of Slovakia national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSlovakiaCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBDigitalSignatureResult, MBFaceImageResult, MBEncodedFaceImageResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *address;

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
* Determines if all check digits inside MRZ are correct
*/
@property (nonatomic, readonly) BOOL mrzVerified;

/**
* The nationality of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The personal number of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *personalNumber;

/**
* The place of birth of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
* The sex of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The special remarks of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *specialRemarks;

/**
* The surname at birth of the Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *surnameAtBirth;


@end

NS_ASSUME_NONNULL_END