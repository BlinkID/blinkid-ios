//
// MBJordanIdBackRecognizerResult.h
//
// Created by juraskrlec on 18/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBMrzResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Jordan ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBJordanIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The full name of the Jordan ID owner.
*/
@property (nonatomic, readonly) NSString *fullName;

/**
* The data extracted from the machine readable zone.
*/
@property (nonatomic, readonly) MBMrzResult *mrzResult;


@end

NS_ASSUME_NONNULL_END
