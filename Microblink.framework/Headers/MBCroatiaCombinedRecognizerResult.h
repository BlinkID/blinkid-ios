//
// MBCroatiaCombinedRecognizerResult.h
//
// Created by juraskrlec on 18/01/2019
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
* Recognizer which can front and back side of Croatian national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCroatiaCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBDigitalSignatureResult, MBFaceImageResult, MBEncodedFaceImageResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The citizenship of the Croatian ID owner.
*/
@property (nonatomic, readonly) NSString *citizenship;

/**
* The date of birth of the Croatian ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of the Croatian ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* Determines if date of expiry of the Croatian ID is permanent.
*/
@property (nonatomic, readonly) BOOL dateOfExpiryPermanent;

/**
* The date of issue of Croatian ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* Determines if Croatian ID is bilingual.
*/
@property (nonatomic, readonly) BOOL documentBilingual;

/**
* Determines if Croatian ID is issued for non resident.
*/
@property (nonatomic, readonly) BOOL documentForNonResident;

/**
* The document number of the Croatian ID.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The first name of the Croatian ID owner.
*/
@property (nonatomic, readonly) NSString *firstName;

/**
* The issuer of Croatian ID.
*/
@property (nonatomic, readonly) NSString *issuedBy;

/**
* The last name of the Croatian ID owner.
*/
@property (nonatomic, readonly) NSString *lastName;

/**
* Determines if all check digits inside MRZ are correct.
*/
@property (nonatomic, readonly) BOOL mrzVerified;

/**
* The OIB of Croatian ID owner.
*/
@property (nonatomic, readonly) NSString *oib;

/**
* The residence of Croatian ID owner.
*/
@property (nonatomic, readonly) NSString *residence;

/**
* The sex of the Croatian ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

@end

NS_ASSUME_NONNULL_END
