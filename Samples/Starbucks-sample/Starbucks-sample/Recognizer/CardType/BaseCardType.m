//
//  BaseCardType.m
//  Starbucks-sample
//
//  Created by Jure Cular on 09/07/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "BaseCardType.h"

@implementation BaseCardType

- (PPRegexOcrParserFactory *)createParserWithCharWhiteList:(NSSet *)charWhiteList
                                         minimalLineHeight:(NSUInteger)minimalLineHeight
                                         maximalLineHeight:(NSUInteger)maximalLineHeight
                                          maxCharsExpected:(NSUInteger)maxCharsExpected
                                                     regex:(NSString *)regex {
    PPRegexOcrParserFactory *parser = [[PPRegexOcrParserFactory alloc] initWithRegex:regex];

    parser.startsWithWhitespace = YES;
    parser.endsWithWhitespace = YES;

    PPOcrEngineOptions *engineOptions = [[PPOcrEngineOptions alloc] init];

    engineOptions.charWhitelist = charWhiteList;
    engineOptions.minimalLineHeight = minimalLineHeight;
    engineOptions.maximalLineHeight = maximalLineHeight;
    engineOptions.maxCharsExpected = maxCharsExpected;
    engineOptions.colorDropoutEnabled = NO;

    [parser setOptions:engineOptions];

    return parser;
}

- (NSMutableSet *)numberWhitelist {
    // initialize new char whitelist
    NSMutableSet *charWhitelist = [[NSMutableSet alloc] init];

    // Add chars '0'-'9'
    for (int c = '0'; c <= '9'; c++) {
        [charWhitelist addObject:[PPOcrCharKey keyWithCode:c font:PP_OCR_FONT_ANY]];
    }
    return charWhitelist;
}

- (NSSet *)charAndNumberWhiteList {
    NSMutableSet *charWhiteList = [self numberWhitelist];

    for (int c = 'a'; c <= 'z'; c++) {
        [charWhiteList addObject:[PPOcrCharKey keyWithCode:c font:PP_OCR_FONT_ANY]];
    }
    return charWhiteList;
}

@end
