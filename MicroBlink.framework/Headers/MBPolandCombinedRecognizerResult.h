//
//  MBPolandCombinedRecognizerResult.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBCombinedRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBDigitalSignatureResult.h"
#import "MBCombinedFullDocumentImageResult.h"

#import "MBEncodedFaceImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning both front and back side of Czech ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBPolandCombinedRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBCombinedFullDocumentImageResult, MBDigitalSignatureResult, MBEncodedFaceImageResult, MBEncodedCombinedFullDocumentImageResult>

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
 * The nationality of the Polish ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The issuer of Polish ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuer;

/**
 * The document number on Polish ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The personal number of Polish ID.
 */
@property (nonatomic, readonly, nullable) NSString *personalNumber;

/**
 * The date of birth of Polish ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The document date of expiry of the Polish ID
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * YES if all check digits inside MRZ are correct, NO otherwise.
 * More specifically, YES if MRZ complies with ICAO Document 9303 standard, NO otherwise.
 */
@property (nonatomic, readonly) BOOL mrzVerified;

@end

NS_ASSUME_NONNULL_END
