//
// MBSloveniaCombinedRecognizerResult.h
//
// Created by juraskrlec on 19/03/2019
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
* Recognizer which can scan front and back side of Slovenia national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSloveniaCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBDigitalSignatureResult, MBFaceImageResult, MBEncodedFaceImageResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of the Slovenia ID owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The administrative unit of the Slovenia ID card.
*/
@property (nonatomic, readonly) NSString *administrativeUnit;

/**
* The date of birth of the Slovenia ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of the Slovenia ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The date of issue of the Slovenia ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The document number of the Slovenia ID card.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The given names of the Slovenia ID owner.
*/
@property (nonatomic, readonly) NSString *givenNames;

/**
* Determines if all check digits inside MRZ are correct
*/
@property (nonatomic, readonly) BOOL mrzVerified;

/**
* The nationality of the Slovenia ID owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The pin of the Slovenia ID owner.
*/
@property (nonatomic, readonly) NSString *pin;

/**
* The sex of the Slovenia ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The surname of the Slovenia ID owner.
*/
@property (nonatomic, readonly) NSString *surname;

/**
 * Determines if date of expiry of Slovenian ID card is permanent.
 */
@property (nonatomic, readonly) BOOL dateOfExpiryPermanent;

@end

NS_ASSUME_NONNULL_END
