//
//  MBDocumentFaceRecognizerRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 18/06/2018.
//

#import "MBRecognizer.h"
#import "MBDocumentFaceRecognizerResult.h"
#import "MBDocumentFaceDetectorType.h"

#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Document Face Recognizer Recognizer.
 *
 * Document Face Recognizer recognizer is used for scanning documents containing face images.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_CLASS_DEPRECATED("Use MBBlinkIdRecognizer with photoID right.") MB_FINAL
@interface MBDocumentFaceRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBFullDocumentImageDpi, MBFaceImage, MBFaceImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Document Face Recognizer
 */
@property (nonatomic, strong, readonly) MBDocumentFaceRecognizerResult *result;

/**
 * Type of docment this recognizer will scan.
 *
 * Default: MBDocumentFaceDetectorTypeTD1
 */
@property (nonatomic, assign) MBDocumentFaceDetectorType detectorType;

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
