//
//  MBCzechiaIdFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Cz ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCzechiaIdFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFaceImageResult, MBSignatureImageResult, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The ID card number of the Czech ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The first name of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The date of birth of the Czech ID owner in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The date of issue of the Czech ID owner in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfIssue;

/**
 * The date of issue of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The date of expiry of the Czech ID owner in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfExpiry;

/**
 * The date of expiry of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * The sex of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The place of birth of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

@end

NS_ASSUME_NONNULL_END