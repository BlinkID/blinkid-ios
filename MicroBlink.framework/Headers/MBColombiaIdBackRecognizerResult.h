//
//  MBColombiaIdBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of Colombia ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBColombiaIdBackRecognizerResult : MBLegacyRecognizerResult<NSCopying>

MB_INIT_UNAVAILABLE

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

NS_ASSUME_NONNULL_END