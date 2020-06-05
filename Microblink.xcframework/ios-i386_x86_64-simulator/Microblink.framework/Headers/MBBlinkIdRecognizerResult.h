//
// MBBlinkIDRecognizerResult.h
//
// Created by juraskrlec on 06/05/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBMrzResult.h"
#import "MBClassInfo.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"
#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"

#import "MBDriverLicenseDetailedInfo.h"
#import "MBDocumentImageColorStatus.h"
#import "MBDocumentImageMoireStatus.h"

#import "MBAgeResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* The Blink ID Recognizer is used for scanning Blink ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBlinkIdRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBFaceImageResult, MBEncodedFaceImageResult, MBAgeResult>

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
@property (nonatomic, readonly) MBDocumentImageColorStatus documentImageColorStatus;

/**
 * Defines possible moire statuses determined from scanned image.
 */
@property (nonatomic, readonly) MBDocumentImageMoireStatus documentImageMoireStatus;

@end

NS_ASSUME_NONNULL_END
