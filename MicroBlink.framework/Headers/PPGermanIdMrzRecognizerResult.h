//
//  PPGermanIdMrzRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPMrtdRecognizerResult.h"

/**
 * Class representing values obtained when scanning MRZ of German ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPGermanIdMrzRecognizerResult : PPMrtdRecognizerResult

/**
 * The eye color of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *eyeColor;

/**
 * The height of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *height;

/**
 * The date of issue of the ID.
 */
@property (nonatomic, readonly, nullable) NSString *dateOfIssue;

/**
 * The issuing authority of the German ID.
 */
@property (nonatomic, readonly, nullable) NSString *authority;

/**
 * The address of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The card holder's place of birth (only on old cards).
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

@end
