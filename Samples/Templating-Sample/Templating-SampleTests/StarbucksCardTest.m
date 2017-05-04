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

- (void)testStarbucksCardFirstType {
    [self.coordinator.currentSettings.scanSettings addRecognizerSettings:[[StarbucksCardRecognizerSettings alloc] init]];
    [self.coordinator applySettings];
    [self setUpDidOutputResultsWithCardNumberTruth:@"6046 0391 6441 1573" andSecurityCodeTruth:@"77993675" forType:@"FirstType"];

    [self testImage:@"IMG_2385" ofType:@"jpg" withDescription:@"Type one starbucks card"];
}

- (void)testStarbucksCardSecondType {
    [self.coordinator.currentSettings.scanSettings addRecognizerSettings:[[StarbucksCardRecognizerSettings alloc] init]];
    [self.coordinator applySettings];
    [self setUpDidOutputResultsWithCardNumberTruth:@"6083 0771 2728 4166" andSecurityCodeTruth:@"37470746" forType:@"SecondType"];

    [self testImage:@"IMG_2405" ofType:@"jpg" withDescription:@"Type two starbucks card"];
}

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
                [weakSelf checkStringValueInResult:result
                                             truth:cardNumberTruth
                                               key:[[@"CardNumber" stringByAppendingString:type] stringByAppendingString:@".CardNumber"]];
                [weakSelf
                    checkStringValueInResult:result
                                       truth:securityCodeTruth
                                         key:[[@"SecurityCode" stringByAppendingString:type] stringByAppendingString:@".SecurityCode"]];
            }
        }

        [weakSelf.expectation fulfill];
    };
}

@end
