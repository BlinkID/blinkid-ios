//
// MBBruneiIdYellowFrontRecognizerResult.h
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
* Recognizer which can scan front side of yellow version of Brunei ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBruneiIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of Brunei ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The document number of Brunei ID.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The full name of Brunei ID owner.
*/
@property (nonatomic, readonly) NSString *fullName;

/**
* The place of birth of Brunei ID owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
* The sex of Brunei ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

@end

NS_ASSUME_NONNULL_END