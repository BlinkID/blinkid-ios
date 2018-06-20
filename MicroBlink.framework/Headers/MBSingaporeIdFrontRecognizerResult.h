//
//  MBSingaporeIdFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBFaceImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Singapore ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeIdFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFullDocumentImageResult, MBFaceImageResult>

MB_INIT_UNAVAILABLE

/**
 * The identity card number of the Singapore ID.
 */
@property (nonatomic, readonly, nullable) NSString *cardNumber;

/**
 * The name of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The race of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *race;

/**
 * The sex of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The date of birth of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The country of birth of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *countryOfBirth;

@end

NS_ASSUME_NONNULL_END
