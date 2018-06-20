//
//  MBIkadRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning i Kad
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBIkadRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFaceImageResult, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The name of the iKad owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The passport number of the iKad owner.
 */
@property (nonatomic, readonly, nullable) NSString *passportNumber;

/**
 * The nationality of the iKad owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The date of birth of iKad owner, as written on the iKad (DD/MM/YYYY)
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of iKad owner, parsed in NSDate object
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The sex of the iKad owner
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The sector of the iKad owner
 */
@property (nonatomic, readonly, nullable) NSString *sector;

/**
 * The employer of the iKad owner
 */
@property (nonatomic, readonly, nullable) NSString *employer;

/**
 * The address of the iKad owner
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The faculty address of the iKad owner
 */
@property (nonatomic, readonly, nullable) NSString *facultyAddress;

/**
 * The expiry date of the iKad, as written on the iKad (DD/MM/YYYY)
 */
@property (nonatomic, readonly, nullable) NSString *rawExpiryDate;

/**
 * The expiry date of the iKad, parsed in NSDate object
 */
@property (nonatomic, readonly, nullable) NSDate *expiryDate;

@end

NS_ASSUME_NONNULL_END
