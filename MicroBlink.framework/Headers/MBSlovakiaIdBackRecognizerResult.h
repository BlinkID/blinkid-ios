//
// MBSlovakiaIdBackRecognizerResult.h
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
* Recognizer which can scan back side of Slovak ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSlovakiaIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The data extracted from the machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
* The place of birth of Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
* The special remarks of Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *specialRemarks MB_PROPERTY_DEPRECATED;

/**
* The surname at birth of Slovak ID owner.
*/
@property (nonatomic, readonly) NSString *surnameAtBirth MB_PROPERTY_DEPRECATED;

@end

NS_ASSUME_NONNULL_END
