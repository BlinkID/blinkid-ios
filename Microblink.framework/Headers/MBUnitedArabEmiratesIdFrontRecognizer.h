//
//  MBUnitedArabEmiratesIdFrontRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 28/05/2018.
//

#import "MBRecognizer.h"
#import "MBUnitedArabEmiratesIdFrontRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring United Arab Emirates ID Front Recognizer.
 *
 * United Arab Emirates ID Front recognizer is used for scanning front side of United Arab Emirates ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBUnitedArabEmiratesIdFrontRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBFullDocumentImageDpi, MBFaceImage, MBFaceImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * United Arab Emirates ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBUnitedArabEmiratesIdFrontRecognizerResult *result;

/**
 * Defines if owner's name should be extracted from front side of United Arab Emirates ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if owner's nationality should be extracted from front side of United Arab Emirates ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

@end

NS_ASSUME_NONNULL_END
