//
// MBSwitzerlandIdFrontRecognizerResult.h
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
* Recognizer which can scan front side of Switzerland ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwitzerlandIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of Switzerland ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The given name of Switzerland ID owner.
*/
@property (nonatomic, readonly) NSString *givenName;

/**
* The surname of Switzerland ID owner.
*/
@property (nonatomic, readonly) NSString *surname;


@end

NS_ASSUME_NONNULL_END
