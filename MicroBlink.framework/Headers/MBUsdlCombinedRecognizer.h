//
//  MBUsdlCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBRecognizer.h"
#import "MBUsdlCombinedRecognizerResult.h"
#import "MBCombinedRecognizer.h"

#import "MBDocumentFaceDetectorType.h"

#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFaceImage.h"
#import "MBFaceImageDpi.h"

#import "MBDigitalSignature.h"

#import "MBEncodeFaceImage.h"
#import "MBEncodeFullDocumentImage.h"

#import <Foundation/Foundation.h>

/**
 * USDL Combined Recognizer.
 *
 * USDL Combined recognizer is used for scanning both front and back side of US Driver's License.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBUsdlCombinedRecognizer : MBRecognizer<NSCopying, MBCombinedRecognizer, MBFullDocumentImage, MBFullDocumentImageDpi, MBFaceImage, MBFaceImageDpi, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBDigitalSignature>

/**
 * Result of scanning both sides of USDL
 */
@property (nonatomic, strong, readonly) MBUsdlCombinedRecognizerResult* result;

/**
 * Set this to YES to scan even barcode not compliant with standards
 * For example, malformed USDL barcodes which were incorrectly encoded
 *
 * Use only if necessary because it slows down the recognition process
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL scanUncertain;

/**
 * Set this to YES to scan barcodes which don't have quiet zone (white area) around it
 *
 * Use only if necessary because it slows down the recognition process
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL allowNullQuietZone;

/**
 * Type of document this recognizer will scan.
 *
 * Default: MBDocumentFaceDetectorTypeTD1
 */
@property (nonatomic, assign) MBDocumentFaceDetectorType type;

MB_INIT



@end
