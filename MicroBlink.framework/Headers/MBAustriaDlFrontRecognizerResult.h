//
//  MBAustriaDlFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by juraskrlec on 09/10/2018.
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
 * Class representing values obtained when scanning front side of the Austria Dl
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustriaDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
 * The date Of Birth of the front side of the Austria Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
 * The date Of Expiry of the front side of the Austria Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
 * The date Of Issue of the front side of the Austria Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
 * The first Name of the front side of the Austria Dl owner.
 */
@property (nonatomic, readonly) NSString *firstName;

/**
 * The issuing Authority of the front side of the Austria Dl owner.
 */
@property (nonatomic, readonly) NSString *issuingAuthority;

/**
 * The licence Number of the front side of the Austria Dl owner.
 */
@property (nonatomic, readonly) NSString *licenceNumber;

/**
 * The name of the front side of the Austria Dl owner.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The place Of Birth of the front side of the Austria Dl owner.
 */
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
 * The vehicle Categories of the front side of the Austria Dl owner.
 */
@property (nonatomic, readonly) NSString *vehicleCategories;

@end

NS_ASSUME_NONNULL_END
