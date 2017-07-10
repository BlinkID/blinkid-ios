//
//  PPSerbianIDCombinedRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 19/06/2017.
//
//
#import "PPRecognizerResult.h"

/**
 * Result of scanning with Serbian ID Combined recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSerbianIDCombinedRecognizerResult : PPRecognizerResult

/**
 * The identity card number of Serbian ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The date of expiry of Serbian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfExpiry;


/**
 * The date of issue of Serbian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfIssue;

/**
 * The JMBG of Serbian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *JMBG;

/**
 * The first name of the Serbian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Serbian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The date of birth of Serbian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The nationality of the Serbian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The issuing authority of Serbian ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The sex of the Serbian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

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
