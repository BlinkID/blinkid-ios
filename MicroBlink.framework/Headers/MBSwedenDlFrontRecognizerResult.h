//
//  MBSwedenDlFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by DoDo on 16/06/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBFaceImageResult.h"
#import "MBSignatureImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Sweden Dl
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwedenDlFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFullDocumentImageResult, MBFaceImageResult, MBSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
 * The Surname of the Sweden DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *surname;

/**
 * The Name of the Sweden DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The Date Of Birth of the Sweden DL owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The Date Of Issue of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The Date Of Expiry of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * The Issuing Agency of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAgency;

/**
 * The Reference Number of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSString *referenceNumber MB_PROPERTY_DEPRECATED;

/**
 * The Licence Categories of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSString *licenceCategories;

/**
 * The Licence Numer of the Sweden DL.
 */
@property (nonatomic, readonly, nullable) NSString *licenceNumber;

@end

NS_ASSUME_NONNULL_END
