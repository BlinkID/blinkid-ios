//
//  PPPolishIDFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 19/10/2017.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side side of Polish ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPPolishIDFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The first name of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The family name of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *familyName;

/**
 * The parent's name of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *parentsName;

/**
 * The sex of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The date of birth of Polish ID owner in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of Polish ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

@end
