//
//  PPGermanIDFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of German ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPGermanIDFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * The first name of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The nationality of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The date of birth of German ID owner in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of German ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The place of birth of the German ID
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The document date of expiry of the German ID in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfExpiry;

/**
 * The document date of expiry of the German ID
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * The document number of the German ID
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

@end
