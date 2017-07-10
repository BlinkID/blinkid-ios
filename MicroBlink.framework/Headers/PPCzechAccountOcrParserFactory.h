//
//  PPCzechAccountOcrParserFactory.h
//  PhotoPayFramework
//
//  Created by Dino on 23/03/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

/**
 *  Parses account number on Czech payment slips
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPCzechAccountOcrParserFactory : PPOcrParserFactory

/**
 * Creates parser instance with default parametars.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end
