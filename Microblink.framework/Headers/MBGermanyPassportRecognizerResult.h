//
// MBGermanyPassportRecognizerResult.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBMrzResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan German passport.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyPassportRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The issuing authority of German passport.
*/
@property (nonatomic, readonly) NSString *authority;

/**
* The date of issue of German passport.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The given name of German passport owner.
*/
@property (nonatomic, readonly) NSString *givenName;

/**
* The data extracted from the machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
* The nationality of German passport owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The place of birth of German passport owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
* The surname of German passport owner.
*/
@property (nonatomic, readonly) NSString *surname;

@end

NS_ASSUME_NONNULL_END
