//
//  MBPaymentCardBackRecognizer.h
//  MicroBlinkDev
//
//  Created by juraskrlec on 29/08/2018.
//

#import "MBRecognizer.h"
#import "MBPaymentCardBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer used for scanning the back side of credit/debit cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBPaymentCardBackRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection>

MB_INIT

/**
 * Result of scanning Payment Card Back Recognizer
 */
@property (nonatomic, strong, readonly) MBPaymentCardBackRecognizerResult *result;

/**
 * Should extract the card's inventory number
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractInventoryNumber;

@end

NS_ASSUME_NONNULL_END
