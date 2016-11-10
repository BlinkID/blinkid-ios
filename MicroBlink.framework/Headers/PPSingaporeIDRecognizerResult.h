//
//  PPSingaporeIDRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 30/06/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning Singapore ID.
 * Both front and back side can be scanned but the results will be different for each side
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPSingaporeIDRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * Returns the identity card number of the Singapore ID.
 * @return identity card number of the Singapore ID.
 */
- (NSString * _Nullable)identityCardNumber;

/**
 * Returns the name of the Singapore ID owner.
 * @return name of the Singapore ID owner.
 */
- (NSString * _Nullable)name;

/**
 * Returns the race of the Singapore ID owner.
 * @return race of the Singapore ID owner.
 */
- (NSString * _Nullable)race;

/**
 * Returns the sex of the Singapore ID owner.
 * @return sex of the Singapore ID owner.
 */
- (NSString * _Nullable)sex;

/**
 * Returns the date of birth of the Singapore ID owner.
 * @return date of birth of the Singapore ID owner.
 */
- (NSString * _Nullable)dateOfBirth;

/**
 * Returns the country of birth of the Singapore ID owner.
 * @return country of birth of the Singapore ID owner.
 */
- (NSString * _Nullable)countryOfBirth;

/**
 * Returns the blood group of the Singapore ID owner.
 * @return blood group of the Singapore ID owner.
 */
- (NSString * _Nullable)bloodGroup;

/**
 * Returns the date of issue of the Singapore ID.
 * @return date of issue of the Singapore ID.
 */
- (NSString * _Nullable)dateOfIssue;

/**
 * Returns the address of the Singapore ID owner.
 * @return address of the Singapore ID owner.
 */
- (NSString * _Nullable)address;

@end
