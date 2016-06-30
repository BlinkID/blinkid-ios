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
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPAusIDFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * Returns the first name of the Austrian ID owner.
 * @return first name of the Austrian ID owner.
 */
- (NSString *)firstName;

/**
 * Returns the last name of the Austrian ID owner.
 * @return last name of the Austrian ID owner.
 */
- (NSString *)lastName;

/**
 * Returns the document number of the Austrian ID.
 * @return document number of the Austrian ID.
 */
- (NSString *)documentNumber;

/**
 * Returns the date of birth of the Austrian ID owner.
 * @return date of birth of the Austrian ID owner.
 */
- (NSString *)dateOfBirth;

/**
 * Returns the sex of the Austrian ID owner.
 * @return sex of the Austrian ID owner.
 */
- (NSString *)sex;

@end
