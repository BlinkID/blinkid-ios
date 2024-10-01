//
//  MBVizResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 08/07/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBDriverLicenseDetailedInfo.h"
#import "MBDependentInfo.h"

@class MBStringResult;
@class MBDateResult;

NS_ASSUME_NONNULL_BEGIN

/**
 * MBVizResult contains data extracted from the Visual Inspection Zone.
 */
MB_CLASS_AVAILABLE_IOS(13.0) MB_FINAL
@interface MBVizResult : NSObject

MB_INIT_UNAVAILABLE

/**
* The first name of the document owner.
*/
@property (nonatomic, readonly, nullable) MBStringResult *firstName;

/**
* The last name of the document owner.
*/
@property (nonatomic, readonly, nullable) MBStringResult *lastName;

/**
* The full name of the document owner.
*/
@property (nonatomic, readonly, nullable) MBStringResult *fullName;

/**
 * The father's name of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *fathersName;

/**
 * The mother's name of the document owner.
 */
@property (nonatomic, readonly, nullable) MBStringResult *mothersName;

/**
* The additional name information of the document owner.
*/
@property (nonatomic, readonly, nullable) MBStringResult *additionalNameInformation;

/**
* The localized name of the document owner.
*/
@property (nonatomic, readonly, nullable) MBStringResult *localizedName;

/**
* The address of the document owner.
*/
@property (nonatomic, readonly, nullable) MBStringResult *address;

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
* The sex of the document owner.
*/
@property (nonatomic, readonly, nullable) MBStringResult *sex;

/**
* The date of birth of the document owner.
*/
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
* The date of issue of the document.
*/
@property (nonatomic, readonly, nullable) MBDateResult *dateOfIssue;

/**
* The date of expiry of the document.
*/
@property (nonatomic, readonly, nullable) MBDateResult *dateOfExpiry;

/**
* The document number.
*/
@property (nonatomic, readonly, nullable) MBStringResult *documentNumber;

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
* TThe additional personal identification number.
*/
@property (nonatomic, readonly, nullable) MBStringResult *additionalPersonalIdNumber;

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
 * The driver license detailed info.
 */
@property (nonatomic, readonly, nullable) MBDriverLicenseDetailedInfo *driverLicenseDetailedInfo;

/**
 * Flag that indicates if barcode result is empty
*/
@property (nonatomic, readonly, assign) BOOL empty;

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

@end

NS_ASSUME_NONNULL_END
