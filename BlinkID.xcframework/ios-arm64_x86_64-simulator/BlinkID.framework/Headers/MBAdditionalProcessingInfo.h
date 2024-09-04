//
//  MBAdditionalProcessingInfo.h
//  BlinkIDDev
//
// Copyright (c) 2022 Microblink Ltd. All rights reserved.
// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#ifndef MBAdditionalProcessingInfo__h
#define MBAdditionalProcessingInfo__h

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * MBVizResult contains data extracted from the Visual Inspection Zone.
 */
MB_CLASS_AVAILABLE_IOS(13.0) MB_FINAL
@interface MBAdditionalProcessingInfo : NSObject

/**
 * List of fields that were expected on the document but were missing.
 * @discusion: List contains elements of type MBFieldType wrapped in NSNumber
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *missingMandatoryFields;

/**
 * List of fields that contained characters which were not expected in that field.
 * @discusion: List contains elements of type MBFieldType wrapped in NSNumber
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *invalidCharacterFields;

/**
 * List of fields that weren't expected on the document but were present.
 * @discusion: List contains elements of type MBFieldType wrapped in NSNumber
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *extraPresentFields;

/**
 * List of fields that weren't expected on the document but were present.
 * @discusion: List contains elements of type MBImageExtractionType wrapped in NSNumber
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *imageExtractionFailures;

@end

NS_ASSUME_NONNULL_END

#endif /* MBAdditionalProcessingInfo__h */
