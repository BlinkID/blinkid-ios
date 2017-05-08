//
//  PPCzIDFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 30/06/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Czech ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCzIDFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * The ID card number of the Czech ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The first name of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The date of birth of the Czech ID owner in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The date of issue of the Czech ID owner in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfIssue;

/**
 * The date of issue of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The date of expiry of the Czech ID owner in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfExpiry;

/**
 * The date of expiry of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * The sex of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The place of birth of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

@end
