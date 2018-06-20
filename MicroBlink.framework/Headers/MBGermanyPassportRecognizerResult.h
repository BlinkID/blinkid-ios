//
//  MBGermanyPassportRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyMRTDRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning German Passport
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyPassportRecognizerResult : MBLegacyMRTDRecognizerResult<NSCopying, MBFaceImageResult, MBSignatureImageResult, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The surname of the German Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *surname;

/**
 * The name of the German Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The place of birth of the German Passport owner
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * Raw date of issue, as written on the passport
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfIssue;

/**
 * Date of issue in NSDate object
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * Issuing authority of the Passport
 */
@property (nonatomic, readonly, nullable) NSString *authority;

@end

NS_ASSUME_NONNULL_END
