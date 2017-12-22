//
//  PPMyKadBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 21/12/2017.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Result of scanning MyKad Back (Malaysian ID document).
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPMyKadBackRecognizerResult : PPDetectorRecognizerResult

/**
 * NRIC number (National Registration Identity Card Number)
 *
 *  @see https://en.wikipedia.org/wiki/Malaysian_identity_card#Structure_of_the_National_Registration_Identity_Card_Number_.28NRIC.29
 */
@property (nonatomic, readonly, nullable) NSString *nricNumber;

/**
 * Extended NRIC number (National Registration Identity Card Number)
 *
 *  @see https://en.wikipedia.org/wiki/Malaysian_identity_card#Structure_of_the_National_Registration_Identity_Card_Number_.28NRIC.29
 */
@property (nonatomic, readonly, nullable) NSString *extendedNricNumber;

/**
 * Owner birth date string, as written on the document (YYMMDD format)
 */
@property (nonatomic, readonly, nullable) NSString *rawOwnerBirthDate;

/**
 * Owner birth date converted in NSDate object
 */
@property (nonatomic, readonly, nullable) NSDate *ownerBirthDate;

/**
 * Owner sex (M for male, F for female)
 */
@property (nonatomic, readonly, nullable) NSString *ownerSex;

@end
