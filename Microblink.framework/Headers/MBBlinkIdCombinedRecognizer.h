//
//  MBBlinkIdCombinedRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 18/06/2019.
//

#import "MBRecognizer.h"
#import "MBBlinkIdCombinedRecognizerResult.h"
#import "MBClassInfo.h"

#import "MBCombinedRecognizer.h"
#import "MBDigitalSignature.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"
#import "MBAnonymizationMode.h"
#import "MBRecognitionModeFilter.h"
#import "MBSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBEncodeSignatureImage.h"

@protocol MBBlinkIdCombinedRecognizerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer which can scan front and back side of the United States driver license.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBlinkIdCombinedRecognizer : MBRecognizer<NSCopying, MBCombinedRecognizer, MBDigitalSignature, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

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
 * Class filter delegate
 */
@property (nonatomic, nullable, weak) id<MBBlinkIdCombinedRecognizerDelegate> classFilterDelegate;

/**
 * Barcode started scanning delegate
 */
@property (nonatomic, nullable, weak) id<MBBlinkIdCombinedRecognizerDelegate> barcodeScanningStartedDelegate;

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
 * Skip back side capture and processing step when back side of the document is not supported
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL skipUnsupportedBack;

/**
 * Defines whether result characters validatation is performed.
 * If a result member contains invalid character, the result state cannot be valid
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL validateResultCharacters;

/**
 * Defines whether sensitive data should be removed from images, result fields or both.
 * The setting only applies to certain documents
 *
 * Default: MBAnonymizationModeFullResult
 */
@property (nonatomic, assign) MBAnonymizationMode anonymizationMode;

/**
 * Enable or disable recognition of specific document groups supported by the current license.
 *
 * Default: all modes are enabled
 */
@property (nonatomic, strong) MBRecognitionModeFilter *recognitionModeFilter;

@end

@protocol MBBlinkIdCombinedRecognizerDelegate <NSObject>
@optional

/**
 * Called when dewarped full document image is available
*/
- (void)onCombinedImageAvailable:(nullable MBImage *)dewarpedImage;

/**
 * Called when recognizer classifies document.
 *  @param isDocumentSupported - true if supported, false otherwise
*/
- (void)onCombinedDocumentSupportStatus:(BOOL)isDocumentSupported;

/**
 * Called when recognizer classifies document as a supported class.
 * Enables filtering based on class.
 * @param classInfo - classInfo of the document
*/
- (BOOL)combinedClassInfoFilter:(nullable MBClassInfo *)classInfo;

/**
 * Called when barcode scanning step starts.
 */
- (void)onCombinedBarcodeScanningStarted;

@end

NS_ASSUME_NONNULL_END
