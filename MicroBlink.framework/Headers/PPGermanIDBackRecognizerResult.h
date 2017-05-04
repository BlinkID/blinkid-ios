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
@interface PPGermanIDBackRecognizerResult : PPMrtdRecognizerResult

/**
 * Eye colour
 */
@property (nonatomic, readonly, nullable) NSString *eyeColor;

/**
 * Height in cm
 */
@property (nonatomic, readonly, nullable) NSString *height;

/**
 * Raw date of issue, as written on the ID
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfIssue;

/**
 * Date of issue
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * Issuing authority of the ID
 */
@property (nonatomic, readonly, nullable) NSString *authority;

/**
 * Full address
 */
@property (nonatomic, readonly, nullable) NSString *fullAddress;

/**
 * ZIP code
 */
@property (nonatomic, readonly, nullable) NSString *ZIPCode;

/**
 * City
 */
@property (nonatomic, readonly, nullable) NSString *city;

/**
 * Stret name in single line
 */
@property (nonatomic, readonly, nullable) NSString *street;

/**
 * House number
 */
@property (nonatomic, readonly, nullable) NSString *houseNumber;

@end
