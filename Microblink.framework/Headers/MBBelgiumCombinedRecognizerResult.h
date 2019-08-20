//
// MBBelgiumCombinedRecognizerResult.h
//
// Created by juraskrlec on 13/08/2019
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
* Recognizer which can scan front and back side of Belgium national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBelgiumCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBDigitalSignatureResult, MBFaceImageResult, MBEncodedFaceImageResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The card number of the Belgium ID card.
*/
@property (nonatomic, readonly) NSString *cardNumber;

/**
* The date of birth of the Belgium ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of the Belgium ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The first name of the Belgium ID owner.
*/
@property (nonatomic, readonly) NSString *firstName;

/**
* The issuing authority of the Belgium ID card.
*/
@property (nonatomic, readonly) NSString *issuedBy;

/**
* The last name of the Belgium ID owner.
*/
@property (nonatomic, readonly) NSString *lastName;

/**
* Determines if all check digits inside MRZ are correct.
*/
@property (nonatomic, readonly) BOOL mrzVerified;

/**
* The nationality of the Belgium ID owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The sex of the Belgium ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

@end

NS_ASSUME_NONNULL_END
