//
//  MBBlinkIdCombinedRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 18/06/2019.
//

#import "MBRecognizer.h"
#import "MBBlinkIdCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"
#import "MBDigitalSignature.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

@protocol MBBlinkIdCombinedRecognizerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer which can scan front and back side of the United States driver license.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBlinkIdCombinedRecognizer : MBRecognizer<NSCopying, MBCombinedRecognizer, MBDigitalSignature, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning BlinkIDCombinedRecognizer
 */
@property (nonatomic, strong, readonly) MBBlinkIdCombinedRecognizerResult *result;

/**
* Full document dewarped imagedelegate
*/
@property (nonatomic, nullable, weak) id<MBBlinkIdCombinedRecognizerDelegate> dewarpedImageDelegate;

/**
* Document not supported classifier delegate
*/
@property (nonatomic, nullable, weak) id<MBBlinkIdCombinedRecognizerDelegate> classifierDelegate;

/**
 * Defines whether blured frames filtering is allowed
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL allowBlurFilter;

/**
 * Defines whether returning of unparsed MRZ (Machine Readable Zone) results is allowed
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL allowUnparsedMrzResults;

/**
 * Defines whether returning unverified MRZ (Machine Readable Zone) results is allowed
 * Unverified MRZ is parsed, but check digits are incorrect
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL allowUnverifiedMrzResults;

@end

@protocol MBBlinkIdCombinedRecognizerDelegate <NSObject>
@optional
- (void)onCombinedImageAvailable:(nullable MBImage *)dewarpedImage;
- (void)onCombinedDocumentSupportStatus:(BOOL)isDocumentSupported;
@end


NS_ASSUME_NONNULL_END
