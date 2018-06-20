//
//  MBGermanyIdFrontRecognizerResult.h
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
 * Class representing values obtained when scanning front side of German ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyIdFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFaceImageResult, MBSignatureImageResult, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The nationality of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The date of birth of German ID owner in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of German ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The place of birth of the German ID
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The document date of expiry of the German ID in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfExpiry;

/**
 * The document date of expiry of the German ID
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * The document number of the German ID
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The CAN number of the German ID
 */
@property (nonatomic, readonly, nullable) NSString *canNumber;

@end

NS_ASSUME_NONNULL_END
