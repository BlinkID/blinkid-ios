//
// MBMalaysiaIKadFrontRecognizerResult.h
//
// Created by juraskrlec on 17/12/2018
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
* Recognizer which can scan front side of Malaysia iKad card.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMalaysiaIkadFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* Address of Malaysian iKad owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The date of birth of Malaysian iKad owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* Date of expiry of Malaysian iKad card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* Employer of Malaysian iKad owner.
*/
@property (nonatomic, readonly) NSString *employer;

/**
* Faculty address in which Malaysian iKad owner currently studies.
*/
@property (nonatomic, readonly) NSString *facultyAddress;

/**
* Gender of Malaysian iKad owner.
*/
@property (nonatomic, readonly) NSString *gender;

/**
* The name of Malaysian iKad owner.
*/
@property (nonatomic, readonly) NSString *name;

/**
* Nationality of Malaysian iKad owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The passport number of Malaysian iKad owners passport.
*/
@property (nonatomic, readonly) NSString *passportNumber;

/**
* Sector in which Malaysian iKad owner works.
*/
@property (nonatomic, readonly) NSString *sector;

@end

NS_ASSUME_NONNULL_END
