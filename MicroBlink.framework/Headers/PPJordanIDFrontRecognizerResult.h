//
//  PPJordanIDFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 23/03/2018.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Jordan ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPJordanIDFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The Name of the Jordan ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The Sex of the Jordan ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The Date Of Birth of the Jordan ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The National Number of the Jordan ID.
 */
@property (nonatomic, readonly, nullable) NSString *nationalNumber;

@end
