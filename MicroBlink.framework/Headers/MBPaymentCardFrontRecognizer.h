//
//  MBPaymentCardFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by juraskrlec on 29/08/2018.
//

#import "MBRecognizer.h"
#import "MBPaymentCardFrontRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer used for scanning the front side of credit/debit cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBPaymentCardFrontRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Payment Card Front Recognizer
 */
@property (nonatomic, strong, readonly) MBPaymentCardFrontRecognizerResult *result;

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

@end

NS_ASSUME_NONNULL_END
