//
//  PPSlovenianIdFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 22/09/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side side of Slovenian ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSlovenianIdFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * The first name of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The sex of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The nationality of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The date of birth of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *dateOfBirth;

/**
 * The date of expiry of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *dateOfExpiry;

@end
