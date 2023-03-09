//
//  MBDataMatchResult.h
//  BlinkShowcaseDev
//
// Copyright (c) 2022 Microblink Ltd. All rights reserved.
// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBDataMatchState.h"


typedef NS_ENUM(NSInteger, MBDataMatchField) {
    MBDataMatchFieldDateOfBirth = 0,
    MBDataMatchFieldDateOfExpiry,
    MBDataMatchFieldDocumentNumber
};

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBFieldState: NSObject

@property (nonatomic) MBDataMatchField field;
@property (nonatomic) MBDataMatchState state;

- (instancetype)initWithField:(MBDataMatchField)field state:(MBDataMatchState)state;
- (instancetype)init NS_UNAVAILABLE;

@end


MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBDataMatchResult : NSObject

/** States of the data match per field.  */
@property (nonatomic, readonly) NSArray<MBFieldState *> *states;

/** The state of the data match on the whole document. */
@property (nonatomic, readonly) MBDataMatchState stateForWholeDocument;

/**
 * The state of the data match on the specified field
 * For example if date of expiry is scanned from the front and back side
 * of the document and values do not match, this method will return {@link DataMatchResult#Failed}.
 * Result will be {@link DataMatchResult#Success} only if scanned values for all fields that are
 * compared are the same. If data matching has not been performed, result will be
 * {@link DataMatchResult#NotPerformed}.
 *
 * @return result of the data matching algorithm for scanned parts/sides of the document.
 */
- (MBDataMatchState)getStateForField:(MBDataMatchField)field;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
