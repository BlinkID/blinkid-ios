//
//  PPMyKadRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Jura on 16/12/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

PP_CLASS_AVAILABLE_IOS(6.0) @interface PPMyKadRecognizerResult : PPRecognizerResult

/**
 * Returns NRIC number (National Registration Identity Card Number)
 *
 *  @see https://en.wikipedia.org/wiki/Malaysian_identity_card#Structure_of_the_National_Registration_Identity_Card_Number_.28NRIC.29
 *
 *  @return NRIC number
 */
- (NSString *)nricNumber;

/**
 * Returns owner address
 *
 *  @return owner address
 */
- (NSString *)ownerAddress;

/**
 * Returns owner birth date (YYMMDD format)
 *
 *  @return ownedr birth date
 */
- (NSString *)ownerBirthDate;

/**
 * Returns owner full name
 *
 *  @return owner full name
 */
- (NSString *)ownerFullName;

/**
 * Returns owner religion if written on MyKad
 *
 *  @return owner religion
 */
- (NSString *)ownerReligion;

/**
 * Returns owner sex (M for male, F for female)
 *
 *  @return owner sex
 */
- (NSString *)ownerSex;

@end

NS_ASSUME_NONNULL_END
