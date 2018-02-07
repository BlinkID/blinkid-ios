//
//  PPColombiaIDBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 30/01/2018.
//

#import "PPRecognizerResult.h"

/**
 * Class representing values obtained when scanning back side of Colombia ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPColombiaIDBackRecognizerResult : PPRecognizerResult

/**
 * The first name of the Colombian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Colombian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The sex of the Colombian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The date of birth of the Colombian ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The blood group of the Colombian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *bloodGroup;

/**
 * The fingerprint of the Colombian ID owner.
 */
@property (nonatomic, readonly, nullable) NSData *fingerprint;

/**
 * The document number of the Colombian ID card.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

@end
