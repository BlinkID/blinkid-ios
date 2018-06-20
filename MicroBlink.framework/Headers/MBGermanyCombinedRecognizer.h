//
//  MBGermanyCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBGermanyCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageExtensionFactors.h"
#import "MBSignatureImage.h"
#import "MBFaceImage.h"

#import "MBDigitalSignature.h"

#import "MBEncodeFaceImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBEncodeSignatureImage.h"

/**
 * German ID Combined Recognizer.
 *
 * German ID Combined recognizer is used for scanning both front and back side of German ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBGermanyCombinedRecognizer : MBLegacyRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFullDocumentImage, MBSignatureImage, MBFaceImage, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBEncodeSignatureImage, MBDigitalSignature, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * German ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBGermanyCombinedRecognizerResult* result;

/**
 * Defines if owner's address should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

@end
