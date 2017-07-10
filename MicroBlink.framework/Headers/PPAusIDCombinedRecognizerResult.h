//
//  PPAusIDCombinedRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 19/06/2017.
//
//

#import "PPRecognizerResult.h"

/**
 * Result of scanning with Austrian ID Combined recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPAusIDCombinedRecognizerResult : PPRecognizerResult
/**
 * The first name of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The document number of the Austrian ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The sex of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The date of birth of Austrian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The place of birth of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The issuing authority of Austrian ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The principal residence of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *principalResidence;

/**
 * The height of Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *height;

/**
 * The date of issue of Austrian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The date of expiry of Austrian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfExpiry;

/**
 * The eye color of Austrian ID owner.
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
