//
// MBBruneiTemporaryResidencePermitBackRecognizerResult.h
//
// Created by jcular on 20/02/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBMrzResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Brunei temporary residence permit cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBruneiTemporaryResidencePermitBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of Brunei temporary residence permit owner's employer.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The date of issue of Brunei temporary residence permit.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The data extracted from the machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
* The passport number of Brunei temporary residence permit owner.
*/
@property (nonatomic, readonly) NSString *passportNumber;

@end

NS_ASSUME_NONNULL_END
