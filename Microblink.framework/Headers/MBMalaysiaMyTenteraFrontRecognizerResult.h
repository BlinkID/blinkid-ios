//
// MBMalaysiaMyTenteraFrontRecognizerResult.h
//
// Created by juraskrlec on 13/11/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front side of Malaysian MyTentera cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMalaysiaMyTenteraFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The army number of Malaysian MyTentera owner.
*/
@property (nonatomic, readonly) NSString *armyNumber;

/**
* The birth date of Malaysian MyTentera owner.
*/
@property (nonatomic, readonly) MBDateResult *birthDate;

/**
* The city of Malaysian MyTentera owner.
*/
@property (nonatomic, readonly) NSString *city;

/**
* The address of Malaysian MyTentera owner.
*/
@property (nonatomic, readonly) NSString *fullAddress;

/**
* The full name of Malaysian MyTentera owner.
*/
@property (nonatomic, readonly) NSString *fullName;

/**
* The nric of Malaysian MyTentera.
*/
@property (nonatomic, readonly) NSString *nric;

/**
* The state of Malaysian MyTentera owner.
*/
@property (nonatomic, readonly) NSString *ownerState;

/**
* The religion of Malaysian MyTentera owner.
*/
@property (nonatomic, readonly) NSString *religion;

/**
* The sex of Malaysian MyTentera owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The street of Malaysian MyTentera owner.
*/
@property (nonatomic, readonly) NSString *street;

/**
* The zipcode of Malaysian MyTentera owner.
*/
@property (nonatomic, readonly) NSString *zipcode;


@end

NS_ASSUME_NONNULL_END
