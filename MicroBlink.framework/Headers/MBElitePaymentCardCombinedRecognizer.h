//
//  MBElitePaymentCardCombinedRecognizer.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 10/10/2018.
//

#import "MBRecognizer.h"
#import "MBElitePaymentCardCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBDigitalSignature.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer used for scanning the front and back side of credit/debit cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBElitePaymentCardCombinedRecognizer : MBRecognizer <NSCopying, MBCombinedRecognizer, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBDigitalSignature, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Payment Card Combined Recognizer
 */
@property (nonatomic, strong, readonly) MBElitePaymentCardCombinedRecognizerResult *result;

/**
 * Should extract the card owner information
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractOwner;

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
 * Should anonymize the card number area (redact image pixels) on the document image result
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL anonymizeCardNumber;

/**
 * Should anonymize the owner area (redact image pixels) on the document image result
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL anonymizeOwner;


/**
 * Should anonymize the CVV area (redact image pixels) on the document image result
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL anonymizeCvv;

@end

NS_ASSUME_NONNULL_END
