//
//  MBNewZealandDlFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
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
 * Class representing values obtained when scanning front side of New Zealand DL
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBNewZealandDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

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
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfIssue;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfExpiry;

/**
 * The last name of the New Zealand Driver License owner.
 */
@property (nonatomic, readonly, assign) BOOL donorIndicator MB_PROPERTY_DEPRECATED;

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
@property (nonatomic, readonly, nullable) NSString *cardVersion MB_PROPERTY_DEPRECATED;

@end

NS_ASSUME_NONNULL_END
