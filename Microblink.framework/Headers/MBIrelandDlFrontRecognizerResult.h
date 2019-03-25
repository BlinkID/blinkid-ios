//
//  MBIrelandDlFrontRecognizerResult.h
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
 * Class representing values obtained when scanning front side of the Ireland Dl
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBIrelandDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
 * The address of the front side of the Ireland Dl owner.
 */
@property (nonatomic, readonly) NSString *address;

/**
 * The date Of Birth of the front side of the Ireland Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
 * The date Of Expiry of the front side of the Ireland Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
 * The date Of Issue of the front side of the Ireland Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
 * The driver Number of the front side of the Ireland Dl owner.
 */
@property (nonatomic, readonly) NSString *driverNumber;

/**
 * The first Name of the front side of the Ireland Dl owner.
 */
@property (nonatomic, readonly) NSString *firstName;

/**
 * The issued By of the front side of the Ireland Dl owner.
 */
@property (nonatomic, readonly) NSString *issuedBy;

/**
 * The licence Categories of the front side of the Ireland Dl owner.
 */
@property (nonatomic, readonly) NSString *licenceCategories;

/**
 * The licence Number of the front side of the Ireland Dl owner.
 */
@property (nonatomic, readonly) NSString *licenceNumber;

/**
 * The place Of Birth of the front side of the Ireland Dl owner.
 */
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
 * The surname of the front side of the Ireland Dl owner.
 */
@property (nonatomic, readonly) NSString *surname;

@end

NS_ASSUME_NONNULL_END
