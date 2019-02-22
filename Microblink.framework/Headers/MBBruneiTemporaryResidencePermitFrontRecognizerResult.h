//
// MBBruneiTemporaryResidencePermitFrontRecognizerResult.h
//
// Created by jcular on 21/02/2019
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
* Recognizer which can scan front side of Brunei Temporary Residence Permit.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBruneiTemporaryResidencePermitFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of Brunei Temporary Residence Permit owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The date of birth of Brunei Temporary Residence Permit owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The document number of Brunei Temporary Residence Permit.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The full name of Brunei Temporary Residence Permit owner.
*/
@property (nonatomic, readonly) NSString *fullName;

/**
* The place of birth of Brunei Temporary Residence Permit owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
* The sex of Brunei Temporary Residence Permit owner.
*/
@property (nonatomic, readonly) NSString *sex;

@end

NS_ASSUME_NONNULL_END
