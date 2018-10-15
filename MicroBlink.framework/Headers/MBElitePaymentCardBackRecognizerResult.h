//
//  MBElitePaymentCardBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by juraskrlec on 10/10/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of the Elite Payment Card
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBElitePaymentCardBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The card Number of the back side of the Elite Payment Card owner.
 */
@property (nonatomic, readonly) NSString *cardNumber;

/**
 * The cvv of the back side of the Elite Payment Card owner.
 */
@property (nonatomic, readonly) NSString *cvv;

/**
 * The inventory Number of the back side of the Elite Payment Card owner.
 */
@property (nonatomic, readonly) NSString *inventoryNumber;

/**
 * The valid Thru of the back side of the Elite Payment Card owner.
 */
@property (nonatomic, readonly) MBDateResult *validThru;

@end

NS_ASSUME_NONNULL_END
