//
//  PPSwissIDFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 04/09/2017.
//
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Swiss ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSwissIDFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The first name of the Swiss ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Swiss ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The date of birth of the Swiss ID owner in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of the Swiss ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

@end
