//
//  PPAusIDFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 30/06/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Austrian ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPAusIDFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * The first name of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The document number of the Austrian ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The date of birth of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *dateOfBirth;

/**
 * The sex of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

@end
