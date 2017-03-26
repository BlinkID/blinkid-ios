//
//  PPOcrScanResult.h
//  PhotoPayFramework
//
//  Created by Jura on 18/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"
#import "PPOcrLayout.h"

/**
 * Result of scanning with OCR Recognizer
 *
 * For each parser group, the result contains one Ocr Layout, and one or more parsed results.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPTemplatingRecognizerResult : PPRecognizerResult

/**
 * If only default parser group is used, this method returns the OCR layout for this parser group
 *
 *  @return OCR layout for default parser group
 */
- (PPOcrLayout *_Nullable)ocrLayout;

/**
 * If only default parser group is used, this method returns parsed string from the default parser group
 *
 *  @param name name of the parser responsible for parsing the wanted string
 *
 *  @return parsed string
 */
- (NSString *_Nullable)parsedResultForName:(NSString *_Nonnull)name;

/**
 * If only default parser group is used, this method returns parsed object from the default parser group
 * For example, date parser represented with PPDateOcrParserFactory can return parsed date here as
 * NSDate object. It is always possible to obtain parsed result as raw string by using {@link parsedResultForName:}
 * method.
 *
 *  @param name name of the parser responsible for parsing the wanted string
 *
 *  @return parsed object
 */
- (NSObject *_Nullable)specificParsedResultForName:(NSString *_Nonnull)name;

/**
 * Retrieves OCR layout from arbitrary parser groups
 *
 *  @param parserGroup parser group name
 *
 *  @return OCR layout for given parser group
 */
- (PPOcrLayout *_Nullable)ocrLayoutForParserGroup:(NSString *_Nonnull)parserGroup;

/**
 *  Retrieves parsed string from given parser group
 *
 *  @param name        name of the parser responsible for parsing the wanted string
 *  @param parserGroup parser group name
 *
 *  @return parsed string
 */
- (NSString *_Nullable)parsedResultForName:(NSString *_Nonnull)name parserGroup:(NSString *_Nonnull)parserGroup;

/**
 *  Retrieves parsed object from given parser group
 *
 *  @param name        name of the parser responsible for parsing the wanted string
 *  @param parserGroup parser group name
 *
 *  @return parsed object
 */
- (NSObject *_Nullable)specificParsedResultForName:(NSString *_Nonnull)name parserGroup:(NSString *_Nonnull)parserGroup;

/**
 *  Retrieves raw parsed object from given parser group
 *
 *  @param name        name of the parser responsible for parsing the wanted string
 *  @param parserGroup parser group name
 *
 *  @return raw parsed object
 */
- (NSString *_Nullable)rawParsedResultForName:(NSString *_Nonnull)name parserGroup:(NSString *_Nonnull)parserGroup;

/**
 * Returns result of document classification, if any.
 * @return result of document classification, if any.
 */
- (NSString *_Nullable)documentClassification;

@end
