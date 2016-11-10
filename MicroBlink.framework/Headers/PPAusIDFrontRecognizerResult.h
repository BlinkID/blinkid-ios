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
- (NSString * _Nullable)firstName;

/**
 * Returns the last name of the Austrian ID owner.
 * @return last name of the Austrian ID owner.
 */
- (NSString * _Nullable)lastName;

/**
 * Returns the document number of the Austrian ID.
 * @return document number of the Austrian ID.
 */
- (NSString * _Nullable)documentNumber;

/**
 * Returns the date of birth of the Austrian ID owner.
 * @return date of birth of the Austrian ID owner.
 */
- (NSString * _Nullable)dateOfBirth;

/**
 * Returns the sex of the Austrian ID owner.
 * @return sex of the Austrian ID owner.
 */
- (NSString * _Nullable)sex;

@end
