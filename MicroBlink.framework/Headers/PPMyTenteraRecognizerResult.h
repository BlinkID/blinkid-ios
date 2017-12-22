//
//  PPMyTenteraRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 21/12/2017.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of MyTentera
 */
PP_CLASS_AVAILABLE_IOS(6.0)

@interface PPMyTenteraRecognizerResult : PPDetectorRecognizerResult

/**
 * NRIC number (National Registration Identity Card Number)
 *
 *  @see https://en.wikipedia.org/wiki/Malaysian_identity_card#Structure_of_the_National_Registration_Identity_Card_Number_.28NRIC.29
 */
@property (nonatomic, readonly, nullable) NSString *nricNumber;

/**
 * Owner army number
 */
@property (nonatomic, readonly, nullable) NSString *armyNumber;

/**
 * Owner address
 */
@property (nonatomic, readonly, nullable) NSString *ownerAddress;

/**
 * Owner address city. Determined from owner address.
 */
@property (nonatomic, readonly, nullable) NSString *ownerAddressCity;

/**
 * Owner address state. Determined from owner address.
 */
@property (nonatomic, readonly, nullable) NSString *ownerAddressState;

/**
 * Owner address Zip code. Determined from owner address.
 */
@property (nonatomic, readonly, nullable) NSString *ownerAddressZipCode;

/**
 * Owner street. Determined from owner address.
 */
@property (nonatomic, readonly, nullable) NSString *ownerAddressStreet;

/**
 * Owner birth date string, as written on the document (YYMMDD format)
 */
@property (nonatomic, readonly, nullable) NSString *rawOwnerBirthDate;

/**
 * Owner birth date converted in NSDate object
 */
@property (nonatomic, readonly, nullable) NSDate *ownerBirthDate;

/**
 * Owner full name
 */
@property (nonatomic, readonly, nullable) NSString *ownerFullName;

/**
 * Owner religion if written on MyKad
 */
@property (nonatomic, readonly, nullable) NSString *ownerReligion;

/**
 * Owner sex (M for male, F for female)
 */
@property (nonatomic, readonly, nullable) NSString *ownerSex;

@end
