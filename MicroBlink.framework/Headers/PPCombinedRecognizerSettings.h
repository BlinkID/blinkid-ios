//
//  PPCombinedRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 05/03/2017.
//  Copyright © 2017 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Recognizer settings subclass which combines multiple recognizers in one bundle.
 *
 * Typically used for scanning front and back side of the ID documents
 */
@interface PPCombinedRecognizerSettings : PPRecognizerSettings

/**
 * If YES, recognized data will contain a digital signature which can be used to prove
 * that the data really originated from the SDK
 *
 * Default: NO
 */
@property (nonatomic) BOOL shouldSignData;

@end
