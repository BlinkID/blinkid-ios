//
//  MBDocumentFaceRecognizerRecognizerResult.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 18/06/2018.
//

#import "MBRecognizerResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBFaceImageResult.h"
#import "MBQuadrangle.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning Document Face Recognizer
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDocumentFaceRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBFaceImageResult>

MB_INIT_UNAVAILABLE


/**
 * Quadrangle represeting corner points of the document within the input image.
 */
@property (nonatomic, readonly) MBQuadrangle *documentLocation;

/**
 * Quadrangle represeting corner points of the face image within the input image.
 */
@property (nonatomic, readonly) MBQuadrangle *faceLocation;

@end

NS_ASSUME_NONNULL_END
