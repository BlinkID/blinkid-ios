//
//  PPSlovenianIDCombinedRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 20/06/2017.
//
//

#import "PPRecognizerResult.h"

/**
 * Result of scanning with Slovenian ID Combined recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSlovenianIDCombinedRecognizerResult : PPRecognizerResult

/**
 * The first name of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The identity card number of Slovenian ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The sex of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The nationality of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *citizenship;

/**
 * The date of birth of Slovenian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The date of expiry of Slovenian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfExpiry;

/**
 * The address of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The PIN of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *personalIdentificationNumber;

/**
 * The issuing authority of Slovenian ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The date of issue of Slovenian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfIssue;

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
