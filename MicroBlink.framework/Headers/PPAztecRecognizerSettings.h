//
//  PPAztecRecognizerSettings.h
//  BlinkIDDev
//
//  Created by Jura on 25/03/2017.
//  Copyright (c) 2017 MicroBlink Ltd. All rights reserved.

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring Aztec Recognizer
 *
 * Aztec recognizer is used for scanning Aztec barcodes. Intrnally it uses Manatee Works library, but adds 
 * MicroBlink's image processing and camera management. 
 * It's superior in performance to ZXingRecognizer and others.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPAztecRecognizerSettings : PPRecognizerSettings

PP_INIT_UNAVAILABLE;

/**
 * Initializes the settings with license key for manatee library
 *
 * @param manateeLibKey license key
 * @return initialized instance
 */
- (instancetype)initWithManateeLibKey:(nonnull NSString *)manateeLibKey NS_DESIGNATED_INITIALIZER;

/**
 * License key for manateeworks library
 */
@property (nonatomic, readonly, strong) NSString *manateeLibKey;

@end

NS_ASSUME_NONNULL_END
