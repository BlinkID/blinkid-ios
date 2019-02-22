//
// MBGermanyDlBackRecognizerResult.h
//
// Created by juraskrlec on 13/11/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of German DL cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyDlBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The date of issue for B category of German DL card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssueB10;

/**
* The date of issue for B category of German DL card is not specified.
*/
@property (nonatomic, readonly) BOOL dateOfIssueB10NotSpecified;


@end

NS_ASSUME_NONNULL_END
