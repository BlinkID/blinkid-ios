//
//  MBSwitzerlandPassportRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyMRTDRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning Swiss Passport
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwitzerlandPassportRecognizerResult : MBLegacyMRTDRecognizerResult<NSCopying, MBFaceImageResult, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The surname of the Swiss Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *surname;

/**
 * The name of the Swiss Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *givenName;

/**
 * The place of birth of the Swiss Passport owner
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * Raw date of issue, as written on the passport
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfIssue;

/**
 * Date of issue in NSDate object
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * Raw date of birth, as written on the passport
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * Date of birth in NSDate object
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * Raw date of expiry, as written on the passport
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfExpiry;

/**
 * Date of expiry in NSDate object
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * Issuing authority of the Passport
 */
@property (nonatomic, readonly, nullable) NSString *authority;

/**
 * Number of the Passport
 */
@property (nonatomic, readonly, nullable) NSString *passportNumber;

/**
 * The sex of the Swiss Passport owner
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The height of the Swiss Passport owner
 */
@property (nonatomic, readonly, nullable) NSString *height;

@end

NS_ASSUME_NONNULL_END
