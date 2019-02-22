//
// MBPolandIdFrontRecognizerResult.h
//
// Created by jcular on 20/02/2019
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
* Recognizer which can scan front side of Poland ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBPolandIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of the Poland ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The family name of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *familyName MB_PROPERTY_DEPRECATED;

/**
* The given names of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *givenNames;

/**
* The parents given names of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *parentsGivenNames MB_PROPERTY_DEPRECATED;

/**
* The sex of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The surname of the Poland ID owner.
*/
@property (nonatomic, readonly) NSString *surname;

@end

NS_ASSUME_NONNULL_END
