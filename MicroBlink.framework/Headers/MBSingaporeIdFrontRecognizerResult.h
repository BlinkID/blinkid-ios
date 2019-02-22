//
//  MBSingaporeIdFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"
#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Singapore ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBFaceImageResult, MBEncodedFaceImageResult>

MB_INIT_UNAVAILABLE

/**
 * The identity card number of the Singaporean ID card.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The name of the Singaporean ID card owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The race of the Singaporean ID card owner.
 */
@property (nonatomic, readonly, nullable) NSString *race;

/**
 * The sex of the Singaporean ID card owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The date of birth of the Singaporean ID card owner.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
 * The country/place of birth of the Singaporean ID card owner.
 */
@property (nonatomic, readonly, nullable) NSString *countryOfBirth;

@end

NS_ASSUME_NONNULL_END
