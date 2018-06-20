//
//  MBDocumentFaceRecognizerRecognizer.h
//  MicroBlinkDev
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


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Document Face Recognizer Recognizer.
 *
 * Document Face Recognizer recognizer is used for scanning documents containing face images.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBDocumentFaceRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBFullDocumentImageDpi, MBFaceImage, MBFaceImageDpi>

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

@end

NS_ASSUME_NONNULL_END
