//
// MBBlinkIDRecognizer.h
//
// Created by juraskrlec on 06/05/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBBlinkIdRecognizerResult.h"
#import "MBClassInfo.h"

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
 * Class filter delegate
 */
@property (nonatomic, nullable, weak) id<MBBlinkIdRecognizerDelegate> classFilterDelegate;

/**
 * Barcode started scanning delegate
 */
@property (nonatomic, nullable, weak) id<MBBlinkIdRecognizerDelegate> barcodeScanningStartedDelegate;

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

/**
 * Pading is a minimum distance from the edge of the frame and is defined as a percentage of the frame width. Default value is 0.0f and in that case
 * padding edge and image edge are the same.
 * Recommended value is 0.02f.
 *
 * Default: 0.0f
 */
@property (nonatomic, assign) CGFloat paddingEdge;

/**
 * Defines whether result characters validatation is performed.
 * If a result member contains invalid character, the result state cannot be valid
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL validateResultCharacters;

/**
 * Defines whether sensitive data should be anonymized in full document image result.
 * The setting only applies to certain documents
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL anonymizeImage;

@end

@protocol MBBlinkIdRecognizerDelegate <NSObject>
@optional

/**
 * Called when dewarped full document image is available
*/
- (void)onImageAvailable:(nullable MBImage *)dewarpedImage;

/**
 * Called when recognizer classifies document.
 *  @param isDocumentSupported - true if supported, false otherwise
*/
- (void)onDocumentSupportStatus:(BOOL)isDocumentSupported;

/**
 * Called when recognizer classifies document as a supported class.
 * Enables filtering based on class.
 * @param classInfo - classInfo of the document
*/
- (BOOL)classInfoFilter:(nullable MBClassInfo *)classInfo;

/**
 * Called when barcode scanning step starts.
 */
- (void)onBarcodeScanningStarted;

@end

NS_ASSUME_NONNULL_END
