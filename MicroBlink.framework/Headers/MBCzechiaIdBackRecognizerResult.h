//
// MBCzechiaIdBackRecognizerResult.h
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
* Recognizer which can scan the back side of Czech IDs.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCzechiaIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The Czech ID's issuing authority.
*/
@property (nonatomic, readonly) NSString *authority;

/**
* The data extracted from Czech ID's machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
* The Czech ID owner's permanent address.
*/
@property (nonatomic, readonly) NSString *permanentStay;

/**
* The Czech ID owner's personal number.
*/
@property (nonatomic, readonly) NSString *personalNumber;

@end

NS_ASSUME_NONNULL_END
