//
//  PPMyKadRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Jura on 16/12/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"

/**
 * Result of scanning MyKad (Malaysian ID document).
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPMyKadRecognizerResult : PPRecognizerResult

/**
 * NRIC number (National Registration Identity Card Number)
 *
 *  @see https://en.wikipedia.org/wiki/Malaysian_identity_card#Structure_of_the_National_Registration_Identity_Card_Number_.28NRIC.29
 */
@property (nonatomic, readonly, nullable) NSString *nricNumber;

/**
 * Owner address
 */
@property (nonatomic, readonly, nullable) NSString *ownerAddress;

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
