//
//  PPSwissPassportRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 27/07/2017.
//
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning of Swiss Passport
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSwissPassportRecognizerResult : PPDetectorRecognizerResult

/**
 * The surname of the Swiss Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The name of the Swiss Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The place of origin of the Swiss Passport owner
 */
@property (nonatomic, readonly, nullable) NSString *placeOfOrigin;

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
