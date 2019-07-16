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
 * Called with dewarped full document image
 */
- (void)setDewarpedImageDelegate:(nullable id<MBBlinkIdCombinedRecognizerDelegate>)delegate;

/**
 * Called when document is not supported
 */
- (void)setClassifierDelegate:(nullable id<MBBlinkIdCombinedRecognizerDelegate>)delegate;

@end

@protocol MBBlinkIdCombinedRecognizerDelegate <NSObject>
@optional
- (void)onCombinedImageAvailable:(nullable MBImage *)dewarpedImage;
- (void)onCombinedDocumentSupportStatus:(BOOL)isDocumentSupported;
@end


NS_ASSUME_NONNULL_END
