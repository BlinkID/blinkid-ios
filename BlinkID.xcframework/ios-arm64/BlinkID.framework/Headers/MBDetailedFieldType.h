// Created by Toni Krešo on 25.06.2024.. 
// Copyright (c) 2024 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBFieldType.h"
#import "MBStringResult.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBDetailedFieldType : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * Designated intializer.
 *
 *  @param fieldType MBFieldType case
 *
 *  @param alphabetType MBAlphabetType case
 *
 *  @return initialized detailedFieldType
 */
- (instancetype)initWithFieldType:(MBFieldType)fieldType alphabetType:(MBAlphabetType)alphabetType NS_DESIGNATED_INITIALIZER;


/**
 * Field type found on document.
 */
@property (nonatomic, assign) MBFieldType fieldType;

/**
 * Alphabet type of specified field type.
 */
@property (nonatomic, assign) MBAlphabetType alphabetType;

@end

NS_ASSUME_NONNULL_END
