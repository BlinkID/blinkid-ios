//
//  BottomLeftCardNumberType.m
//  Starbucks-sample
//
//  Created by Jure Cular on 07/07/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "BottomLeftCardNumberType.h"

// Key used to distinguish between parser groups
static NSString *const kCardType = @"BottomLeftCardNumberType";

// Key used to fetch results from parser
static NSString *const kSecurityCodeKey = @"SecurityCodeBottomLeftCardNumberType";

// Dewarped height of security code
static CGFloat const kSecurityCodeDewarpedHeight = 200.f;

// Minimal security code line height
static CGFloat const kSecurityCodeMinHeight = 70.f;

// Maximal security code line height
static CGFloat const kSecurityCodeMaxHeight = 120.f;

// Maximal number of characters expected on position of security code
static CGFloat const kSecurityCodeMaxCharExpected = 35.f;

// Rectangle that describes the position of the security code relative to card
static CGRect const kSecurityCodeLocation = {{0.6950f, 0.6416f}, {0.2625f, 0.0980f}};

// Key used to fetch card number from parser
static NSString *const kCardNumberKey = @"CardNumberBottomLeftCardNumberType";

// Dewarped height of card number
static CGFloat const kCardNumberDewarpedHeight = 100.f;

// Minimal card number line height
static CGFloat const kCardNumberMinHeight = 50.f;

// Maximal card number line height
static CGFloat const kCardNumberMaxHeight = 100.f;

// Maximal number of characters expected
static CGFloat const kCardNumberMaxCharExpected = 150.f;

// Rectangle that describes the position of the card number relative to card
static CGRect const kCardNumberLocation = {{0.2000f, 0.6700f}, {0.5000f, 0.0700f}};

@implementation BottomLeftCardNumberType

- (instancetype)init {
    self = [super init];
    if (self) {
        self.cardNumberDecodingInfo =
            [[PPDecodingInfo alloc] initWithLocation:kCardNumberLocation dewarpedHeight:kCardNumberDewarpedHeight uniqueId:kCardNumberKey];

        self.securityCodeDecodingInfo = [[PPDecodingInfo alloc] initWithLocation:kSecurityCodeLocation
                                                                  dewarpedHeight:kSecurityCodeDewarpedHeight
                                                                        uniqueId:kSecurityCodeKey];

        self.securityCodeRegexParser = [self createParserWithCharWhiteList:[self numberWhitelist]
                                                         minimalLineHeight:kSecurityCodeMinHeight
                                                         maximalLineHeight:kSecurityCodeMaxHeight
                                                          maxCharsExpected:kSecurityCodeMaxCharExpected
                                                                     regex:kSecurityCodeRegex];

        self.cardNumberRegexParser = [self createParserWithCharWhiteList:[self charAndNumberWhiteList]
                                                       minimalLineHeight:kCardNumberMinHeight
                                                       maximalLineHeight:kCardNumberMaxHeight
                                                        maxCharsExpected:kCardNumberMaxCharExpected
                                                                   regex:kCardNumberRegex];
        self.cardTypeKey = kCardType;

        self.securityCodeKey = kSecurityCodeKey;

        self.cardNumberKey = kCardNumberKey;
    }
    return self;
}

@end
