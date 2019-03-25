//
// MBBruneiMilitaryIdBackRecognizerResult.h
//
// Created by juraskrlec on 20/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Brunei Military ID card.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBruneiMilitaryIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The army number of Brunei Military ID owner.
*/
@property (nonatomic, readonly) NSString *armyNumber;

/**
* The date of expiry of Brunei Military ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The date of issue of Brunei Military ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

@end

NS_ASSUME_NONNULL_END
