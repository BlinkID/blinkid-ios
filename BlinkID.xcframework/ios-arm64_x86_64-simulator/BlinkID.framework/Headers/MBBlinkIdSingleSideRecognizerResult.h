//
// MBBlinkIdSingleSideRecognizerResult.h
//
// Created by juraskrlec on 06/05/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBMrzResult.h"
#import "MBClassInfo.h"
#import "MBBarcodeResult.h"
#import "MBVizResult.h"
#import "MBProcessingStatus.h"
#import "MBRecognitionMode.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"
#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"

#import "MBDriverLicenseDetailedInfo.h"
#import "MBImageAnalysisResult.h"

#import "MBAgeResult.h"
#import "MBDocumentExpirationCheckResult.h"
#import "MBAdditionalProcessingInfo.h"
#import "MBDependentInfo.h"

@class MBStringResult;

NS_ASSUME_NONNULL_BEGIN

/**
* The Blink ID Recognizer is used for scanning Blink ID.
*/
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBBlinkIdSingleSideRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBFaceImageResult, MBEncodedFaceImageResult, MBAgeResult, MBDocumentExpirationCheckResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
 * The address of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *address;

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
@property (nonatomic, readonly, nullable) MBStringResult *documentNumber;

/**
 * The first name of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *firstName;

/**
 * The full name of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *fullName;

/**
 * The last name of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *lastName;

/**
 * The father's name of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *fathersName;

/**
 * The mother's name of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *mothersName;

/**
 * The sex of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *sex;

/**
 * The localized name of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *localizedName;

/**
 * The additional name information of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *additionalNameInformation;

/**
 * The additional address information of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *additionalAddressInformation;

/**
 * The one more additional address information of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *additionalOptionalAddressInformation;

/**
 * The place of birth of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *placeOfBirth;

/**
 * The nationality of the documet owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *nationality;

/**
 * The race of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *race;

/**
 * The religion of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *religion;

/**
 * The profession of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *profession;

/**
 * The marital status of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *maritalStatus;

/**
 * The residential stauts of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *residentialStatus;

/**
 * The employer of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *employer;

/**
 * The personal identification number.
 */
@property (nonatomic, readonly, nullable) MBStringResult *personalIdNumber;

/**
 * The additional number of the document.
 */
@property (nonatomic, readonly, nullable) MBStringResult *documentAdditionalNumber;

/**
 * The one more additional number of the document.
 */
@property (nonatomic, readonly, nullable) MBStringResult *documentOptionalAdditionalNumber;

/**
 * The issuing authority of the document.
 */
@property (nonatomic, readonly, nullable) MBStringResult *issuingAuthority;

/**
 * The transcription of the document subtype.
 */
@property (nonatomic, readonly, nullable) MBStringResult *documentSubtype;

/**
 * The sponsor of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *sponsor;

/**
 * The blood type of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *bloodType;

/**
 * The data extracted from the machine readable zone
 */
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
 * The driver license detailed info.
 */
@property (nonatomic, readonly, nullable) MBDriverLicenseDetailedInfo *driverLicenseDetailedInfo;

/**
 * The classification information.
 */
@property (nonatomic, readonly, nullable) MBClassInfo *classInfo;

/**
 * Defines possible color and moire statuses determined from scanned image.
 */
@property (nonatomic, readonly, nullable) MBImageAnalysisResult *imageAnalysisResult;

/**
 * Defines the data extracted from the barcode.
 */
@property (nonatomic, readonly, nullable) MBBarcodeResult *barcodeResult;

/**
 * Defines the data extracted from the visual inspection zone
 */
@property (nonatomic, readonly, nullable) MBVizResult *vizResult;

/**
 * Defines status of the last recognition process.
 */
@property (nonatomic, readonly, assign) MBProcessingStatus processingStatus;

/**
 * Additional info on processing.
 */
@property (nonatomic, readonly, nullable) MBAdditionalProcessingInfo *additionalProcessingInfo;

/**
 * Recognition mode used to scan current document.
 */
@property (nonatomic, readonly, assign) MBRecognitionMode recognitionMode;

/**
 * The raw camera frame.
 */
@property (nonatomic, readonly, nullable) MBImage *cameraFrame;

/**
 * The barcode raw camera frame.
 */
@property (nonatomic, readonly, nullable) MBImage *barcodeCameraFrame;

/**
 * face image location from the document if enabled with `MBFaceImage returnFaceImage` property.
 */
@property (nonatomic, readonly) CGRect faceImageLocation;

/**
 * side of document that face image is located on if enabled with `MBFaceImage returnFaceImage` property.
 */
@property (nonatomic, readonly) MBSide faceImageSide;

/**
 * The remarks on the residence permit.
 */
@property (nonatomic, readonly, nullable) MBStringResult *remarks;

/**
 * The residence permit type.
 */
@property (nonatomic, readonly, nullable) MBStringResult *residencePermitType;

/**
 * The visa type.
 */
@property (nonatomic, readonly, nullable) MBStringResult *visaType;

/**
 * The manufacturing year.
 */
@property (nonatomic, readonly, nullable) MBStringResult *manufacturingYear;

/**
 * The eligibility category.
 */
@property (nonatomic, readonly, nullable) MBStringResult *vehicleType;

/**
 * The manufacturing year..
 */
@property (nonatomic, readonly, nullable) MBStringResult *eligibilityCategory;

/**
 * The specific document validity.
 */
@property (nonatomic, readonly, nullable) MBStringResult *specificDocumentValidity;

/**
 * The dependents info.
 */
@property (nonatomic, readonly, nullable) NSArray<MBDependentInfo *>* dependentInfos;

/**
 * This member indicates whether the barcode scanning step was utilized during the
 * process.
 * If the barcode scanning step was executed: a parsable barcode image will be stored in the
 * `barcodeCameraFrame`.
 * If the barcode scanning step was not executed: a parsable barcode image will be stored in the
 * `fullDocumentImage`.
 */
@property (nonatomic, readonly) BOOL barcodeStepUsed;

@end

NS_ASSUME_NONNULL_END
