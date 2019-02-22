//
// MBBruneiIdBackRecognizerResult.h
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
* Recognizer which can scan back side of Brunei national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBruneiIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of Brunei ID owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The date of issue of Brunei ID.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The data extracted from the machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
* The race of Brunei ID owner.
*/
@property (nonatomic, readonly) NSString *race;

@end

NS_ASSUME_NONNULL_END