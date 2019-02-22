//
//  MBSloveniaIdFrontRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSloveniaIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBSignatureImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Slovenian ID Front Recognizer.
 *
 * Slovenian ID Front recognizer is used for scanning front side of Slovenian ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBSloveniaIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBSignatureImage, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Slovenian ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBSloveniaIdFrontRecognizerResult *result;

/**
 *  Defines if sex of Slovenian ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractSex;

/**
 *  Defines if nationality of Slovenian ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractNationality;

/**
 *  Defines if date of birth of Slovenian ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractDateOfBirth;

/**
 *  Defines if date of expiry of Slovenian ID should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractDateOfExpiry;

@end

NS_ASSUME_NONNULL_END
