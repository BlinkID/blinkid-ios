//
//  MBPaymentCardFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by juraskrlec on 29/08/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of the Payment Card
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBPaymentCardFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The payment card number.
 */
@property (nonatomic, readonly) NSString *cardNumber;

/**
 * Information about the payment card owner (name, company, etc.).
 */
@property (nonatomic, readonly) NSString *owner;

/**
 * The payment card's last month of validity.
 */
@property (nonatomic, readonly) MBDateResult *validThru;

@end

NS_ASSUME_NONNULL_END
