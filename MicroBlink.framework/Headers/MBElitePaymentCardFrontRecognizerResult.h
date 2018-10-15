//
//  MBElitePaymentCardFrontRecognizerResult.h
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
 * Class representing values obtained when scanning front side of the Elite Payment Card
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBElitePaymentCardFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The owner of the front side of the Elite Payment Card owner.
 */
@property (nonatomic, readonly) NSString *owner;

@end

NS_ASSUME_NONNULL_END
