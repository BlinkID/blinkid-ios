//
//  PPLicensePlatesParserFactory.h
//  PhotoPayFramework
//
//  Created by Dino on 17/05/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

/**
 *  Parses license plates
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPLicensePlatesParserFactory : PPOcrParserFactory

/**
 * Creates parser instance with default parametars.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end
