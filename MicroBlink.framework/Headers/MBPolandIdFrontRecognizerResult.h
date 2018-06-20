//
//  MBPolandIdFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Polish ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBPolandIdFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFaceImageResult, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *givenNames;

/**
 * The last name of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *surname;

/**
 * The family name of Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *familyName;

/**
 * The parents name of Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *parentsGivenNames;

/**
 * The sex of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The date of birth of Polish ID owner in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of Polish ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

@end

NS_ASSUME_NONNULL_END
