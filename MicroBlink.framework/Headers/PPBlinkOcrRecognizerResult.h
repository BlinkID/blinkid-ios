//
//  PPOcrScanResult.h
//  PhotoPayFramework
//
//  Created by Jura on 18/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPTemplatingRecognizerResult.h"
#import "PPOcrLayout.h"

/**
 * Result of scanning with Blink OCR Recognizer
 *
 * For each parser group, the result contains one Ocr Layout, and one or more parsed results.
 */
PP_CLASS_DEPRECATED_IOS(1_0, 5_10_0, "Use PPDetectorRecognizerResult for templating or PPBlinkInputRecognizerResult segment scan")
@interface PPBlinkOcrRecognizerResult : PPTemplatingRecognizerResult

@end
