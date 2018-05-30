//
//  PPSwedenDLFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 29/05/2018.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Sweden DL
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSwedenDLFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The Surname of the Sweden DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *surname;

/**
 * The Name of the Sweden DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The Date Of Birth of the Sweden DL owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The Date Of Issue of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The Date Of Expiry of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * The Issuing Agency of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAgency;

/**
 * The Reference Number of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSString *referenceNumber;

/**
 * The Licence Categories of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSString *licenceCategories;

/**
 * The Licence Numer of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSString *licenceNumber;

@end
