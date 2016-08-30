//
//  PPGermanIdFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of German ID
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPGermanIdFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * Returns the first name of the German ID owner.
 * @return the first name of the German ID owner.
 */
- (NSString *)firstName;

/**
 * Returns the last name of the German ID owner.
 * @return the last name of the German ID owner.
 */
- (NSString *)lastName;

/**
 * Returns nationality of the German ID owner.
 * @return nationality of the German ID owner
 */
- (NSString *)nationality;

/**
 * Returns the date of birth of German ID owner
 * @return the date of birth of German ID owner
 */
- (NSString *)dateOfBirth;

/**
 * Returns the place of birth of the German ID
 * @return the place of birth of the German ID
 */
- (NSString *)placeOfBirth;

/**
 * Returns the document date of expiry of the German ID
 * @return the document date of expiry of the German ID
 */
- (NSString *)dateOfExpiry;

/**
 * Returns the document number of the German ID
 * @return the document number of the German ID
 */
- (NSString *)documentNumber;

@end

NS_ASSUME_NONNULL_END
