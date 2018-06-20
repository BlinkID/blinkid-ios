//
//  MBNewZealandDlFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of New Zealand DL
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBNewZealandDlFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFaceImageResult, MBSignatureImageResult, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstNames;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *surname;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSDate *issueDate;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSDate *expiryDate;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, assign) BOOL donorIndicator;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The license number of the New Zealand Driver License.
 */
@property (nonatomic, readonly, nullable) NSString *licenseNumber;

/**
 * The card version of the New Zealand Driver License.
 */
@property (nonatomic, readonly, nullable) NSString *cardVersion;

@end

NS_ASSUME_NONNULL_END
