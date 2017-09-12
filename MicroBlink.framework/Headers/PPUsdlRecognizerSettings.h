//
//  PPUsdlRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 26/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring Usdl Recognizer
 *
 * Usdl Recognizer recognizer is used for scanning and parsing of PDF417
 * on the back sides of the US drivers license
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPUsdlRecognizerSettings : PPRecognizerSettings

/**
 * Set this to YES to scan even barcode not compliant with standards
 * For example, malformed PDF417 barcodes which were incorrectly encoded
 *
 * Use only if necessary because it slows down the recognition process
 *
 * Default: YES
 */
@property (nonatomic) BOOL scanUncertain;

/**
 * Set this to YES to scan barcodes which don't have quiet zone (white area) around it
 *
 * Disable if you need a slight speed boost
 *
 * Default: YES
 */
@property (nonatomic) BOOL allowNullQuietZone;

@end

NS_ASSUME_NONNULL_END
