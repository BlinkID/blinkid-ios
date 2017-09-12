//
//  PPAusPassportRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 24/07/2017.
//
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning of Austrian Passport
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPAusPassportRecognizerResult : PPDetectorRecognizerResult

/**
 * The surname of the Austrian Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The name of the Austrian Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The nationality of the Austrian Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The place of birth of the Austrian Passport owner
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
 * The sex of the Austrian Passport owner
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The height of the Austrian Passport owner
 */
@property (nonatomic, readonly, nullable) NSString *height;

@end
