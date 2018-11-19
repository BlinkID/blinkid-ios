//
//  MBElitePaymentCardFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by juraskrlec on 10/10/2018.
//

#import "MBRecognizer.h"
#import "MBElitePaymentCardFrontRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer used for scanning the front side of elite credit/debit cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBElitePaymentCardFrontRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Elite Payment Card Front Recognizer
 */
@property (nonatomic, strong, readonly) MBElitePaymentCardFrontRecognizerResult *result;

/**
 * Should extract the card owner information
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractOwner;

/**
 * Should anonymize the owner area (redact image pixels) on the document image result
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL anonymizeOwner;

@end

NS_ASSUME_NONNULL_END
