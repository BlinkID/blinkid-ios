//
//  MBSloveniaCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSloveniaCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBSignatureImage.h"
#import "MBFaceImage.h"

#import "MBDigitalSignature.h"

#import "MBEncodeFaceImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBEncodeSignatureImage.h"


/**
 * Slovenian ID Combined Recognizer.
 *
 * Slovenian ID Combined recognizer is used for scanning both front and back side of Slovenian ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSloveniaCombinedRecognizer : MBLegacyRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFullDocumentImage, MBSignatureImage, MBFaceImage, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBEncodeSignatureImage, MBDigitalSignature>

MB_INIT

/**
 * Slovenian ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBSloveniaCombinedRecognizerResult* result;

@end
