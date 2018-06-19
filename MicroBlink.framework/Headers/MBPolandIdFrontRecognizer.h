//
//  MBPolandIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBPolandIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Polish ID Front Recognizer.
 *
 * Polish ID Front recognizer is used for scanning front side of Polish ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBPolandIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Polish ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBPolandIdFrontRecognizerResult *result;

/**
 *  Defines if sex of Polish ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if citizenship of Polish ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if date of birth of Polish ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractGivenNames;

/**
 * Defines if date of expiry should be extracted from Polish ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFamilyName;

/**
 * Defines if date of expiry should be extracted from Polish ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractParentsGivenNames;

/**
 * Defines if date of expiry should be extracted from Polish ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

@end

NS_ASSUME_NONNULL_END
