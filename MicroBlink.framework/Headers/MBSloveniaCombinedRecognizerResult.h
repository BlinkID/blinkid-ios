//
//  MBSloveniaCombinedRecognizerResult.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBCombinedRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBDigitalSignatureResult.h"
#import "MBCombinedFullDocumentImageResult.h"

#import "MBEncodedFaceImageResult.h"
#import "MBEncodedSignatureImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning both front and back side of Slovenian ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSloveniaCombinedRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBCombinedFullDocumentImageResult, MBSignatureImageResult, MBDigitalSignatureResult, MBEncodedFaceImageResult, MBEncodedSignatureImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The identity card number of Slovenian ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The sex of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The nationality of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *citizenship;

/**
 * The date of birth of Slovenian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The date of expiry of Slovenian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * The address of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The PIN of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *personalIdentificationNumber;

/**
 * The issuing authority of Slovenian ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The date of issue of Slovenian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * YES if all check digits inside MRZ are correct, NO otherwise.
 * More specifically, YES if MRZ complies with ICAO Document 9303 standard, NO otherwise.
 */
@property (nonatomic, readonly) BOOL mrzVerified;

@end

NS_ASSUME_NONNULL_END
