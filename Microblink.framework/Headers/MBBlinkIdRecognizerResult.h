//
// MBBlinkIDRecognizerResult.h
//
// Created by juraskrlec on 06/05/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"
#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBDriverLicenseDetailedInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
* The Blink ID Recognizer is used for scanning Blink ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBlinkIdRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBFaceImageResult, MBEncodedFaceImageResult>

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
 * The driver license detailed info.
 */
@property (nonatomic, readonly, nullable) MBDriverLicenseDetailedInfo *driverLicenseDetailedInfo;
@end

NS_ASSUME_NONNULL_END
