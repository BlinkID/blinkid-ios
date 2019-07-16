//
// MBSloveniaIdFrontRecognizerResult.h
//
// Created by juraskrlec on 19/03/2019
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
* Recognizer which can scan front side of Slovenia ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSloveniaIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of Slovenian ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of Slovenian ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The given names of Slovenian ID owner.
*/
@property (nonatomic, readonly) NSString *givenNames;

/**
* The nationality of Slovenian ID owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The sex of Slovenian ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The surname of Slovenian ID owner.
*/
@property (nonatomic, readonly) NSString *surname;

/**
 * Determines if date of expiry of Slovenian ID card is permanent.
 */
@property (nonatomic, readonly) BOOL dateOfExpiryPermanent;


@end

NS_ASSUME_NONNULL_END
