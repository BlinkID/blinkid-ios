//
//  MBMalaysiaDlFrontRecognizer.h
//  MicroblinkDev
//
//  Created by juraskrlec on 20/09/2018.
//

#import "MBRecognizer.h"
#import "MBMalaysiaDlFrontRecognizerResult.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer which can scan front side of Malaysian DL cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMalaysiaDlFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Malaysia Dl Front Recognizer
 */
@property (nonatomic, strong, readonly) MBMalaysiaDlFrontRecognizerResult *result;

/**
 * Defines if address of Malaysian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if vehicle classes of Malaysian DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractClass;

/**
 * Defines if name of Malaysian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if nationality of Malaysian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if date of issue of Malaysian DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidFrom;

/**
 * Defines if date of expiry of Malaysian DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidUntil;

@end

NS_ASSUME_NONNULL_END
