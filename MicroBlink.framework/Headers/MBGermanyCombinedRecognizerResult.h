//
//  MBGermanyCombinedRecognizerResult.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBCombinedRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBDigitalSignatureResult.h"
#import "MBCombinedFullDocumentImageResult.h"

#import "MBEncodedFaceImageResult.h"
#import "MBEncodedSignatureImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning both front and back side of German ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyCombinedRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBCombinedFullDocumentImageResult, MBSignatureImageResult, MBDigitalSignatureResult, MBEncodedFaceImageResult, MBEncodedSignatureImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The nationality of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The place of birth of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The sex of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The date of birth of German ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The date of issue of German ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The date of expiry of German ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * The identity card number of German ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The address of the German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The issuing authority of German ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The height of German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *height;

/**
 * The eye color of German ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *eyeColor;

/**
 * The CAN number of German ID.
 */
@property (nonatomic, readonly, nullable) NSString *canNumber;

/**
 * YES if all check digits inside MRZ are correct, NO otherwise.
 * More specifically, YES if MRZ complies with ICAO Document 9303 standard, NO otherwise.
 */
@property (nonatomic, readonly) BOOL mrzVerified;

@end

NS_ASSUME_NONNULL_END
