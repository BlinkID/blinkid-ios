//
//  PPSlovakIdFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Slovak ID
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPSlovakIdFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * Returns the first name of the Slovakian ID owner.
 * @return the first name of the Slovakian ID owner.
 */
- (NSString *)firstName;

/**
 * Returns the last name of the Slovakian ID owner.
 * @return the last name of the Slovakian ID owner.
 */
- (NSString *)lastName;

/**
 * Returns the sex of the Slovakian ID owner.
 * @return the sex of the Slovakian ID owner.
 */
- (NSString *)sex;

/**
 * Returns the nationality of the Slovakian ID owner.
 * @return the nationality of the Slovakian ID owner.
 */
- (NSString *)nationality;

/**
 * Returns the date of birth of the Slovakian ID owner.
 * @return the date of birth of the Slovakian ID owner.
 */
- (NSString *)dateOfBirth;

/**
 * Returns the date of expiry of the Slovakian ID.
 * @return the date of expiry of the Slovakian ID.
 */
- (NSString *)dateOfExpiry;

/**
 * Returns the date of issue of the Slovakian ID.
 * @return the date of issue of the Slovakian ID.
 */
- (NSString *)dateOfIssue;

/**
 * Returns the issuing authority of the ID.
 * @return the issuing authority of the ID.
 */
- (NSString *)issuedBy;

/**
 * Returns the personal number of the Slovakian ID owner.
 * @return the personal number of the Slovakian ID owner.
 */
- (NSString *)personalNumber;

/**
 * Returns the document number of the Slovakian ID.
 * @return the document number of the Slovakian ID.
 */
- (NSString *)documentNumber;

@end

NS_ASSUME_NONNULL_END
