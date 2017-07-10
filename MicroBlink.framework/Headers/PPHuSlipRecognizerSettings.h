//
//  PPHuSlipRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 28/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring HU Slip Recognizer
 *
 * HU Slip recognizer is used for scanning Hungarian payment slips - white and yellow.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPHuSlipRecognizerSettings : PPRecognizerSettings

/**
 * If YES, HU Slip recognizer will read recipent name from the payment slip.
 *
 * Default: YES
 */
@property (nonatomic) BOOL readRecipientName;

@end
