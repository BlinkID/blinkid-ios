//
//  MBSwitzerlandPassportRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSwitzerlandPassportRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Swiss Passport Recognizer.
 *
 * Swiss Passport recognizer is used for scanning Swiss Passport.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwitzerlandPassportRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Swiss Passport recognizer result
 */
@property (nonatomic, strong, readonly) MBSwitzerlandPassportRecognizerResult *result;

/**
 * Defines if owner's surname should be extracted from Swiss Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if owner's name should be extracted from Swiss Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractGivenName;

/**
 * Defines if owner's place of birth should be extracted from Swiss Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if date of issue should be extracted from Swiss Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if date of birth should be extracted from Swiss Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if date of expiry should be extracted from Swiss Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if authority should be extracted from Swiss Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAuthority;

/**
 * Defines if passport number should be extracted from Swiss Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPassportNumber;

/**
 * Defines if sex should be extracted from Swiss Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if height should be extracted from Swiss Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractHeight;

@end

NS_ASSUME_NONNULL_END
