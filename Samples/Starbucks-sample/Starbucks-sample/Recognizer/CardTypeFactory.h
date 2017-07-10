//
//  CardTypeFactory.h
//  Starbucks-sample
//
//  Created by Jure Cular on 07/07/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MicroBlink/MicroBlink.h>

#import "BaseCardType.h"

typedef NS_ENUM(NSUInteger, CardTypeEnum) {

    /*  Type of card with card number in top center position on the card and security number below it */
    TopCenterCardNumberTypeEnum,

    /*  Type of card with card number in top left position on the card and security number in top right position */

    TopLeftCardNumberTypeEnum,

    /*  Type of card with card number in bottom left position on the card and security number in the bottom right position */
    BottomLeftCardNumberTypeEnum,
    
};

@interface CardTypeFactory : NSObject

+ (BaseCardType *)createCardInfoForType:(CardTypeEnum)cardType;

@end
