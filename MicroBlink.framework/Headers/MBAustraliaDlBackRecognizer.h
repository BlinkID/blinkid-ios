//
//  MBAustraliaDlBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBAustraliaDlBackRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Australia DL Back Recognizer.
 *
 * Australia DL Back recognizer is used for scanning back side of Australia DL.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustraliaDlBackRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBFullDocumentImageDpi>

MB_INIT

/**
 * Australia DL Back recognizer result
 */
@property (nonatomic, strong, readonly) MBAustraliaDlBackRecognizerResult *result;

/**
 *  Defines if last name of Australian DL owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractLastName;

/**
 *  Defines if sex of Australian DL owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if date of expiry should be extracted from Australian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

@end

NS_ASSUME_NONNULL_END
