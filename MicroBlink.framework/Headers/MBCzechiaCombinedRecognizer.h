//
//  MBCzechiaCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBMicroBlinkDefines.h"
#import "MBLegacyRecognizer.h"
#import "MBMicroBlinkInitialization.h"
#import "MBCzechiaCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBSignatureImage.h"
#import "MBFaceImage.h"

#import "MBDigitalSignature.h"

#import "MBEncodeFaceImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBEncodeSignatureImage.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Czech ID Combined Recognizer.
 *
 * Czech ID Combined recognizer is used for scanning both front and back side of Czech ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCzechiaCombinedRecognizer : MBLegacyRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFullDocumentImage, MBSignatureImage, MBFaceImage, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBEncodeSignatureImage, MBDigitalSignature>

MB_INIT

/**
 * Czech ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBCzechiaCombinedRecognizerResult* result;

@end

NS_ASSUME_NONNULL_END
