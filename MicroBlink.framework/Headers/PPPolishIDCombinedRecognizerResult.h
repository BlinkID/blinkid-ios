//
//  PPPolishIDCombinedRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 19/10/2017.
//

#import "PPRecognizerResult.h"

/**
 * Result of scanning with Polish ID Combined recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPPolishIDCombinedRecognizerResult : PPRecognizerResult

/**
 * The first name of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The family name of Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *familyName;

/**
 * The parents name of Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *parentsName;

/**
 * The sex of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The nationality of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The issuing authority of Polish ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The issuing authority of Polish ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The issuing authority of Polish ID.
 */
@property (nonatomic, readonly, nullable) NSString *personalNumber;

/**
 * The date of birth of Polish ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The document date of expiry of the Polish ID
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfExpiry;

/**
 * YES if all check digits inside MRZ are correct, NO otherwise.
 * More specifically, YES if MRZ complies with ICAO Document 9303 standard, NO otherwise.
 */
@property (nonatomic, readonly) BOOL mrtdVerified;

/**
 * YES if Data from the front side is matching the data from the back side
 */
@property (nonatomic, readonly) BOOL matchingData;

/**
 * Contains signature which confirms that this data originates from the SDK
 */
@property (nonatomic, readonly, nullable) NSData *signature;

/**
 * Contains the version of the signature
 */
@property (nonatomic, readonly, nullable) NSString *signatureVersion;

/**
 * Byte buffer with face image
 */
@property (nonatomic, readonly, nullable) NSData *faceImage;

@end
