//
//  PPOcrScanResult.h
//  PhotoPayFramework
//
//  Created by Jura on 18/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"
#import "PPOcrLayout.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Result of scanning with OCR Recognizer
 *
 * For each parser group, the result contains one Ocr Layout, and one or more parsed results.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPTemplatingRecognizerResult : PPRecognizerResult

/**
 * If only default parser group is used, this method returns the OCR layout for this parser group
 *
 *  @return OCR layout for default parser group
 */
- (PPOcrLayout *)ocrLayout;

/**
 * If only default parser group is used, this method returns parsed string from the defaul parser group
 *
 *  @param name name of the parser responsible for parsing the wanted string
 *
 *  @return parsed string
 */
- (NSString *)parsedResultForName:(NSString*)name;

/**
 * Retrieves OCR layout from arbitrary parser groups
 *
 *  @param parserGroup parser group name
 *
 *  @return OCR layout for given parser group
 */
- (PPOcrLayout *)ocrLayoutForParserGroup:(NSString*)parserGroup;

/**
 *  Retrieves parsed string from given parser group
 *
 *  @param name        name of the parser responsible for parsing the wanted string
 *  @param parserGroup parser group name
 *
 *  @return parsed string
 */
- (NSString *)parsedResultForName:(NSString*)name parserGroup:(NSString*)parserGroup;

@end

NS_ASSUME_NONNULL_END