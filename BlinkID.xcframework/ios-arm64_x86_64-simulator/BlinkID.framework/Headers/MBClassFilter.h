// Created by Toni Krešo on 20.06.2024.. 
// Copyright (c) 2024 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBClassInfoTypes.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBClassFilter : NSObject

// TODO: ovo ide u private.h
- (instancetype)initWithNumbersCountry:(NSNumber *)country region:(NSNumber *)region type:(NSNumber *)type;

/**
 * Country that defines class of documents to be anonymized
 * @discusion: MBCountry wrapped in NSNumber
 */
@property (nonatomic, copy) NSNumber *country;

/**
 * Region that defines class of documents to be anonymized
 * @discusion: MBRegion wrapped in NSNumber
 */
@property (nonatomic, copy) NSNumber *region;

/**
 * Type that defines class of documents to be anonymized
 * @discusion: MBType wrapped in NSNumber
 */
@property (nonatomic, copy) NSNumber *type;

/**
 *  @param country MBCountry object
 *
 *  @param region MBRegion object
 *
 *  @param type MBType object
 *
 *  @return initialized ClassFilter
 */
- (instancetype)initWithCountry:(MBCountry)country region:(MBRegion)region type:(MBType)type;

/**
 *  @param country MBCountry object
 *
 *  @param region MBRegion object
 *
 *  @return initialized ClassFilter
 */
- (instancetype)initWithCountry:(MBCountry)country region:(MBRegion)region;

/**
 *  @param country MBCountry object
 *
 *  @param type MBType object
 *
 *  @return initialized ClassFilter
 */
- (instancetype)initWithCountry:(MBCountry)country type:(MBType)type;

/**
 *  @param region MBRegion object
 *
 *  @param type MBType object
 *
 *  @return initialized ClassFilter
 */
- (instancetype)initWithRegion:(MBRegion)region type:(MBType)type;

/**
 *  @param country MBCountry object
 *
 *  @return initialized ClassFilter
 */
- (instancetype)initWithCountry:(MBCountry)country;

/**
 *  @param region MBRegion object
 *
 *  @return initialized ClassFilter
 */
- (instancetype)initWithRegion:(MBRegion)region;

/**
 *  @param type MBType object
 *
 *  @return initialized ClassFilter
 */
- (instancetype)initWithType:(MBType)type;

/**
 *  @return initialized ClassFilter
 */
- (instancetype)init;

@end

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBClassFilterBuilder : NSObject

/**
 * Country that defines class of documents to be anonymized
 * @discusion: MBCountry wrapped in NSNumber
 */
@property (nonatomic, assign) NSNumber *country;

/**
 * Region that defines class of documents to be anonymized
 * @discusion: MBRegion wrapped in NSNumber
 */
@property (nonatomic, assign) NSNumber *region;

/**
 * Type that defines class of documents to be anonymized
 * @discusion: MBType wrapped in NSNumber
 */
@property (nonatomic, assign) NSNumber *type;

- (MBClassFilterBuilder *)withCountry:(MBCountry)country;
- (MBClassFilterBuilder *)withRegion:(MBRegion)region;
- (MBClassFilterBuilder *)withType:(MBType)type;
- (MBClassFilter *)build;

@end


NS_ASSUME_NONNULL_END
