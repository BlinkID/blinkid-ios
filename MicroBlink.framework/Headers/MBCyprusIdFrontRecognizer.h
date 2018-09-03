//
//  MBCyprusIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by juraskrlec on 21/08/2018.
//

#import "MBRecognizer.h"
#import "MBCyprusIdFrontRecognizerResult.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer which can scan front side of Cyprus national ID cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCyprusIdFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection>

MB_INIT

/**
 * Result of scanning Cyprus Id Front Recognizer
 */
@property (nonatomic, strong, readonly) MBCyprusIdFrontRecognizerResult *result;

/**
 * Defines if document number of Cyprus ID card should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDocumentNumber;

/**
 * Defines if name of Cyprus ID card owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if surname of Cyprus ID card owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
