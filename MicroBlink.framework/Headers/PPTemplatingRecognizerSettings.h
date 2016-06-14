//
//  PPTemplatingRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Dino on 18/05/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"
#import "PPOcrParserFactory.h"
#import "PPDecodingInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for Templating API and general OCR recognition.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPTemplatingRecognizerSettings : PPRecognizerSettings

@property (nonatomic) BOOL allowUnparsedResults;

/**
 * Adds OCR parser. Parser results will be fetched by parser name.
 *
 * Parsers added this way are added to default group.
 */
- (void)addOcrParser:(PPOcrParserFactory *)factory name:(NSString *)name;

/**
 * Adds OCR parser to group. Parser results will be fetched by parser name and group. 
 * Adding more parsers to same group will result in changing character whitelist of parsers but will also slightly increase performance 
 * since only one recognition will be done on the same image.
 *
 * It is advised to keep similar parsers (i.e. first and last name parsers) in same groups
 * and parsers with different character sets in different groups (i.e. amount parser and email parser).
 *
 * If using Templating API, parser groups also denote which parsers will be used for specific PPDecodingInfo (group name and uniqueId have to be same).
 */
- (void)addOcrParser:(PPOcrParserFactory *)factory
                name:(NSString *)name
               group:(NSString *)group;

/**
 * Removes parser with given name.
 */
- (void)removeOcrParserWithName:(NSString *)name;

/**
 * Removes parser with given name from group.
 */
- (void)removeOcrParserWithName:(NSString *)parser fromGroup:(NSString *)group;

/**
 * Removes all parsers from a given group.
 */
- (void)clearParsersInGroup:(NSString *)group;

/**
 * Removes all present parsers.
 */
- (void)clearAllParsers;

/**
 * Sets array of PPDecodingInfo to be used when PPDocumentClassifer outputs a selected result.
 */
- (void)setDecodingInfoSet:(NSArray<PPDecodingInfo*> *)decodingInfos forClassifierResult:(NSString *)classifierResult;

/**
 * Removes all decoding infos for a given classifier result.
 */
- (void)removeDecodingInfoSetForClassifierResult:(NSString *)classifierResult;

/**
 * Removes all present decoding info
 */
- (void)removeAllDecodingInfoSets;

@end

NS_ASSUME_NONNULL_END
