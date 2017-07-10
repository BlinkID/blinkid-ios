//
//  PPCzechVariabilniSymbolParserFactory.h
//  PhotoPayFramework
//
//  Created by Dino on 23/03/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

/**
 *  Parses variabilni symbol on Czech and Slovakian payment slips
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPCzechVariabilniSymbolParserFactory : PPOcrParserFactory

/**
 * Creates parser instance with default parametars.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end
