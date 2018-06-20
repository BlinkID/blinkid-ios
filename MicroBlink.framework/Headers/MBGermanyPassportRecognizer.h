//
//  MBGermanyPassportRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBGermanyPassportRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBSignatureImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring German Passport Recognizer.
 *
 * German Passport recognizer is used for scanning German Passport.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyPassportRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBSignatureImage, MBFullDocumentImage, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * German Passport recognizer result
 */
@property (nonatomic, strong, readonly) MBGermanyPassportRecognizerResult *result;

/**
 * Defines if owner's surname should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if owner's name should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if owner's nationality should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if owner's place of birth should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if date of issue should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if authority should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAuthority;

@end

NS_ASSUME_NONNULL_END
