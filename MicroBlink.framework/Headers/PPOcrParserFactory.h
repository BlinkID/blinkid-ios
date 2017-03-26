//
//  PPOcrParserFactory.h
//  PhotoPayFramework
//
//  Created by Jura on 26/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class of all OCR parsers.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPOcrParserFactory : NSObject

/**
 * Init is unavailable
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Denotes if this parser is required to output results.
 * If this parser is required to output results, no other parser results will be outputted unless this parser outputs a result.
 *
 * For example, If there are date and email parsers active and required, no results will be outputted unless both produce results from the
 * same frame.
 *
 * Default: YES
 */
@property (nonatomic) BOOL isRequired;

@end

NS_ASSUME_NONNULL_END
