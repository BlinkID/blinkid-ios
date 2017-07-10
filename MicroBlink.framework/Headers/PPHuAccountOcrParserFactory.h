//
//  PPHuAccountOcrParserFactory.h
//  PhotoPayFramework
//
//  Created by DoDo on 21/10/2016.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

/**
 *  Parses account number on Hungarian payment slip
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPHuAccountOcrParserFactory : PPOcrParserFactory

/**
 * Creates parser instance with default parametars.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

