//
//  MBSingaporeCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBMicroBlinkDefines.h"
#import "MBLegacyRecognizer.h"
#import "MBMicroBlinkInitialization.h"
#import "MBSingaporeCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBFaceImage.h"

#import "MBDigitalSignature.h"

#import "MBEncodeFaceImage.h"
#import "MBEncodeFullDocumentImage.h"

#import <Foundation/Foundation.h>

/**
 * Singapore ID Combined Recognizer.
 *
 * Singapore ID Combined recognizer is used for scanning both front and back side of Singapore ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSingaporeCombinedRecognizer : MBLegacyRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFullDocumentImage, MBFaceImage, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBDigitalSignature>

MB_INIT

/**
 * Singapore ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBSingaporeCombinedRecognizerResult* result;

@end
