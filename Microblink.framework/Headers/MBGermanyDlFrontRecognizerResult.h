//
// MBGermanyDlFrontRecognizerResult.h
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
* Recognizer which can scan front side of Germany national DL cards
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of Germany DL owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of Germany DL.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The date of issue of Germany DL.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The first name of the Germany DL owner.
*/
@property (nonatomic, readonly) NSString *firstName;

/**
* The issuing authority of the Germany DL.
*/
@property (nonatomic, readonly) NSString *issuingAuthority;

/**
* The last name of the Germany DL owner.
*/
@property (nonatomic, readonly) NSString *lastName;

/**
* The licence categories of the Germany DL.
*/
@property (nonatomic, readonly) NSString *licenceCategories;

/**
* The licence number of the Germany DL.
*/
@property (nonatomic, readonly) NSString *licenceNumber;

/**
* The place of birth of Germany DL owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;


@end

NS_ASSUME_NONNULL_END
