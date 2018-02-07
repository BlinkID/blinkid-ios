//
//  PPHongKongIDFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 05/02/2018.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Hong Kong ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPHongKongIDFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The full name of the Hong Kong ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *fullName;

/**
 * The commerical Code of the Hong Kong ID.
 */
@property (nonatomic, readonly, nullable) NSString *commercialCode;

/**
 * The date of birth of the Hong Kong ID ownder.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The sex of the Hong Kong ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The issue date of the Hong Kong ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *issueDate;

/**
 * The document number of the Hong Kong card.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

@end
