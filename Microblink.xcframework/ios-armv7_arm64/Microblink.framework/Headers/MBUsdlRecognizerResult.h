//
//  MBUsdlRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 03/01/2018.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBRecognizerResult.h"
#import "MBUsdlKeys.h"
#import "MBDateResult.h"

#import "MBAgeResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A recognizer that can scan PDF417 2D barcodes.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBUsdlRecognizerResult : MBRecognizerResult<NSCopying, MBAgeResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the United States driver license owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the United States driver license owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The full name of the United States driver license owner.
 */
@property (nonatomic, readonly, nullable) NSString *fullName;

/**
 * The full address of the United States driver license owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The date of birth of the United States driver license owner.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
 * The date of issue of the United States driver license.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfIssue;

/**
 * The date of expiry of the United States driver license.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfExpiry;

/**
 * The document number of the United States driver license.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * TThe sex of the United States driver license owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The restrictions to driving privileges for the United States driver license owner.
 */
@property (nonatomic, readonly, nullable) NSString *restrictions;

/**
 * The additional privileges granted to the United States driver license owner.
 */
@property (nonatomic, readonly, nullable) NSString *endorsements;

/**
 * The type of vehicle the driver license owner has privilege to drive.
 */
@property (nonatomic, readonly, nullable) NSString *vehicleClass;

/**
 * Byte array with result of the scan
 */
- (NSData *_Nullable)data;

/**
 * Flag indicating uncertain scanning data
 * E.g obtained from damaged barcode.
 */
- (BOOL)isUncertain;

/**
 * Returns a string value for a given key.
 *
 *  @param usdlKey field key
 *
 *  @return value for a given key
 */
- (NSString *_Nullable)getField:(MBUsdlKeys)usdlKey;

/**
* Array of elements that are not part of AAMVA standard and are specific to each US state.
* If no specific elements existed inside 2D barcode, this is an empty array. Otherwise,
* this array contains list of state-specific elements in the same order as given inside
* barcode.
* NOTE: Size of this array is both state-specific and barcode-specific. Each US state has
* ability to arbitrarily define size and contents of these elements. You can obtain the
* as a parameter.
*/
- (NSArray<NSString *> *_Nullable)optionalElements MB_ATTRIBUTE_DEPRECATED;

@end

NS_ASSUME_NONNULL_END
