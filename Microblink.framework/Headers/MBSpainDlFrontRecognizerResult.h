//
//  MBSpainDlFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 17/08/2018.
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
 * Class representing values obtained when scanning front side of Spain DL
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSpainDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the Spain DL owner
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The surname of the Spain DL owner
 */
@property (nonatomic, readonly, nullable) NSString *surname;

/**
 * The licence number of the Spain DL
 */
@property (nonatomic, readonly, nullable) NSString *number;

/**
 * The place of birth of Spain DL owner
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The issuing authority of the Spain DL
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The licence categories of the Spain DL
 */
@property (nonatomic, readonly, nullable) NSString *licenceCategories;

/**
 * The date of birth of Spain DL owner
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
 * The date of issue of Spain DL
 */
@property (nonatomic, readonly, nullable) MBDateResult *validFrom;

/**
 * The date of expiry of Spain DL
 */
@property (nonatomic, readonly, nullable) MBDateResult *validUntil;

@end

NS_ASSUME_NONNULL_END
