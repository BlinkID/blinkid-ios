//
//  MBAustraliaDlFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBAustraliaDlFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBSignatureImage.h"
#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Australia DL Front Recognizer.
 *
 * Australia DL Front recognizer is used for scanning front side of Australia DL.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustraliaDlFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBSignatureImage, MBFullDocumentImage, MBFullDocumentImageDpi>

MB_INIT

/**
 * Australia DL Front recognizer result
 */
@property (nonatomic, strong, readonly) MBAustraliaDlFrontRecognizerResult *result;

/**
 *  Defines if sex of Australian DL owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if date of birth of Australian DL owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if date of expiry should be extracted from Australian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

@end

NS_ASSUME_NONNULL_END
