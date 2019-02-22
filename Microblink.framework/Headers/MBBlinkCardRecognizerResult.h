//
//  MBBlinkCardRecognizerResult.h
//  MicroBlinkDev
//
//  Created by juraskrlec on 29/08/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBDigitalSignatureResult.h"

#import "MBCombinedRecognizerResult.h"
#import "MBCombinedFullDocumentImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

#import "MBCardIssuer.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of the Payment Card
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBlinkCardRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBDigitalSignatureResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult>

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

/**
 *  Payment card's security code/value
 */
@property (nonatomic, readonly) NSString *cvv;

/**
 * Payment card's inventory number.
 */
@property (nonatomic, readonly) NSString *inventoryNumber;

/**
 * Payment card's issuing networ
 */
@property (nonatomic, readonly) MBCardIssuer issuer;

@end

NS_ASSUME_NONNULL_END
