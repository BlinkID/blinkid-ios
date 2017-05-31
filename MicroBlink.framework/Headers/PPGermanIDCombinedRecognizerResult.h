//
//  PPGermanIDCombinedRecognizerResult.h
//  PhotoPayDev
//
//  Created by Jura Skrlec on 22/05/2017.
//
//

#import "PPRecognizerResult.h"

/**
 * Result of scanning with German ID Combined recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPGermanIDCombinedRecognizerResult : PPRecognizerResult

/**
 * The first name of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The nationality of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The place of birth of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The sex of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The date of birth of German ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The date of issue of German ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfIssue;

/**
 * The date of expiry of German ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfExpiry;

/**
 * The identity card number of German ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The address of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The issuing authority of German ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The height of German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *height;

/**
 * The eye color of German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *eyeColor;

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
