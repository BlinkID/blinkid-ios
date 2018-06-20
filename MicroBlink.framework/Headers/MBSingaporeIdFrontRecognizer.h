//
//  MBSingaporeIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSingaporeIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBFaceImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Singapore ID Front Recognizer.
 *
 * Singapore ID Front recognizer is used for scanning front side of Singapore ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBFaceImage, MBGlareDetection>

MB_INIT

/**
 * Singapore ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBSingaporeIdFrontRecognizerResult *result;

/**
 *  Defines if race of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractRace;

/**
 *  Defines if date of birth of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractDateOfBirth;

/**
 *  Defines if sex of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractSex;

/**
 *  Defines if country of birth of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractCountryOfBirth;

@end

NS_ASSUME_NONNULL_END
