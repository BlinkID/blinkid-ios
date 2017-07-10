//
//  PPVinRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 06/06/2017.
//
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Vin Recognizer
 *
 * Vin recognizer is used for scanning Code 39 and Code 128 VIN barcodes and is superior in performance
 * to BarDecoder for VIN
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPVinRecognizerSettings : PPRecognizerSettings

@end
