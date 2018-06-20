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

@end
