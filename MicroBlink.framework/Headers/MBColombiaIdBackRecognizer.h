//
//  MBColombiaIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBColombiaIdBackRecognizerResult.h"

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Colombia ID Back Recognizer.
 *
 * Colombia ID Back recognizer is used for scanning back side of Colombia ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBColombiaIdBackRecognizer : MBLegacyRecognizer <NSCopying>

MB_INIT

/**
 * Colombia ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBColombiaIdBackRecognizerResult *result;

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
 * Default: YES
 */
@property (nonatomic) BOOL nullQuietZoneAllowed;

@end

NS_ASSUME_NONNULL_END
