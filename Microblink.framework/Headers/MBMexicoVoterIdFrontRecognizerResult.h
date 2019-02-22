//
// MBMexicoVoterIdFrontRecognizerResult.h
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
#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front side of Mexican voter id.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMexicoVoterIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of Mexico Voter ID owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The CURP of Mexico Voter ID owner.
*/
@property (nonatomic, readonly) NSString *curp;

/**
* The date of birth of Mexico Voter ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The elector key of Mexico Voter ID owner.
*/
@property (nonatomic, readonly) NSString *electorKey MB_PROPERTY_DEPRECATED;

/**
* The full name of Mexico Voter ID owner.
*/
@property (nonatomic, readonly) NSString *fullName;

/**
* The sex of Mexico Voter ID owner.
*/
@property (nonatomic, readonly) NSString *sex;


@end

NS_ASSUME_NONNULL_END
