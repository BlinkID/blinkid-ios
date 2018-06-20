//
//  MBCroatiaCombinedRecognizerResult.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBMicroBlinkDefines.h"
#import "MBLegacyRecognizerResult.h"

#import "MBCombinedRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBDigitalSignatureResult.h"
#import "MBCombinedFullDocumentImageResult.h"

#import "MBEncodedFaceImageResult.h"
#import "MBEncodedSignatureImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning both front and back side of Croatian ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCroatiaCombinedRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBCombinedFullDocumentImageResult, MBSignatureImageResult, MBDigitalSignatureResult, MBEncodedFaceImageResult, MBEncodedSignatureImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The identity card number of Croatian ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The sex of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The citizenship of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *citizenship;

/**
 * The date of birth of Croatian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The document date of expiry of the Croatian ID
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * Check if date of expiry is permanent on the Croatian ID.
 */
@property (nonatomic, readonly) BOOL dateOfExpiryPermanent;

/**
 * The address of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The issuing authority of Croatian ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The document date of issue of the Croatian ID.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The OIB (PIN) of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *personalIdentificationNumber;

/**
 * YES if the person is non Croatian resident
 */
@property (nonatomic, readonly) BOOL nonResident;

/**
 * YES if the document is bilingual
 */
@property (nonatomic, readonly) BOOL documentBilingual;

/**
 * YES if all check digits inside MRZ are correct, NO otherwise.
 * More specifically, YES if MRZ complies with ICAO Document 9303 standard, NO otherwise.
 */
@property (nonatomic, readonly) BOOL mrzVerified;

@end

NS_ASSUME_NONNULL_END
