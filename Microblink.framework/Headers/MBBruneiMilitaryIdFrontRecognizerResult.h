//
// MBBruneiMilitaryIdFrontRecognizerResult.h
//
// Created by juraskrlec on 20/03/2019
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
* Recognizer which can scan front side of Brunei Military ID card.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBruneiMilitaryIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of Brunei Military ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The full name of Brunei Military ID owner.
*/
@property (nonatomic, readonly) NSString *fullName;

/**
* The military rank of Brunei Military ID owner.
*/
@property (nonatomic, readonly) NSString *rank;

@end

NS_ASSUME_NONNULL_END
