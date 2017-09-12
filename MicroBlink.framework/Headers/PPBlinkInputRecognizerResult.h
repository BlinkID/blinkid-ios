//
//  PPBlinkInputRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 03/08/2017.
//
//

#import "PPSegmentRecognizerResult.h"
#import "PPOcrLayout.h"

/**
 * Result of scanning with Blink Input Recognizer
 *
 * For each parser group, the result contains one Ocr Layout, and one or more parsed results.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPBlinkInputRecognizerResult : PPSegmentRecognizerResult

@end
