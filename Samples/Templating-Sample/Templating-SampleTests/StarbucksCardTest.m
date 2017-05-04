//
//  StarbucksCardTest.m
//  Templating-Sample
//
//  Created by Jure Cular on 02/05/2017.
//  Copyright © 2017 Dino. All rights reserved.
//

#import "TemplateRecognizerTests.h"
#import "StarbucksCardRecognizerSettings.h"

@interface StarbucksCardTest : TemplateRecognizerTests

@end

@implementation StarbucksCardTest

/**
 *  Test for the first type of cards.
 *  First type of cards have card number in the center top, and security number below it.
 *  Example: IMG_2385.jpg
 */

- (void)testStarbucksCardFirstType {
    [self.coordinator.currentSettings.scanSettings addRecognizerSettings:[[StarbucksCardRecognizerSettings alloc] init]];
    [self.coordinator applySettings];
    [self setUpDidOutputResultsWithCardNumberTruth:@"6046 0391 6441 1573" andSecurityCodeTruth:@"77993675" forType:@"FirstType"];

    [self testImage:@"IMG_2385" ofType:@"jpg" withDescription:@"Type one starbucks card"];
}

/**
 *  Test for the second type of cards.
 *  Second type of cards have card number in the upper left corner, and security number in the upper right corner.
 *  Example: IMG_2405.jpg
 */

- (void)testStarbucksCardSecondType {
    [self.coordinator.currentSettings.scanSettings addRecognizerSettings:[[StarbucksCardRecognizerSettings alloc] init]];
    [self.coordinator applySettings];
    [self setUpDidOutputResultsWithCardNumberTruth:@"6083 0771 2728 4166" andSecurityCodeTruth:@"37470746" forType:@"SecondType"];

    [self testImage:@"IMG_2405" ofType:@"jpg" withDescription:@"Type two starbucks card"];
}

/**
 *  Test for the third type of cards.
 *  Third type of cards have card number in the lower left corner, and security number in the lower right corner.
 *  Example: IMG_2388.jpg
 */

- (void)testStarbucksCardThirdType {
    [self.coordinator.currentSettings.scanSettings addRecognizerSettings:[[StarbucksCardRecognizerSettings alloc] init]];
    [self.coordinator applySettings];
    [self setUpDidOutputResultsWithCardNumberTruth:@"6078 7827 3165 3467" andSecurityCodeTruth:@"25977048" forType:@"ThirdType"];

    [self testImage:@"IMG_2388" ofType:@"jpg" withDescription:@"Type three starbucks card"];
}


#pragma mark - DidOutputResults block setup

- (void)setUpDidOutputResultsWithCardNumberTruth:(NSString *)cardNumberTruth
                            andSecurityCodeTruth:(NSString *)securityCodeTruth
                                         forType:(NSString *)type {

    __weak StarbucksCardTest *weakSelf = self;

    weakSelf.didOutputResults = ^(NSArray<PPRecognizerResult *> *results) {

        if (results.count == 0 || results == nil) {
            return;
        }
        for (PPRecognizerResult *result in results) {
            if ([result isKindOfClass:[PPBlinkOcrRecognizerResult class]]) {

                // Key used to get recognized card number, key used depends on the type of card recognized therefore key is dynamically
                // created using the type of card recognized. If the First type of card is recognized, the key will be :
                // @"CardNumberFirstType.CardNumber"
                NSString *cardNumberKey = [[@"CardNumber" stringByAppendingString:type] stringByAppendingString:@".CardNumber"];

                [weakSelf checkStringValueInResult:result truth:cardNumberTruth key:cardNumberKey];

                // Same as the CardNumber above, but this one is used to get security code values.
                NSString *securityCodeKey = [[@"SecurityCode" stringByAppendingString:type] stringByAppendingString:@".SecurityCode"];
                [weakSelf checkStringValueInResult:result truth:securityCodeTruth key:securityCodeKey];
            }
        }

        [weakSelf.expectation fulfill];
    };
}

@end
