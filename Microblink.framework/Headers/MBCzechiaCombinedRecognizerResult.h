//
// MBCzechiaCombinedRecognizerResult.h
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
* Recognizer which can scan front and back side of Czechia national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCzechiaCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBDigitalSignatureResult, MBFaceImageResult, MBEncodedFaceImageResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The issuing authority of the Czechia ID card.
*/
@property (nonatomic, readonly) NSString *authority;

/**
* The date of birth of the Czechia ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of the Czechia ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The date of issue of the Czechia ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The document number of the Czechia ID card.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The given names of the Czechia ID owner.
*/
@property (nonatomic, readonly) NSString *givenNames;

/**
* Determines if all check digits inside MRZ are correct
*/
@property (nonatomic, readonly) BOOL mrzVerified;

/**
* The nationality of the Czechia ID owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The permanent stay address of the Czechia ID owner.
*/
@property (nonatomic, readonly) NSString *permanentStay;

/**
* The personal number of the Czechia ID owner.
*/
@property (nonatomic, readonly) NSString *personalNumber;

/**
* The place of birth of the Czechia ID owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
* The sex of the Czechia ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The surname of the Czechia ID owner.
*/
@property (nonatomic, readonly) NSString *surname;


@end

NS_ASSUME_NONNULL_END