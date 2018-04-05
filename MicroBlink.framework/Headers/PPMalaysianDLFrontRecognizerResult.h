//
//  PPMalaysianDLFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 29/03/2018.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Malaysian DL
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPMalaysianDLFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The Name of the Malaysian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The Identity Number of the Malaysian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *identityNumber;

/**
 * The Nationality of the Malaysian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The Class of the Malaysian DL.
 */
@property (nonatomic, readonly, nullable) NSString *licenseClass;

/**
 * The Valid From date of the Malaysian DL owner.
 */
@property (nonatomic, readonly, nullable) NSDate *validFrom;

/**
 * The Valid Until date of the Malaysian DL owner.
 */
@property (nonatomic, readonly, nullable) NSDate *validUntil;

/**
 * The Street of the Malaysian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *street;

/**
 * The Zip Code of the Malaysian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *zipCode;

/**
 * The City of the Malaysian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *city;

/**
 * The State of the Malaysian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *state;

/**
 * The Full Address of the Malaysian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *fullAddress;

@end
