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
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPMyKadRecognizerResult : PPRecognizerResult

/**
 * Returns NRIC number (National Registration Identity Card Number)
 *
 *  @see https://en.wikipedia.org/wiki/Malaysian_identity_card#Structure_of_the_National_Registration_Identity_Card_Number_.28NRIC.29
 *
 *  @return NRIC number
 */
- (NSString * _Nullable)nricNumber;

/**
 * Returns owner address
 *
 *  @return owner address
 */
- (NSString * _Nullable)ownerAddress;

/**
 * Returns owner birth date (YYMMDD format)
 *
 *  @return ownedr birth date
 */
- (NSString * _Nullable)ownerBirthDate;

/**
 * Returns owner full name
 *
 *  @return owner full name
 */
- (NSString * _Nullable)ownerFullName;

/**
 * Returns owner religion if written on MyKad
 *
 *  @return owner religion
 */
- (NSString * _Nullable)ownerReligion;

/**
 * Returns owner sex (M for male, F for female)
 *
 *  @return owner sex
 */
- (NSString * _Nullable)ownerSex;

@end
