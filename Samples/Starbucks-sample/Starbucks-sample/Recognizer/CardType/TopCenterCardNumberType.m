//
//  TopCenterCardNumberType.m
//  Starbucks-sample
//
//  Created by Jure Cular on 07/07/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "TopCenterCardNumberType.h"

// Key used to distinguish between parser groups
static NSString *const kCardType = @"TopCenterCardNumberType";

// Key used to fetch security code from parser
static NSString *const kSecurityCodeKey = @"SecurityCodeTopCenterCardNumberType";

// Dewarped height of security code
static CGFloat const kSecurityCodeDewarpedHeight = 200.f;

// Minimal security code line height
static CGFloat const kSecurityCodeMinHeight = 60.f;

// Maximal security code line height
static CGFloat const kSecurityCodeMaxHeight = 150.f;

// Maximal number of characters expected on position of security code
static CGFloat const kSecurityCodeMaxCharExpected = 25.f;

// Rectangle that describes the position of the security code relative to card
static CGRect const kSecurityCodeLocation = {{0.7198f, 0.1602f}, {0.2253f, 0.1082f}};

// Key used to fetch card number from parser
static NSString *const kCardNumberKey = @"CardNumberTopCenterCardNumberType";

// Dewarped height of card number
static CGFloat const kCardNumberDewarpedHeight = 100.f;

// Minimal card number line height
static CGFloat const kCardNumberMinHeight = 50.f;

// Maximal card number line height
static CGFloat const kCardNumberMaxHeight = 100.f;

// Maximal number of characters expected
static CGFloat const kCardNumberMaxCharExpected = 150.f;

// Rectangle that describes the position of the card number relative to card
static CGRect const kCardNumberLocation = {{0.2088f, 0.1688f}, {0.5500f, 0.0866f}};

@implementation TopCenterCardNumberType

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
