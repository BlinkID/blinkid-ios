//
//  MBJordanIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBJordanIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBFaceImage.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageDpi.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Jordan ID Front Recognizer.
 *
 * Jordan ID Front recognizer is used for scanning front side of Jordan ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBJordanIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBFaceImage, MBGlareDetection, MBFullDocumentImageDpi>

MB_INIT

/**
 * Jordan ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBJordanIdFrontRecognizerResult *result;

/**
 * Defines if owner's name should be extracted from Jordan ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if owner's sex should be extracted from Jordan ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if owner's date of birth should be extracted from Jordan ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

@end

NS_ASSUME_NONNULL_END
