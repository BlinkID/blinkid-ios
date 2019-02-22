//
// MBSwitzerlandIdBackRecognizerResult.h
//
// Created by juraskrlec on 17/12/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBMrzResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Switzerland ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwitzerlandIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The issuing authority of Switzerland ID.
*/
@property (nonatomic, readonly) NSString *authority;

/**
* The date of expiry of Switzerland ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The date of issue of Switzerland ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The height of Switzerland ID owner.
*/
@property (nonatomic, readonly) NSString *height MB_PROPERTY_DEPRECATED;

/**
* The data extracted from the machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
* The place of origin of Switzerland ID owner.
*/
@property (nonatomic, readonly) NSString *placeOfOrigin;

/**
* The sex of Switzerland ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

@end

NS_ASSUME_NONNULL_END
