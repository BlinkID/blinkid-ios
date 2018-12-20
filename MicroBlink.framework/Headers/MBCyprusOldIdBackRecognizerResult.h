//
// MBCyprusOldIdBackRecognizerResult.h
//
// Created by juraskrlec on 17/12/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of old Cyprus national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCyprusOldIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of the old Cyprus ID card owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The expiry date of old Cyprus ID card.
*/
@property (nonatomic, readonly) MBDateResult *expiresOn;

/**
* The sex of the old Cyprus ID card owner.
*/
@property (nonatomic, readonly) NSString *sex;

@end

NS_ASSUME_NONNULL_END
