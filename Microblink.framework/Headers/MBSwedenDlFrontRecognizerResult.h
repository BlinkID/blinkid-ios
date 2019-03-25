//
// MBSwedenDlFrontRecognizerResult.h
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
#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front side of Sweden DL.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwedenDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of birth of Sweden DL owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of Sweden DL.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The date of issue of Sweden DL.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The issuing agency of Sweden DL.
*/
@property (nonatomic, readonly) NSString *issuingAgency;

/**
* The licence categories of Sweden DL.
*/
@property (nonatomic, readonly) NSString *licenceCategories;

/**
* The licence number of Sweden DL.
*/
@property (nonatomic, readonly) NSString *licenceNumber;

/**
* The name of Sweden DL owner.
*/
@property (nonatomic, readonly) NSString *name;

/**
* The reference number of Sweden DL.
*/
@property (nonatomic, readonly) NSString *referenceNumber MB_PROPERTY_DEPRECATED;

/**
* The surname of Sweden DL owner.
*/
@property (nonatomic, readonly) NSString *surname;


@end

NS_ASSUME_NONNULL_END
