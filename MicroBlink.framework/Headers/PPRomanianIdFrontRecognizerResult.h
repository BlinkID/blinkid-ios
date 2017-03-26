//
//  PPRomanianIdFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Jura on 22/03/17.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPMrtdRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Romanian ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPRomanianIdFrontRecognizerResult : PPMrtdRecognizerResult

/**
 * Last name
 */
@property (nonatomic, strong, readonly, nullable) NSString *lastName;

/**
 * First name
 */
@property (nonatomic, strong, readonly, nullable) NSString *firstName;

/**
 * Card number
 */
@property (nonatomic, strong, readonly, nullable) NSString *cardNumber;

/**
 * ID series
 */
@property (nonatomic, strong, readonly, nullable) NSString *idSeries;

/**
 * CNP
 */
@property (nonatomic, strong, readonly, nullable) NSString *cnp;

/**
 * Parent names - missing if nationality exists
 */
@property (nonatomic, strong, readonly, nullable) NSString *parentNames;

/**
 * Nationality - missing if parent names exists
 */
@property (nonatomic, strong, readonly, nullable) NSString *nationality;

/**
 * Place of birth
 */
@property (nonatomic, strong, readonly, nullable) NSString *placeOfBirth;

/**
 * Address
 */
@property (nonatomic, strong, readonly, nullable) NSString *address;

/**
 * Issued by
 */
@property (nonatomic, strong, readonly, nullable) NSString *issuedBy;

/**
 * Sex
 */
@property (nonatomic, strong, readonly, nullable) NSString *sex;

/**
 * Valid from
 */
@property (nonatomic, strong, readonly, nullable) NSDate *validFrom;

/**
 * Valid from date in format DD.MM.YYYY.
 */
@property (nonatomic, readonly, nullable) NSString *rawValidFrom;

/**
 * Valid until
 */
@property (nonatomic, strong, readonly, nullable) NSDate *validUntil;

/**
 * Valid until date in format DD.MM.YYYY.
 */
@property (nonatomic, readonly, nullable) NSString *rawValidUntil;

@end
