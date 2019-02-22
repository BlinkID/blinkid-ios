//
//  MBSwitzerlandDlFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by dodo on 25/07/2018.
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
 * Class representing values obtained when scanning front side of the Switzerland DL
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwitzerlandDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE


/**
 * The date of birth of the Switzerland DL owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
 * The date of rxpiry of the Switzerland DL.
 */
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
 * The date of issue of the Switzerland DL.
 */
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
 * If YES, then this Switzerland DL will never expire.
 */
@property (nonatomic, readonly) BOOL expiryDatePermanent;

/**
 * The first name of the Switzerland DL owner.
 */
@property (nonatomic, readonly) NSString *firstName;

/**
 * The issuing authority of the Switzerland DL.
 */
@property (nonatomic, readonly) NSString *issuingAuthority;

/**
 * The last name of the Switzerland DL owner.
 */
@property (nonatomic, readonly) NSString *lastName;

/**
 * The license number of the Switzerland DL.
 */
@property (nonatomic, readonly) NSString *licenseNumber;

/**
 * The place of birth of the Switzerland DL owner.
 */
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
 * The vehicle categories of the Switzerland DL.
 */
@property (nonatomic, readonly) NSString *vehicleCategories;

@end

NS_ASSUME_NONNULL_END
