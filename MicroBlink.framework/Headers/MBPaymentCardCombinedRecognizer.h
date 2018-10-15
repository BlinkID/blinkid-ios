//
//  MBPaymentCardCombinedRecognizer.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 29/08/2018.
//

#import "MBRecognizer.h"
#import "MBPaymentCardCombinedRecognizerResult.h"

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
@interface MBPaymentCardCombinedRecognizer : MBRecognizer <NSCopying, MBCombinedRecognizer, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBDigitalSignature, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Payment Card Combined Recognizer
 */
@property (nonatomic, strong, readonly) MBPaymentCardCombinedRecognizerResult *result;

/**
 * Should extract the card owner information
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractOwner;

/**
 * Should extract the payment card's month of expiry
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidThru;

/**
 * Should extract the card's inventory number
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractInventoryNumber;

@end

NS_ASSUME_NONNULL_END
