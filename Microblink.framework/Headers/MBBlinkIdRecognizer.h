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
* Full document dewarped imagedelegate
*/
@property (nonatomic, nullable, weak) id<MBBlinkIdRecognizerDelegate> dewarpedImageDelegate;

/**
* Document not supported classifier delegate
*/
@property (nonatomic, nullable, weak) id<MBBlinkIdRecognizerDelegate> classifierDelegate;

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

@protocol MBBlinkIdRecognizerDelegate <NSObject>
@optional
- (void)onImageAvailable:(nullable MBImage *)dewarpedImage;
- (void)onDocumentSupportStatus:(BOOL)isDocumentSupported;
@end

NS_ASSUME_NONNULL_END
