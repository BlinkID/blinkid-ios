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
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPSlovenianIdFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * Returns the first name of the Slovenian ID owner.
 * @return the first name of the Slovenian ID owner.
 */
- (NSString * _Nullable)firstName;

/**
 * Returns the last name of the Slovenian ID owner.
 * @return the last name of the Slovenian ID owner.
 */
- (NSString * _Nullable)lastName;

/**
 * Returns the sex of the Slovenian ID owner.
 * @return the sex of the Slovenian ID owner.
 */
- (NSString * _Nullable)sex;

/**
 * Returns the nationality of the Slovenian ID owner.
 * @return the nationality of the Slovenian ID owner.
 */
- (NSString * _Nullable)nationality;

/**
 * Returns the date of birth of the Slovenian ID owner.
 * @return the date of birth of the Slovenian ID owner.
 */
- (NSString * _Nullable)dateOfBirth;

/**
 * Returns the date of expiry of the Slovenian ID owner.
 * @return the date of expiry of the Slovenian ID owner.
 */
- (NSString * _Nullable)dateOfExpiry;

@end
