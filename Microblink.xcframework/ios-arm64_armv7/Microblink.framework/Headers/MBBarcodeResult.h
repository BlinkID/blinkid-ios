//
//  MBBarcodeResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 08/07/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBBarcodeType.h"
#import "MBDateResult.h"
#import "MBDriverLicenseDetailedInfo.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBarcodeResult : NSObject

MB_INIT_UNAVAILABLE

/**
 * Byte array with result of the scan
 */
@property(nonatomic, strong, readonly, nullable) NSData* rawData;

/**
 * Retrieves string content of scanned data
 */
@property(nonatomic, strong, readonly, nullable) NSString* stringData;

/**
 * Flag indicating uncertain scanning data
 * E.g obtained from damaged barcode.
 */
@property(nonatomic, assign, readonly) BOOL uncertain;

/**
 * Type of the barcode scanned
 *
 *  @return Type of the barcode
 */
@property(nonatomic, assign, readonly) MBBarcodeType barcodeType;


/**
* The first name of the document owner.
*/
@property (nonatomic, readonly) NSString *firstName;

/**
* TThe middle name of the document owner.
*/
@property (nonatomic, readonly) NSString *middleName;

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
* The address of the document owner.
*/
@property (nonatomic, readonly) NSString *address;

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
* The issuing authority of the document.
*/
@property (nonatomic, readonly) NSString *issuingAuthority;

/**
* The street address portion of the document owner.
*/
@property (nonatomic, readonly) NSString *street;

/**
* The postal code address portion of the document owner.
*/
@property (nonatomic, readonly) NSString *postalCode;

/**
* The city address portion of the document owner.
*/
@property (nonatomic, readonly) NSString *city;

/**
* The jurisdiction code address portion of the document owner.
*/
@property (nonatomic, readonly) NSString *jurisdiction;

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
