//
//  MBBlinkIdCombinedRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 18/06/2019.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBMrzResult.h"

#import "MBCombinedRecognizerResult.h"
#import "MBDigitalSignatureResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBCombinedFullDocumentImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

#import "MBDriverLicenseDetailedInfo.h"
#import "MBClassInfo.h"
#import "MBDocumentImageColorStatus.h"
#import "MBDocumentImageMoireStatus.h"

#import "MBAgeResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer which can scan front and back side of the United States driver license.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBlinkIdCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBDigitalSignatureResult, MBFaceImageResult, MBEncodedFaceImageResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult, MBAgeResult>

MB_INIT_UNAVAILABLE

/**
 * The address of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The date of birth of the document owner.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
 * The date of expiry of the document.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfExpiry;

/**
 * The date of issue of the document.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfIssue;

/**
 * Determines if date of expiry is permanent.
 */
@property (nonatomic, readonly) BOOL dateOfExpiryPermanent;

/**
 * The document number.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The first name of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The full name of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *fullName;

/**
 * The last name of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The sex of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The localized name of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *localizedName;

/**
 * The additional name information of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *additionalNameInformation;

/**
 * The additional address information of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *additionalAddressInformation;

/**
 * The place of birth of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The nationality of the documet owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The race of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *race;

/**
 * The religion of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *religion;

/**
 * The profession of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *profession;

/**
 * The marital status of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *maritalStatus;

/**
 * The residential stauts of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *residentialStatus;

/**
 * The employer of the document owner.
 */
@property (nonatomic, readonly, nullable) NSString *employer;

/**
 * The personal identification number.
 */
@property (nonatomic, readonly, nullable) NSString *personalIdNumber;

/**
 * The additional number of the document.
 */
@property (nonatomic, readonly, nullable) NSString *documentAdditionalNumber;

/**
 * The issuing authority of the document.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The data extracted from the machine readable zone
 */
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
 * The driver license detailed info.
 */
@property (nonatomic, readonly, nullable) MBDriverLicenseDetailedInfo *driverLicenseDetailedInfo;

/**
 * The driver license conditions.
 */
@property (nonatomic, readonly, nullable) NSString *conditions;

/**
 * The classification information.
 */
@property (nonatomic, readonly, nullable) MBClassInfo *classInfo;

/**
 * Defines possible color statuses determined from scanned image.
 */
@property (nonatomic, readonly) MBDocumentImageColorStatus documentFrontImageColorStatus;

/**
 * Defines possible color statuses determined from scanned image.
 */
@property (nonatomic, readonly) MBDocumentImageColorStatus documentBackImageColorStatus;

/**
 * Defines possible moire statuses determined from scanned image.
 */
@property (nonatomic, readonly) MBDocumentImageMoireStatus documentFrontImageMoireStatus;

/**
 * Defines possible moire statuses determined from scanned image.
 */
@property (nonatomic, readonly) MBDocumentImageMoireStatus documentBackImageMoireStatus;

@end

NS_ASSUME_NONNULL_END
