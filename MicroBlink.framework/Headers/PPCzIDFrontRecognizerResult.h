//
//  PPCzIDFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 30/06/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Czech ID
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPCzIDFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * Returns the ID card number of the Czech ID.
 * @return ID card number of the Czech ID.
 */
- (NSString *)identityCardNumber;

/**
 * Returns the first name of the Czech ID owner.
 * @return first name of the Czech ID owner.
 */
- (NSString *)firstName;

/**
 * Returns the last name of the Czech ID owner.
 * @return last name of the Czech ID owner.
 */
- (NSString *)lastName;

/**
 * Returns the date of birth of the Czech ID owner.
 * @return date of birth of the Czech ID owner.
 */
- (NSString *)dateOfBirth;

/**
 * Returns the date of issue of the Czech ID owner.
 * @return date of issue of the Czech ID owner.
 */
- (NSString *)dateOfIssue;

/**
 * Returns the date of expiry of the Czech ID owner.
 * @return date of expiry of the Czech ID owner.
 */
- (NSString *)dateOfExpiry;

/**
 * Returns the sex of the Czech ID owner.
 * @return sex of the Czech ID owner.
 */
- (NSString *)sex;

/**
 * Returns the place of birth of the Czech ID owner.
 * @return place of birth of the Czech ID owner.
 */
- (NSString *)placeOfBirth;

@end
