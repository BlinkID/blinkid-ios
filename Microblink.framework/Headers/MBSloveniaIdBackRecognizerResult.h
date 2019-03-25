//
// MBSloveniaIdBackRecognizerResult.h
//
// Created by juraskrlec on 19/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBMrzResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Slovenia ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSloveniaIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of Slovenian ID owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The issuing administrative unit of Slovenian ID.
*/
@property (nonatomic, readonly) NSString *administrativeUnit;

/**
* The date of issue of Slovenian ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The data extracted from the machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;

@end

NS_ASSUME_NONNULL_END
