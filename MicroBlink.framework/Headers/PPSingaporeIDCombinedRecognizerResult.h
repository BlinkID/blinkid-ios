//
//  PPSingaporeIDCombinedRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 19/06/2017.
//
//

#import "PPRecognizerResult.h"

/**
 * Result of scanning with Singapore ID Combined recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSingaporeIDCombinedRecognizerResult : PPRecognizerResult

/**
 * The first name of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The name of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The blood group of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *bloodGroup;

/**
 * The sex of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The country of birth of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *countryOfBirth;

/**
 * The race of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *race;

/**
 * The identity card number of Singapore ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;


/**
 * The date of birth of Singapore ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The date of issue of Singapore ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfIssue;

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
