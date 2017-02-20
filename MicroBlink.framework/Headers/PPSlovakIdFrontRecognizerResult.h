//
//  PPSlovakIdFrontRecognizerResult.h
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
@interface PPSlovakIdFrontRecognizerResult : PPBlinkOcrRecognizerResult

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
 * The date of birth of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *dateOfBirth;

/**
 * The date of expiry of the Slovakian ID.
 */
@property (nonatomic, readonly, nullable) NSString *dateOfExpiry;

/**
 * The date of issue of the Slovakian ID.
 */
@property (nonatomic, readonly, nullable) NSString *dateOfIssue;

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
