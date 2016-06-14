//
//  PPRawOcrParserFactory.h
//  PhotoPayFramework
//
//  Created by Jura on 27/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

#import "PPOcrEngineOptions.h"

/**
 * Parser responsible for parsing raw OCR text
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPRawOcrParserFactory : PPOcrParserFactory

/**
 * Ocr Engine options used in Raw ocr parsing
 *
 * Default: [[PPOcrEngineOptions alloc] init]
 */
@property (nonatomic, strong) PPOcrEngineOptions *options;

/**
 * Use algorithm for combining consecutive OCR results between video frames
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL useSieve;

@end
