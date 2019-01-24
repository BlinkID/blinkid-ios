//
// MBGermanyIdBackRecognizerResult.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBMrzResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of German ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The city of German ID owner.
*/
@property (nonatomic, readonly) NSString *addressCity;

/**
* The house number of German ID owner.
*/
@property (nonatomic, readonly) NSString *addressHouseNumber;

/**
* The street of German ID owner.
*/
@property (nonatomic, readonly) NSString *addressStreet;

/**
* The zip code of German ID owner.
*/
@property (nonatomic, readonly) NSString *addressZipCode;

/**
* The issuing authority of German ID.
*/
@property (nonatomic, readonly) NSString *authority;

/**
* The colour of eyes of German ID owner.
*/
@property (nonatomic, readonly) NSString *colourOfEyes MB_PROPERTY_DEPRECATED;

/**
* The date of issue of German ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The full address of German ID owner.
*/
@property (nonatomic, readonly) NSString *fullAddress;

/**
* The height of German ID owner.
*/
@property (nonatomic, readonly) NSString *height MB_PROPERTY_DEPRECATED;

/**
* The data extracted from the machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;


@end

NS_ASSUME_NONNULL_END
