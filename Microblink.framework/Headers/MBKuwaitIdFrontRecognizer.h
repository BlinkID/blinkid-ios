//
//  MBKuwaitIdFrontRecognizer.h
//  MicroblinkDev
//
//  Created by juraskrlec on 21/08/2018.
//

#import "MBRecognizer.h"
#import "MBKuwaitIdFrontRecognizerResult.h"

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
 * Recognizer which can scan front side of Kuwait national ID cards.

 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBKuwaitIdFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Kuwait Id Front Recognizer
 */
@property (nonatomic, strong, readonly) MBKuwaitIdFrontRecognizerResult *result;

/**
 * Defines if date of birth of Kuwait ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractBirthDate;

/**
 * Defines if name of Kuwait ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if nationality of Kuwait ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if sex of Kuwait ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
