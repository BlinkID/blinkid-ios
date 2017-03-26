//
//  PPRegexOcrParserFactory.h
//  PhotoPayFramework
//
//  Created by Jura on 27/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"
#import "PPOcrEngineOptions.h"

/**
 * Customizable raw parser that is optimized for a given regex.
 * Regex engine does not support backreferences and doesn't have a defined alphabet (negations '[^...]'
 * and any character symbols '.' are not supported but strictly defined subsets such as digits '\d'
 * and alphanumerc characters '\w' and others are supported).
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPRegexOcrParserFactory : PPOcrParserFactory

/**
 * Initializes the parser factory with
 *
 *  @param regex regular expression pattern for extraction
 *
 *  @return initialized parser factory
 */
- (instancetype)initWithRegex:(NSString *)regex NS_DESIGNATED_INITIALIZER;

/**
 * Regex pattern for OCR extraction
 */
@property (nonatomic) NSString *regex;

/**
 * Use algorithm for combining consecutive OCR results between video frames
 *
 * Default: NO
 */
@property (nonatomic) BOOL useSieve;

/**
 * Denotes if regex engine is using greedy matching.
 *
 * Default: YES
 */
@property (nonatomic) BOOL useGreedyMatching;

/**
 * If set to true, regex will not be matched if there is no whitespace before matched string.
 *
 * Default: NO
 */
@property (nonatomic) BOOL startsWithWhitespace;

/**
 * If set to true, regex will not be matched if there is no whitespace after matched string.
 *
 * Default: NO
 */
@property (nonatomic) BOOL endsWithWhitespace;

/**
 * Sets desired options for a parser. Options enable various customizations of a parsers such as: allowed characters, character heigh, etc.
 *
 * This method also sets the alphabet of regex engine. By default alphabet is not set and regex engine will work on all characters.
 * By setting the alphabet any characters symbols '.' and negations '[^...]' will be enabled.
 *
 * Default: [[PPOcrEngineOptions alloc] init]
 */
- (void)setOptions:(PPOcrEngineOptions *)options;

@end
