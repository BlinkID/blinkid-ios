//
// MBSwitzerlandPassportRecognizerResult.h
//
// Created by juraskrlec on 17/12/2018
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
* Recognizer which can scan Switzerland passport.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwitzerlandPassportRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The issuing authority of Switzerland passport.
*/
@property (nonatomic, readonly) NSString *authority;

/**
* The date of birth of Switzerland passport owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of Switzerland passport.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The date of issue of Switzerland passport.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The given name of Switzerland passport owner.
*/
@property (nonatomic, readonly) NSString *givenName;

/**
* The height of Switzerland passport owner.
*/
@property (nonatomic, readonly) NSString *height MB_PROPERTY_DEPRECATED;

/**
* The data extracted from the machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
* The passport number of Switzerland passport.
*/
@property (nonatomic, readonly) NSString *passportNumber;

/**
* The place of origin of Switzerland passport owner.
*/
@property (nonatomic, readonly) NSString *placeOfOrigin;

/**
* The sex of Switzerland passport owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The surname of Switzerland passport owner.
*/
@property (nonatomic, readonly) NSString *surname;

@end

NS_ASSUME_NONNULL_END
