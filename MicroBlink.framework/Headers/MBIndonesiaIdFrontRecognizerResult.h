//
//  MBIndonesiaIdFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by juraskrlec on 25/09/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of the Indonesia Id
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBIndonesiaIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
 * The address of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *address;

/**
 * The blood Type of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *bloodType MB_PROPERTY_DEPRECATED;

/**
 * The citizenship of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *citizenship;

/**
 * The city of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *city;

/**
 * The date Of Birth of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
 * The date Of Expiry of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
 * The date Of Expiry Permanent of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly, assign) BOOL dateOfExpiryPermanent;

/**
 * The district of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *district MB_PROPERTY_DEPRECATED;

/**
 * The document Number of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *documentNumber;

/**
 * The kel Desa of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *kelDesa MB_PROPERTY_DEPRECATED;

/**
 * The marital Status of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *maritalStatus;

/**
 * The name of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The occupation of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *occupation;

/**
 * The place Of Birth of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
 * The province of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *province;

/**
 * The religion of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *religion;

/**
 * The rt of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *rt MB_PROPERTY_DEPRECATED;

/**
 * The rw of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *rw MB_PROPERTY_DEPRECATED;

/**
 * The sex of the front side of the Indonesia Id owner.
 */
@property (nonatomic, readonly) NSString *sex;

@end

NS_ASSUME_NONNULL_END
