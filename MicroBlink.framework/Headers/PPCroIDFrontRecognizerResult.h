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
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPCroIDFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * Returns the first name of the Croatian ID owner.
 * @return the first name of the Croatian ID owner.
 */
- (NSString * _Nullable)firstName;

/**
 * Returns the last name of the Croatian ID owner.
 * @return the last name of the Croatian ID owner.
 */
- (NSString * _Nullable)lastName;

/**
 * Returns the identity card number of Croatian ID.
 * @return the identity card number of Croatian ID.
 */
- (NSString * _Nullable)identityCardNumber;

/**
 * Returns sex of the Croatian ID owner.
 * @return sex of the Croatian ID owner
 */
- (NSString * _Nullable)sex;

/**
 * Returns nationality of the Croatian ID owner.
 * @return nationality of the Croatian ID owner
 */
- (NSString * _Nullable)nationality;

/**
 * Returns the date of birth of Croatian ID owner
 * @return the date of birth of Croatian ID owner
 */
- (NSString * _Nullable)dateOfBirth;

/**
 * Returns the document date of expiry of the Croatian ID
 * @return the document date of expiry of the Croatian ID
 */
- (NSString * _Nullable)documentDateOfExpiry;

@end
