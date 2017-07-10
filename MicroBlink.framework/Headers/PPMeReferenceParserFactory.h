//
//  MeReferenceParserFactory.h
//  PhotoPayFramework
//
//  Created by Jura on 15/03/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

/**
 *  Parses reference number on Macedonian payment slip
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPMeReferenceParserFactory : PPOcrParserFactory

/**
 * Creates parser instance with default parametars.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end
