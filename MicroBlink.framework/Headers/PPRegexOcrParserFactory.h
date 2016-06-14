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
 * Regex engine does not support backreferences and doesn't have an alphabet (negations '[^...]'
 * and any character symbols '.' are not supported but strictly defined subsets such as digits '\d'
 * and alphanumerc characters '\w' and others are supported).
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPRegexOcrParserFactory : PPOcrParserFactory

/**
 * Initializes the parser factory with
 *
 *  @param regex regular expression pattern for extraction
 *
 *  @return initialized parser factory
 */
- (instancetype)initWithRegex:(NSString*) regex;

/**
 * Regex pattern for OCR extraction
 */
@property (nonatomic) NSString *regex;

/**
 * Ocr Engine options used in Raw ocr parsing
 *
 * Default: [[PPOcrEngineOptions alloc] init]
 */
@property (nonatomic) PPOcrEngineOptions *options;

/**
 * Use algorithm for combining consecutive OCR results between video frames
 *
 * Default: NO
 */
@property (nonatomic) BOOL useSieve;

@end
