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
#import "MBDocumentNumberAnonymizationSettings.h"
#import "MBClassFilter.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBClassAnonymizationSettings : NSObject

/**
 * Specified fields will be anonymized if filter conditions are met.
 */
@property (nonatomic, strong) MBClassFilter *classFilter;

/**
 * List of fields that will be anonymized on the document.
 * @discusion: List contains elements of type MBFieldType wrapped in NSNumber
 */
@property (nonatomic, strong) NSArray<NSNumber *> *fields;

/**
 * Settings that defines document numbers to be anonymized
 * @discusion: MBDocumentNumberAnonymizationSettings object
 */
@property (nonatomic, strong) MBDocumentNumberAnonymizationSettings *documentNumberAnonymizationSettings;

/**
 *  @param country MBCountry object
 *
 *  @param region MBRegion object
 *
 *  @param type MBType object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @param documentNumberAnonymizationSettings MBDocumentNumberAnonymizationSettings object
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithCountry:(MBCountry)country region:(MBRegion)region type:(MBType)type fields:(NSArray<NSNumber *> *)fields documentNumberAnonymizationSettings:(nullable MBDocumentNumberAnonymizationSettings *)documentNumberAnonymizationSettings;

/**
 *  @param country MBCountry object
 *
 *  @param region MBRegion object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @param documentNumberAnonymizationSettings MBDocumentNumberAnonymizationSettings object
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithCountry:(MBCountry)country region:(MBRegion)region fields:(NSArray<NSNumber *> *)fields documentNumberAnonymizationSettings:(nullable MBDocumentNumberAnonymizationSettings *)documentNumberAnonymizationSettings;

/**
 *  @param country MBCountry object
 *
 *  @param type MBType object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @param documentNumberAnonymizationSettings MBDocumentNumberAnonymizationSettings object
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithCountry:(MBCountry)country type:(MBType)type fields:(NSArray<NSNumber *> *)fields documentNumberAnonymizationSettings:(nullable MBDocumentNumberAnonymizationSettings *)documentNumberAnonymizationSettings;

/**
 *  @param region MBRegion object
 *
 *  @param type MBType object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @param documentNumberAnonymizationSettings MBDocumentNumberAnonymizationSettings object
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithRegion:(MBRegion)region type:(MBType)type fields:(NSArray<NSNumber *> *)fields documentNumberAnonymizationSettings:(nullable MBDocumentNumberAnonymizationSettings *)documentNumberAnonymizationSettings;

/**
 *  @param country MBCountry object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @param documentNumberAnonymizationSettings MBDocumentNumberAnonymizationSettings object
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithCountry:(MBCountry)country fields:(NSArray<NSNumber *> *)fields documentNumberAnonymizationSettings:(nullable MBDocumentNumberAnonymizationSettings *)documentNumberAnonymizationSettings;

/**
 *  @param region MBRegion object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @param documentNumberAnonymizationSettings MBDocumentNumberAnonymizationSettings object
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithRegion:(MBRegion)region fields:(NSArray<NSNumber *> *)fields documentNumberAnonymizationSettings:(nullable MBDocumentNumberAnonymizationSettings *)documentNumberAnonymizationSettings;

/**
 *  @param type MBType object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @param documentNumberAnonymizationSettings MBDocumentNumberAnonymizationSettings object
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithType:(MBType)type fields:(NSArray<NSNumber *> *)fields documentNumberAnonymizationSettings:(nullable MBDocumentNumberAnonymizationSettings *)documentNumberAnonymizationSettings;

/**
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @param documentNumberAnonymizationSettings MBDocumentNumberAnonymizationSettings object
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithFields:(NSArray<NSNumber *> *)fields documentNumberAnonymizationSettings:(nullable MBDocumentNumberAnonymizationSettings *)documentNumberAnonymizationSettings;

/**
 *  @param classFilter nullable MBClassFilter object
 *
 *  @param documentNumberAnonymizationSettings nullable MBDocumentNumberAnonymizationSettings object
 *
 *  @param fields NSArray of NSnumbers representing MBFieldType enum types
 *
 *  @return initialized classAnonymizationSettings
 */
- (instancetype)initWithClassFilter:(nullable MBClassFilter*)classFilter documentNumberAnonymizationSettings:(nullable MBDocumentNumberAnonymizationSettings *)documentNumberAnonymizationSettings fields:(NSArray<NSNumber *> *)fields;

@end

NS_ASSUME_NONNULL_END
