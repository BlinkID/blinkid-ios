//
// MBJordanIdFrontRecognizerResult.h
//
// Created by juraskrlec on 18/03/2019
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
* Recognizer which can scan front side of Jordan national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBJordanIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of the Jordan ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The name of the Jordan ID owner.
*/
@property (nonatomic, readonly) NSString *name;

/**
* The national number of the Jordan ID.
*/
@property (nonatomic, readonly) NSString *nationalNumber;

/**
* The sex of the Jordan ID owner.
*/
@property (nonatomic, readonly) NSString *sex;


@end

NS_ASSUME_NONNULL_END