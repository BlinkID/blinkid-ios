//
// MBAustraliaDlFrontRecognizerResult.h
//
// Created by juraskrlec on 21/01/2019
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
* Recognizer which can scan the front side of Australian driver's licences.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustraliaDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of the Australian DL owner
*/
@property (nonatomic, readonly) NSString *address;

/**
* The date of birth of the Australian DL owner
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The full name of the Australian DL owner
*/
@property (nonatomic, readonly) NSString *fullName;

/**
* The date of expiry of the Australian DL
*/
@property (nonatomic, readonly) MBDateResult *licenceExpiry;

/**
* The licence number of the Australian DL
*/
@property (nonatomic, readonly) NSString *licenceNumber;

/**
* The licence type of the Australian DL
*/
@property (nonatomic, readonly) NSString *licenceType;

@end

NS_ASSUME_NONNULL_END
