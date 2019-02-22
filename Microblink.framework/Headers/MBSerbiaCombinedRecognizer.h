//
//  MBSerbiaCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSerbiaCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBSignatureImage.h"
#import "MBFaceImage.h"

#import "MBDigitalSignature.h"

#import "MBEncodeFaceImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBEncodeSignatureImage.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Serbian ID Combined Recognizer.
 *
 * Serbian ID Combined recognizer is used for scanning both front and back side of Serbian ID.
 */
MB_CLASS_DEPRECATED_IOS(1.0.0, 4.6.0, "Recognizer is deprecated")
@interface MBSerbiaCombinedRecognizer : MBLegacyRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFullDocumentImage, MBSignatureImage, MBFaceImage, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBEncodeSignatureImage, MBDigitalSignature>

MB_INIT

/**
 * Serbian ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBSerbiaCombinedRecognizerResult* result;

@end

NS_ASSUME_NONNULL_END
