//
//  MBRomaniaIdFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyMRTDRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Romanian ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBRomaniaIdFrontRecognizerResult : MBLegacyMRTDRecognizerResult<NSCopying, MBFaceImageResult, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * Last name
 */
@property (nonatomic, strong, readonly, nullable) NSString *lastName;

/**
 * First name
 */
@property (nonatomic, strong, readonly, nullable) NSString *firstName;

/**
 * Card number
 */
@property (nonatomic, strong, readonly, nullable) NSString *cardNumber;

/**
 * ID series
 */
@property (nonatomic, strong, readonly, nullable) NSString *idSeries;

/**
 * CNP
 */
@property (nonatomic, strong, readonly, nullable) NSString *cnp;

/**
 * Parent names - missing if nationality exists
 */
@property (nonatomic, strong, readonly, nullable) NSString *parentNames MB_PROPERTY_DEPRECATED;

/**
 * Nationality - missing if parent names exists
 */
@property (nonatomic, strong, readonly, nullable) NSString *nonMRZNationality;

/**
 * Place of birth
 */
@property (nonatomic, strong, readonly, nullable) NSString *placeOfBirth;

/**
 * Address
 */
@property (nonatomic, strong, readonly, nullable) NSString *address;

/**
 * Issued by
 */
@property (nonatomic, strong, readonly, nullable) NSString *issuedBy;

/**
 * Sex
 */
@property (nonatomic, strong, readonly, nullable) NSString *nonMRZSex;

/**
 * Valid from
 */
@property (nonatomic, strong, readonly, nullable) NSDate *validFrom;

/**
 * Valid from date in format DD.MM.YYYY.
 */
@property (nonatomic, readonly, nullable) NSString *rawValidFrom;

/**
 * Valid until
 */
@property (nonatomic, strong, readonly, nullable) NSDate *validUntil;

/**
 * Valid until date in format DD.MM.YYYY.
 */
@property (nonatomic, readonly, nullable) NSString *rawValidUntil;

@end

NS_ASSUME_NONNULL_END
