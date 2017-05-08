//
//  PPSlovakIDFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Slovak ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSlovakIDFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * The first name of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The sex of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The nationality of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The date of birth of the Slovakian ID owner in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The date of expiry of the Slovakian ID in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfExpiry;

/**
 * The date of expiry of the Slovakian ID.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * The date of issue of the Slovakian ID in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfIssue;

/**
 * The date of issue of the Slovakian ID.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The issuing authority of the ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuedBy;

/**
 * The personal number of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *personalNumber;

/**
 * The document number of the Slovakian ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

@end
