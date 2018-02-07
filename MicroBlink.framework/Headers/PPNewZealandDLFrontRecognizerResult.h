//
//  PPNewZealandDLFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 02/02/2018.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of New Zealand Driver License
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPNewZealandDLFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The first name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSDate *issueDate;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSDate *expiryDate;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, assign) BOOL donorIndicator;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The license number of the New Zealand Driver License.
 */
@property (nonatomic, readonly, nullable) NSString *licenseNumber;

/**
 * The card version of the New Zealand Driver License.
 */
@property (nonatomic, readonly, nullable) NSString *cardVersion;

@end

