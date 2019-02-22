//
//  MBItalyDlFrontRecognizerResult.h
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
 * Class representing values obtained when scanning front side of the Italy Dl
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBItalyDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE


/**
 * The address of the front side of the Italy Dl owner.
 */
@property (nonatomic, readonly) NSString *address;

/**
 * The date Of Birth of the front side of the Italy Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
 * The date Of Expiry of the front side of the Italy Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
 * The date Of Issue of the front side of the Italy Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
 * The given Name of the front side of the Italy Dl owner.
 */
@property (nonatomic, readonly) NSString *givenName;

/**
 * The issuing Authority of the front side of the Italy Dl owner.
 */
@property (nonatomic, readonly) NSString *issuingAuthority;

/**
 * The licence Categories of the front side of the Italy Dl owner.
 */
@property (nonatomic, readonly) NSString *licenceCategories;

/**
 * The licence Number of the front side of the Italy Dl owner.
 */
@property (nonatomic, readonly) NSString *licenceNumber;

/**
 * The place Of Birth of the front side of the Italy Dl owner.
 */
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
 * The surname of the front side of the Italy Dl owner.
 */
@property (nonatomic, readonly) NSString *surname;

@end

NS_ASSUME_NONNULL_END
