//
//  PPMobileCouponsOcrParserFactory.h
//  BlinkOcrFramework
//
//  Created by Dino on 08/09/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

/**
 * Top up prefix of a coupon
 */
typedef NS_ENUM(NSUInteger, PPTopUpPrefix) {
    
    /** Simpa, BonBon, Multiplus */
    PPTopUpPrefix123 = 0,
    
    /** vip, tomato */
    PPTopUpPrefix103,
    
    /** tele2 */
    PPTopUpPrefix131,
    
    /** All prefixes but do not allow codes without prefix */
    PPTopUpPrefixAll,
};

/**
 *  Parses mobile coupons
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPMobileCouponsOcrParserFactory : PPOcrParserFactory

/**
 * Initializes parser with desired top up prefix.
 */
- (instancetype)initWithTopUpPrefix:(PPTopUpPrefix)topUpPrefix;

@end
