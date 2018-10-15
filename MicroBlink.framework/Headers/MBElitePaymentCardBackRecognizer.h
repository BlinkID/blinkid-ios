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
 * Should extract the card's security code/value
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCvv;

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

@end

NS_ASSUME_NONNULL_END
