//
//  PPIndonesianIDFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 30/11/2017.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Indonesian ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPIndonesianIDFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The province of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *province;

/**
 * The city of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *city;

/**
 * The document number of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The name of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The place of birth of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The date of birth of Indonesian ID owner in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of Indonesian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The sex of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The blood type of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *bloodType;

/**
 * The address of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The rt of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *rt;

/**
 * The rw of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *rw;

/**
 * The kel desa of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *kelDesa;

/**
 * The district of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *district;

/**
 * The religion of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *religion;

/**
 * The marriage status of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *marriageStatus;

/**
 * The occupation of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *occupation;

/**
 * The occupation of the Indonesian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *citizenship;

/**
 * The document date of expiry of the Indonesian ID in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDocumentDateOfExpiry;

/**
 * The document date of expiry of the Indonesian ID
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfExpiry;

/**
 * Check if date of expiry is permanent on the Indonesian ID.
 */
@property (nonatomic, readonly) BOOL isDocumentDateOfExpiryPermanent;

@end
