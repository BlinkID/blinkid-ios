//
//  PPOcrScanResult.h
//  PhotoPayFramework
//
//  Created by Jura on 18/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPSegmentRecognizerResult.h"
#import "PPOcrLayout.h"

/**
 * Result of scanning with OCR Recognizer
 *
 * For each parser group, the result contains one Ocr Layout, and one or more parsed results.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPTemplatingRecognizerResult : PPSegmentRecognizerResult

/**
 * Returns result of document classification, if any.
 * @return result of document classification, if any.
 */
- (NSString *_Nullable)documentClassification;

@end
