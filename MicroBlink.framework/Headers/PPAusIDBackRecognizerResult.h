//
//  PPAusIDBackRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 30/06/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPMrtdRecognizerResult.h"

/**
 * Class representing values obtained when scanning back side of Austrian ID
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPAusIDBackRecognizerResult : PPMrtdRecognizerResult

/**
 * Returns the issuing authority of the Austrian ID.
 * @return issuing authority of the Austrian ID.
 */
- (NSString *)issuingAuthority;

/**
 * Returns the place of birth of the Austrian ID owner.
 * @return place of birth of the Austrian ID owner.
 */
- (NSString *)placeOfBirth;

/**
 * Returns the principal residence of the Austrian ID owner.
 * @return principal residence of the Austrian ID owner.
 */
- (NSString *)principalResidence;

/**
 * Returns the height of the Austrian ID owner.
 * @return height of the Austrian ID owner.
 */
- (NSString *)height;

/**
 * Returns the date of issue of the Austrian ID.
 * @return date of issue of the Austrian ID.
 */
- (NSString *)dateOfIssue;

/**
 * Returns the eye color of the Austrian ID owner.
 * @return eye color of the Austrian ID owner.
 */
- (NSString *)eyeColor;

/**
 * Returns the document number of the Austrian ID.
 * @return document number of the Austrian ID.
 */
- (NSString *)documentNumber;

@end
