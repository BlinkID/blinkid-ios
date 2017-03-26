//
//  PPVinOcrParserFactory.h
//  BlinkIdFramework
//
//  Created by Dino on 20/06/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPVinOcrParserFactory : PPOcrParserFactory

/**
 * Creates parser instance with default parametars.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end
