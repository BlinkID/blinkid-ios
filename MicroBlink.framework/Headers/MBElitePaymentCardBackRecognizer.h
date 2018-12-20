//
//  MBElitePaymentCardBackRecognizer.h
//  MicroBlinkDev
//
//  Created by juraskrlec on 10/10/2018.
//

#import "MBRecognizer.h"
#import "MBElitePaymentCardBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer used for scanning the back side of elite payment cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBElitePaymentCardBackRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Elite Payment Card Back Recognizer
 */
@property (nonatomic, strong, readonly) MBElitePaymentCardBackRecognizerResult *result;

/**
 * Should extract the card's inventory number
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractInventoryNumber;

/**
 * Should extract the payment card's month of expiry
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidThru;

/**
 * Should anonymize the CVV area (redact image pixels) on the document image result
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL anonymizeCvv;

/**
 * Should anonymize the card number area (redact image pixels) on the document image result
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL anonymizeCardNumber;

@end

NS_ASSUME_NONNULL_END
