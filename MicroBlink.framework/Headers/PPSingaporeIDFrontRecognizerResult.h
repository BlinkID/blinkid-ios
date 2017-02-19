//
//  PPSingaporeIDFrontRecognizerResult.h
//  PhotoPayFramework
//
//  Created by DoDo on 21/12/2016.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Singapore ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSingaporeIDFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * The identity card number of the Singapore ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The name of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The race of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *race;

/**
 * The sex of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The date of birth of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The country of birth of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *countryOfBirth;

@end
