//
//  MBPaymentCardBackRecognizerResult.h
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
 * Class representing values obtained when scanning back side of the Payment Card
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBPaymentCardBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * Payment card's security code/value.
 */
@property (nonatomic, readonly) NSString *cvv;

/**
 * Payment card's inventory number.
 */
@property (nonatomic, readonly) NSString *inventoryNumber;

@end

NS_ASSUME_NONNULL_END
