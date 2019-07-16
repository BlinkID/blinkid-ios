//
// MBRomaniaIdFrontRecognizerResult.h
//
// Created by juraskrlec on 18/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBMrzResult.h"
#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front side of Romania ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBRomaniaIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of Romania ID owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The date of expiry of Romania ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The date of issue of Romania ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The first name of Romania ID owner.
*/
@property (nonatomic, readonly) NSString *firstName;

/**
* The issuing authority of Romania ID.
*/
@property (nonatomic, readonly) NSString *issuedBy;

/**
* The data extracted from the machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
* The nationality of Romania ID owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The parent name of Romania ID owner.
*/
@property (nonatomic, readonly) NSString *parentName MB_PROPERTY_DEPRECATED;

/**
* The place of birth of Romania ID owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
* The sex of Romania ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The surname of Romania ID owner.
*/
@property (nonatomic, readonly) NSString *surname;

/**
 * The CNP number of Romania ID owner.
 */
@property (nonatomic, readonly) NSString *cnpNumber;

@end

NS_ASSUME_NONNULL_END
