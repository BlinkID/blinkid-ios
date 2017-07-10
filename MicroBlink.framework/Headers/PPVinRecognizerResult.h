//
//  PPVinRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 06/06/2017.
//
//

#import "PPRecognizerResult.h"

/**
 * Result of scanning with Vin Recognizer
 *
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPVinRecognizerResult : PPRecognizerResult

/**
 * Scanned VIN
 */
@property (nonatomic, readonly, strong, nullable) NSString *vinNumber;

@end
