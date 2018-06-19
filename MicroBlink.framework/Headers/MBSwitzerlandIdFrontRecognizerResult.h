//
//  MBSwitzerlandIdFrontRecognizerResult.h
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
 * Class representing values obtained when scanning front side of Swiss ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwitzerlandIdFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFaceImageResult, MBSignatureImageResult, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the Swiss ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *givenName;

/**
 * The last name of the Swiss ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *surname;

/**
 * The date of birth of the Swiss ID owner in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of the Swiss ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

@end

NS_ASSUME_NONNULL_END
