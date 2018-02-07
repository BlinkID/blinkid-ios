//
//  PPColombiaIDBackRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 30/01/2018.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Colombian Back ID Recognizer.
 *
 * Colombian Back ID recognizer is used for scanning back side of Colombian ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPColombiaIDBackRecognizerSettings : PPRecognizerSettings

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
 * Use only if necessary because it slows down the recognition process
 *
 * Default: NO
 */
@property (nonatomic) BOOL allowNullQuietZone;

@end
