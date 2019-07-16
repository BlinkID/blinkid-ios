//
// MBBlinkIDRecognizer.h
//
// Created by juraskrlec on 06/05/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBBlinkIdRecognizerResult.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

@protocol MBBlinkIdRecognizerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
* The Blink ID Recognizer is used for scanning Blink ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBlinkIdRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning BlinkIDRecognizer
 */
@property (nonatomic, strong, readonly) MBBlinkIdRecognizerResult *result;

/**
 * Called with dewarped full document image
 */
- (void)setDewarpedImageDelegate:(nullable id<MBBlinkIdRecognizerDelegate>)delegate;

/**
 * Called when document is not supported
 */
- (void)setClassifierDelegate:(nullable id<MBBlinkIdRecognizerDelegate>)delegate;

@end

@protocol MBBlinkIdRecognizerDelegate <NSObject>
@optional
- (void)onImageAvailable:(nullable MBImage *)dewarpedImage;
- (void)onDocumentSupportStatus:(BOOL)isDocumentSupported;
@end

NS_ASSUME_NONNULL_END
