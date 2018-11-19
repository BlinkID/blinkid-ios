//
//  MBMrtdCombinedRecognizer.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 13/06/2018.
//

#import "MBMicroBlinkDefines.h"
#import "MBLegacyRecognizer.h"
#import "MBMicroBlinkInitialization.h"
#import "MBMrtdCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBFullDocumentImage.h"
#import "MBSignatureImage.h"
#import "MBFaceImage.h"
#import "MBMrzImage.h"

#import "MBDigitalSignature.h"

#import "MBEncodeFaceImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBEncodeSignatureImage.h"
#import "MBEncodeMrzImage.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * MRTD Combined recognizer
 *
 * MRTD Combined recognizer is used for scanning both front and back side of generic IDs.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBMrtdCombinedRecognizer : MBLegacyRecognizer<NSCopying, MBCombinedRecognizer, MBFullDocumentImage, MBFaceImage, MBMrzImage, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBDigitalSignature>

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
 * Defines how many times the same document should be detected before the detector
 * returns this document as a result of the deteciton
 *
 * Higher number means more reliable detection, but slower processing
 *
 * Default: 6
 */
@property (nonatomic, assign) NSUInteger numStableDetectionsThreshold;

@end

NS_ASSUME_NONNULL_END
