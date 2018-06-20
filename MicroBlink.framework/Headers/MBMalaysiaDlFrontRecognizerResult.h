//
//  MBMalaysiaDlFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBFaceImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Malaysian DL
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMalaysiaDlFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFullDocumentImageResult, MBFaceImageResult>

MB_INIT_UNAVAILABLE

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
@property (nonatomic, readonly, nullable) NSString *dlClass;

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

NS_ASSUME_NONNULL_END
