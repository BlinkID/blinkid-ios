//
//  TopLeftCardNumberType.m
//  Starbucks-sample
//
//  Created by Jure Cular on 07/07/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "TopLeftCardNumberType.h"

// Key used to distinguish between parser groups
static NSString *const kCardType = @"TopLeftCardNumberType";

// Key used to fetch security code from parser
static NSString *const kSecurityCodeKey = @"SecurityCodeTopLeftCardNumberType";

// Dewarped height of security code
static CGFloat const kSecurityCodeDewarpedHeight = 200.f;

// Minimal security code line height
static CGFloat const kSecurityCodeMinHeight = 80.f;

// Maximal security code line height
static CGFloat const kSecurityCodeMaxHeight = 150.f;

// Maximal number of characters expected on position of security code
static CGFloat const kSecurityCodeMaxCharExpected = 15.f;

// Rectangle that describes the position of the security code relative to card
static CGRect const kSecurityCodeLocation = {{0.4750f, 0.2180f}, {0.2266f, 0.0800f}};

// Key used to fetch card number from parser
static NSString *const kCardNumberKey = @"CardNumberTopLeftCardNumberType";

// Dewarped height of card number
static CGFloat const kCardNumberDewarpedHeight = 100.f;

// Minimal card number line height
static CGFloat const kCardNumberMinHeight = 50.f;

// Maximal card number line height
static CGFloat const kCardNumberMaxHeight = 100.f;

// Maximal number of characters expected
static CGFloat const kCardNumberMaxCharExpected = 150.f;

// Rectangle that describes the position of the card number relative to card
static CGRect const kCardNumberLocation = {{0.3406f, 0.1303f}, {0.5125f, 0.0977f}};

@implementation TopLeftCardNumberType

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
