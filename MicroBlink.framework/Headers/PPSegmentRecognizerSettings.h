//
//  PPSegmentRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 03/08/2017.
//
//

#import "PPRecognizerSettings.h"
#import "PPOcrParserFactory.h"
#import "PPDecodingInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for Segment API and general OCR recognition.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSegmentRecognizerSettings : PPRecognizerSettings

/**
 * Adds OCR parser. Parser results will be fetched by parser name.
 *
 * Parsers added this way are added to default group.
 *
 *  @param factory Parser to be added
 *  @param name    ID of the parser to be added. Output of this parser can be fetched by this name
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
 * If using Templating API, parser groups also denote which parsers will be used for specific PPDecodingInfo (group name and uniqueId have
 * to be same).
 *
 *  @param factory Parser to be added
 *  @param name    Name/ID of the parser to be added. Output of this parser can be fetched by this name
 *  @param group   Group name/ID of the parser to be added
 */
- (void)addOcrParser:(PPOcrParserFactory *)factory name:(NSString *)name group:(NSString *)group;

/**
 * Removes parser with given name.
 *
 *  @param name Name/ID of the parser to be removed
 */
- (void)removeOcrParserWithName:(NSString *)name;

/**
 * Removes parser with given name from group.
 *
 *  @param parser  Name/ID of the parser to be removed
 *  @param group Group name/ID of the parser to be removed
 */
- (void)removeOcrParserWithName:(NSString *)parser fromGroup:(NSString *)group;

/**
 * Removes all parsers from a given group.
 *
 *  @param group name/ID in which all parsers will be removed
 */
- (void)clearParsersInGroup:(NSString *)group;

/**
 * Removes all present parsers.
 */
- (void)clearAllParsers;

@end

NS_ASSUME_NONNULL_END
