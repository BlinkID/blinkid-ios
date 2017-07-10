//
//  BaseCardType.h
//  Starbucks-sample
//
//  Created by Jure Cular on 09/07/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MicroBlink/MicroBlink.h>

// Security code regex
static NSString *const kSecurityCodeRegex = @"\\d{8}";

// Card number regex
static NSString *const kCardNumberRegex = @"(\\d{4} ){3}(\\d{4})";

/**
 *  To add a new type of card make subclass of this class and set its properties in init method.
 *  This class is not meant to be instantiated.
 */

@interface BaseCardType : NSObject

@property (strong, nonatomic) PPDecodingInfo *cardNumberDecodingInfo;

@property (strong, nonatomic) PPDecodingInfo *securityCodeDecodingInfo;

@property (strong, nonatomic) PPRegexOcrParserFactory *cardNumberRegexParser;

@property (strong, nonatomic) PPRegexOcrParserFactory *securityCodeRegexParser;

@property (strong, nonatomic) NSString *cardTypeKey;

@property (strong, nonatomic) NSString *securityCodeKey;

@property (strong, nonatomic) NSString *cardNumberKey;

- (PPRegexOcrParserFactory *)createParserWithCharWhiteList:(NSSet *)charWhiteList
                                         minimalLineHeight:(NSUInteger)minimalLineHeight
                                         maximalLineHeight:(NSUInteger)maximalLineHeight
                                          maxCharsExpected:(NSUInteger)maxCharsExpected
                                                     regex:(NSString *)regex;
- (NSMutableSet *)numberWhitelist;

- (NSSet *)charAndNumberWhiteList;

@end
