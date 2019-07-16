//
// MBNigeriaVoterIdBackRecognizerResult.h
//
// Created by juraskrlec on 09/07/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Nigeria voter ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBNigeriaVoterIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of Nigeria Voter ID owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The date of birth of Nigeria Voter ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The first name of Nigeria Voter ID owner.
*/
@property (nonatomic, readonly) NSString *firstName;

/**
* The raw barcode data of Nigeria Voter ID card.
*/
@property (nonatomic, readonly) NSString *rawBarcodeData;

/**
* The sex of Nigeria Voter ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The surname of Nigeria Voter ID owner.
*/
@property (nonatomic, readonly) NSString *surname;

@end

NS_ASSUME_NONNULL_END
