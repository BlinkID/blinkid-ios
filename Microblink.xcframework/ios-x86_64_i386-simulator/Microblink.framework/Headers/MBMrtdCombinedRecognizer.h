//
//  MBMrtdCombinedRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 13/06/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBRecognizer.h"
#import "MBMicroblinkInitialization.h"
#import "MBMrtdCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBGlareDetection.h"
#import "MBDigitalSignature.h"

#import "MBDocumentFaceDetectorType.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"
#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"

@protocol MBMrzCombinedFilter;

NS_ASSUME_NONNULL_BEGIN

/**
 * MRTD Combined recognizer
 *
 * MRTD Combined recognizer is used for scanning both front and back side of generic IDs.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBMrtdCombinedRecognizer : MBRecognizer<NSCopying, MBCombinedRecognizer, MBDigitalSignature, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi>

MB_INIT

/**
 * Mrtd Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBMrtdCombinedRecognizerResult* result;

/**
 * Whether returning of unparsed results is allowed
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL allowUnparsedResults;

/**
 * Whether returning of unverified results is allowed
 * Unverified result is result that is parsed, but check digits are incorrect.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL allowUnverifiedResults;

/**
 * Whether special characters are allowed
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL allowSpecialCharacters;

/**
 * Defines how many times the same document should be detected before the detector
 * returns this document as a result of the deteciton
 *
 * Higher number means more reliable detection, but slower processing
 *
 * Default: 6
 */
@property (nonatomic, assign) NSUInteger numStableDetectionsThreshold;

/**
 * Type of document this recognizer will scan.
 *
 * Default: MBDocumentFaceDetectorTypeTD1
 */
@property (nonatomic, assign) MBDocumentFaceDetectorType detectorType;

/**
* Filter for MRTDs (Machine Readable Travel Documents) that is used to determine which documents
* will be processed. If document is filtered out by this filter, its data cannot be returned as recognition result.
*/
@property (nonatomic, nullable, weak) id<MBMrzCombinedFilter> mrzCombinedFilterDelegate;

@end

@protocol MBMrzCombinedFilter <NSObject>
@required
/**
 * Determines whether document should be processed or it is filtered out.
 * @return YES if the document with the given MRZ should be processed, NO if the document
 * should be filtered out.
 */
- (BOOL)mrzCombinedFilter;
@end

NS_ASSUME_NONNULL_END
