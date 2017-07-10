//
//  CardTypeFactory.m
//  Starbucks-sample
//
//  Created by Jure Cular on 07/07/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "CardTypeFactory.h"
#import "BottomLeftCardNumberType.h"
#import "TopCenterCardNumberType.h"
#import "TopLeftCardNumberType.h"

@implementation CardTypeFactory

+ (BaseCardType *)createCardInfoForType:(CardTypeEnum)cardType {
    switch (cardType) {
        case TopCenterCardNumberTypeEnum:
            return [[TopCenterCardNumberType alloc] init];

        case TopLeftCardNumberTypeEnum:
            return [[TopLeftCardNumberType alloc] init];

        case BottomLeftCardNumberTypeEnum:
            return [[BottomLeftCardNumberType alloc] init];

        default:
            return nil;
    }
}

@end
