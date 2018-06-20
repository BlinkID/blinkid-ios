//
//  MBMalaysiaDlFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBMalaysiaDlFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFaceImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Malaysian DL Front Recognizer.
 *
 * Malaysian DL Front recognizer is used for scanning front side of Malaysian DL.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBMalaysiaDlFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBFaceImage, MBGlareDetection, MBFullDocumentImageDpi>

MB_INIT

/**
 * Malaysian DL Front recognizer result
 */
@property (nonatomic, strong, readonly) MBMalaysiaDlFrontRecognizerResult *result;

/**
 * Defines if owner's name should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if owner's nationality should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if owner's license class should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDlClass;

/**
 * Defines if owner's valid from should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidFrom;

/**
 * Defines if owner's valid until should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidUntil;

/**
 * Defines if owner's full address should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFullAddress;

@end

NS_ASSUME_NONNULL_END
