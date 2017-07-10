//
//  PPCroQrRecognizerSetting.h
//  PhotoPayFramework
//
//  Created by Jura on 27/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Specififes settings for QR code recognizer for croatian payslips
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCroQrRecognizerSettings : PPRecognizerSettings

/**
 * Peform sanitization on data recognized from QR code.
 * Sanitization is performed according to HUB3 standards.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL useSanitization;

/**
 * Performs slower and more thorough search for QR code finder patterns.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL useSlowerThoroughScan;

@end
