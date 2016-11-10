//
//  PPGermanIdFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of German ID
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPGermanIdFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * Returns the first name of the German ID owner.
 * @return the first name of the German ID owner.
 */
- (NSString * _Nullable)firstName;

/**
 * Returns the last name of the German ID owner.
 * @return the last name of the German ID owner.
 */
- (NSString * _Nullable)lastName;

/**
 * Returns nationality of the German ID owner.
 * @return nationality of the German ID owner
 */
- (NSString * _Nullable)nationality;

/**
 * Returns the date of birth of German ID owner
 * @return the date of birth of German ID owner
 */
- (NSString * _Nullable)dateOfBirth;

/**
 * Returns the place of birth of the German ID
 * @return the place of birth of the German ID
 */
- (NSString * _Nullable)placeOfBirth;

/**
 * Returns the document date of expiry of the German ID
 * @return the document date of expiry of the German ID
 */
- (NSString * _Nullable)dateOfExpiry;

/**
 * Returns the document number of the German ID
 * @return the document number of the German ID
 */
- (NSString * _Nullable)documentNumber;

@end
