//
// MBJordanCombinedRecognizerResult.h
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
* Recognizer which can scan front and back side of Jordan national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBJordanCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBDigitalSignatureResult, MBFaceImageResult, MBEncodedFaceImageResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of the Jordan ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of the Jordan ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The document number of the Jordan ID card.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The issuing authority of the Jordan ID card.
*/
@property (nonatomic, readonly) NSString *issuedBy;

/**
* Determines if all check digits inside MRZ are correct
*/
@property (nonatomic, readonly) BOOL mrzVerified;

/**
* The name of the Jordan ID owner.
*/
@property (nonatomic, readonly) NSString *name;

/**
* The national number of the Jordan ID card.
*/
@property (nonatomic, readonly) NSString *nationalNumber;

/**
* The nationality of the Jordan ID owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The sex of the Jordan ID owner.
*/
@property (nonatomic, readonly) NSString *sex;


@end

NS_ASSUME_NONNULL_END