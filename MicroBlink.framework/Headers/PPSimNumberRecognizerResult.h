//
//  PPSimNumberRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Admin on 23/02/2017.
//  Copyright © 2017 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"

/**
 * Result of scanning with SimNumber Recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSimNumberRecognizerResult : PPRecognizerResult

/**
 * Scanned SIM number
 */
@property (nonatomic, readonly, strong, nullable) NSString *simNumber;

@end
