//
// MBAustraliaDlBackRecognizerResult.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"


#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan the back side of Australian driver's licences
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustraliaDlBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of the Australia DL owner
*/
@property (nonatomic, readonly) NSString *address;

/**
* The last name of the Australia DL owner
*/
@property (nonatomic, readonly) NSString *lastName;

/**
* The date of expiry of the Australia DL
*/
@property (nonatomic, readonly) MBDateResult *licenceExpiry;

/**
* The licence number of the Australia DL
*/
@property (nonatomic, readonly) NSString *licenceNumber;

@end

NS_ASSUME_NONNULL_END
