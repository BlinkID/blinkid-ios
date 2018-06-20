//
//  MBCzechiaIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBCzechiaIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBSignatureImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Cz ID Front Recognizer.
 *
 * Cz ID Front recognizer is used for scanning front side of Cz ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBCzechiaIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBSignatureImage, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Cz ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBCzechiaIdFrontRecognizerResult *result;

/**
 *  Defines if sex of Czech ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if surname of Czech ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if given names of Czech ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractGivenNames;

/**
 * Defines if date of expiry should be extracted from Czech ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if date of issue should be extracted from Czech ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if date of expiry should be extracted from Czech ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if place of birth should be extracted from Czech ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

@end

NS_ASSUME_NONNULL_END
