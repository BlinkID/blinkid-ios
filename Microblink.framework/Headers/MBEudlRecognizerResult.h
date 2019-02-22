//
//  MBEudlRecognizerResult.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 28/05/2018.
//

#import "MBRecognizerResult.h"

#import "MBEudlCountry.h"
#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"
#import "MBDateResult.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning EU Driver License
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBEudlRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first Name of the EU Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last Name of the EU Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The birth Data of the EU Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *birthData;

/**
 * The issue Date of the EU Driver License owner.
 */
@property (nonatomic, readonly, nullable) MBDateResult *issueDate;

/**
 * The expiry Date of the EU Driver License owner.
 */
@property (nonatomic, readonly, nullable) MBDateResult *expiryDate;

/**
 * The issuing Authority of the EU Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The personal Number of the EU Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *personalNumber;

/**
 * The driver Number of the EU Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *driverNumber;

/**
 * The address of the EU Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The country of the EU Driver License owner.
 */
@property (nonatomic, readonly) MBEudlCountry country;

@end

NS_ASSUME_NONNULL_END
