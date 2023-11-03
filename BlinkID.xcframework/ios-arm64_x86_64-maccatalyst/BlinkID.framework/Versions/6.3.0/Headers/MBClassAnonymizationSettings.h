// Created by Toni Krešo on 04.05.2023.. 
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

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
@interface MBClassAnonymizationSettings : NSObject

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

/**
 * List of fields that will be anonymized on the document.
 * @discusion: List contains elements of type MBFieldType wrapped in NSNumber
 */
@property (nonatomic, strong) NSArray<NSNumber *> *fields;

/**
 *  @param country MBCountry object
 *
 *  @param region MBRegion object
 *
 *  @param type MBType object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithCountry:(MBCountry)country region:(MBRegion)region type:(MBType)type fields:(NSArray<NSNumber *> *)fields;

/**
 *  @param country MBCountry object
 *
 *  @param region MBRegion object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithCountry:(MBCountry)country region:(MBRegion)region fields:(NSArray<NSNumber *> *)fields;

/**
 *  @param country MBCountry object
 *
 *  @param type MBType object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithCountry:(MBCountry)country type:(MBType)type fields:(NSArray<NSNumber *> *)fields;

/**
 *  @param region MBRegion object
 *
 *  @param type MBType object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithRegion:(MBRegion)region type:(MBType)type fields:(NSArray<NSNumber *> *)fields;

/**
 *  @param country MBCountry object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithCountry:(MBCountry)country fields:(NSArray<NSNumber *> *)fields;

/**
 *  @param region MBRegion object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithRegion:(MBRegion)region fields:(NSArray<NSNumber *> *)fields;

/**
 *  @param type MBType object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithType:(MBType)type fields:(NSArray<NSNumber *> *)fields;

/**
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithFields:(NSArray<NSNumber *> *)fields;

@end

NS_ASSUME_NONNULL_END
