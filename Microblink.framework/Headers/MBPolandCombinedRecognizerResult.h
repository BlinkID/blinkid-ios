//
// MBPolandCombinedRecognizerResult.h
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

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front and back side of Poland national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBPolandCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBDigitalSignatureResult, MBFaceImageResult, MBEncodedFaceImageResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of the Poland ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of the Poland ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The document number of the Poland ID card.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The family name of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *familyName;

/**
* The given names of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *givenNames;

/**
* The issuing authority of the Poland ID card.
*/
@property (nonatomic, readonly) NSString *issuedBy;

/**
* Determines if all check digits inside MRZ are correct
*/
@property (nonatomic, readonly) BOOL mrzVerified;

/**
* The nationality of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The parents given names of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *parentsGivenNames;

/**
* The personal number of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *personalNumber;

/**
* The sex of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The surname of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *surname;


@end

NS_ASSUME_NONNULL_END