//
//  MBColombiaDlFrontRecognizerResult.h
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

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of the Colombia Dl
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBColombiaDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The date Of Birth of the front side of the Colombia Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
 * The date Of Issue of the front side of the Colombia Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
 * The driver Restrictions of the front side of the Colombia Dl owner.
 */
@property (nonatomic, readonly) NSString *driverRestrictions;

/**
 * The issuing Agency of the front side of the Colombia Dl owner.
 */
@property (nonatomic, readonly) NSString *issuingAgency;

/**
 * The licence Number of the front side of the Colombia Dl owner.
 */
@property (nonatomic, readonly) NSString *licenceNumber;

/**
 * The name of the front side of the Colombia Dl owner.
 */
@property (nonatomic, readonly) NSString *name;

@end

NS_ASSUME_NONNULL_END
