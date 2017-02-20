//
//  PPCroIDFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Boris Trubic on 05/05/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Croatian ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCroIDFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * The first name of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The identity card number of Croatian ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The sex of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The nationality of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The date of birth of Croatian ID owner
 */
@property (nonatomic, readonly, nullable) NSString *dateOfBirth;

/**
 * The document date of expiry of the Croatian ID
 */
@property (nonatomic, readonly, nullable) NSString *documentDateOfExpiry;

@end
