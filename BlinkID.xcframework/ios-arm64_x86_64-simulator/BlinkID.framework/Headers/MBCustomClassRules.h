// Created by Toni Krešo on 25.06.2024.. 
// Copyright (c) 2024 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBClassFilter.h"
#import "MBDetailedFieldType.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBCustomClassRules : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * Designated intializer.
 *
 *  @param classFilter MBClassFilter object
 *
 *  @param fields NSArray<MBDetailedFieldType *> object
 *
 *  @return initialized customClassRules
 */
- (instancetype)initWithClassFilter:(MBClassFilter *)classFilter fields:(NSArray<MBDetailedFieldType *> *)fields NS_DESIGNATED_INITIALIZER;

/**
* Specified fields will overrule our class field rules if filter conditions are met.
*/
@property (nonatomic, strong) MBClassFilter *classFilter;

/**
 * Fields to overrule our class field rules.
 */
@property (nonatomic, strong) NSArray<MBDetailedFieldType *> *fields;

@end

NS_ASSUME_NONNULL_END
