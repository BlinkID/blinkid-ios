//
//  MBColombiaIdBackRecognizerRecognizer.h
//  MicroblinkDev
//
//  Created by dodo on 24/07/2018.
//

#import "MBRecognizer.h"
#import "MBColombiaIdBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Colombia Id Back Recognizer.
 *
 * Colombia Id Back recognizer is used for scanning back side of the Colombia Id.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBColombiaIdBackRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Colombia Id Back Recognizer
 */
@property (nonatomic, strong, readonly) MBColombiaIdBackRecognizerResult *result;

/**
 * Set this to YES to scan even barcode not compliant with standards
 * For example, malformed PDF417 barcodes which were incorrectly encoded
 *
 * Use only if necessary because it slows down the recognition process
 *
 * Default: YES
 */
@property (nonatomic) BOOL scanUncertain;

/**
 * Set this to YES to scan barcodes which don't have quiet zone (white area) around it
 *
 * Use only if necessary because it slows down the recognition process
 *
 * Default: YES
 */
@property (nonatomic) BOOL nullQuietZoneAllowed;

@end

NS_ASSUME_NONNULL_END
