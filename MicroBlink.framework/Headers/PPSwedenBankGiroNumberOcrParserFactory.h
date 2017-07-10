//
//  PPSwedenBankGiroNumberOcrParserFactory.h
//  PhotoPayFramework
//
//  Created by Jura on 27/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

/**
 *  Parses Giro number on Swedish payment slip
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPSwedenBankGiroNumberOcrParserFactory : PPOcrParserFactory

/**
 * Creates parser instance with default parametars.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end
