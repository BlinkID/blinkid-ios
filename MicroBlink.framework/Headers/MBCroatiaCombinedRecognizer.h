//
//  MBCroatiaCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBMicroBlinkDefines.h"
#import "MBLegacyRecognizer.h"
#import "MBMicroBlinkInitialization.h"
#import "MBCroatiaCombinedRecognizerResult.h"

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

/**
 * Croatian ID Combined Recognizer.
 *
 * Croatian ID Combined recognizer is used for scanning both front and back side of Croatian ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCroatiaCombinedRecognizer : MBLegacyRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFullDocumentImage, MBSignatureImage, MBFaceImage, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBEncodeSignatureImage, MBDigitalSignature>

MB_INIT

/**
 * Croatian ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBCroatiaCombinedRecognizerResult* result;

@end
