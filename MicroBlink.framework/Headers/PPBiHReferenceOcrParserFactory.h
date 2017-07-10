//
//  PPBiHReferenceOcrParserFactory.h
//  PhotoPayFramework
//
//  Created by Dino on 16/12/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

/**
 *  Parses reference number on BiH payment slips
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPBiHReferenceOcrParserFactory : PPOcrParserFactory

/**
 * Creates parser instance with default parametars.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end
