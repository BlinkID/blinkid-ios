//
//  PPJordanIDCombinedRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 02/04/2018.
//

#import "PPRecognizerResult.h"

/**
 * Result of scanning with Jordan ID Combined recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPJordanIDCombinedRecognizerResult : PPRecognizerResult

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
 * The Document Number of the Jordan ID.
 */
@property (nonatomic, readonly, nullable) NSString *nationalNumber;

/**
 * The nationality of the Jordan ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The issuer of the Jordan ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuer;

/**
 * The Document Number of the Jordan ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The Date of expiry of the Jordan ID.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * YES if all check digits inside MRZ are correct, NO otherwise.
 * More specifically, YES if MRZ complies with ICAO Document 9303 standard, NO otherwise.
 */
@property (nonatomic, readonly) BOOL mrtdVerified;

/**
 * YES if Data from the front side is matching the data from the back side
 */
@property (nonatomic, readonly) BOOL matchingData;

/**
 * Byte buffer with face image
 */
@property (nonatomic, readonly, nullable) NSData *faceImage;

@end
