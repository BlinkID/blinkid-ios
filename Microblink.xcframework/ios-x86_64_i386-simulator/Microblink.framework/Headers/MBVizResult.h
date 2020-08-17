//
//  MBVizResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 08/07/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBDateResult.h"
#import "MBDriverLicenseDetailedInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * MBVizResult contains data extracted from the Visual Inspection Zone.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBVizResult : NSObject

MB_INIT_UNAVAILABLE

/**
* The first name of the document owner.
*/
@property (nonatomic, readonly) NSString *firstName;

/**
* The last name of the document owner.
*/
@property (nonatomic, readonly) NSString *lastName;

/**
* The full name of the document owner.
*/
@property (nonatomic, readonly) NSString *fullName;

/**
* The additional name information of the document owner.
*/
@property (nonatomic, readonly) NSString *additionalNameInformation;

/**
* The localized name of the document owner.
*/
@property (nonatomic, readonly) NSString *localizedName;

/**
* The address of the document owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The additional address information of the document owner.
*/
@property (nonatomic, readonly) NSString *additionalAddressInformation;

/**
* The place of birth of the document owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
* The nationality of the documet owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The race of the document owner.
*/
@property (nonatomic, readonly) NSString *race;

/**
* The religion of the document owner.
*/
@property (nonatomic, readonly) NSString *religion;

/**
* The profession of the document owner.
*/
@property (nonatomic, readonly) NSString *profession;

/**
* The marital status of the document owner.
*/
@property (nonatomic, readonly) NSString *maritalStatus;

/**
* The residential stauts of the document owner.
*/
@property (nonatomic, readonly) NSString *residentialStatus;

/**
* The employer of the document owner.
*/
@property (nonatomic, readonly) NSString *employer;

/**
* The sex of the document owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The date of birth of the document owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of issue of the document.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The date of expiry of the document.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The document number.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The personal identification number.
*/
@property (nonatomic, readonly) NSString *personalIdNumber;

/**
* The additional number of the document.
*/
@property (nonatomic, readonly) NSString *documentAdditionalNumber;

/**
* TThe additional personal identification number.
*/
@property (nonatomic, readonly) NSString *additionalPersonalIdNumber;

/**
* The issuing authority of the document.
*/
@property (nonatomic, readonly) NSString *issuingAuthority;

/**
 * The driver license detailed info.
 */
@property (nonatomic, readonly, nullable) MBDriverLicenseDetailedInfo *driverLicenseDetailedInfo;

/**
 * Flag that indicates if barcode result is empty
*/
@property (nonatomic, readonly, assign) BOOL empty;

@end

NS_ASSUME_NONNULL_END
