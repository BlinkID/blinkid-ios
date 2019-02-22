//
//  MBCroatiaCombinedRecognizerResult.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBMicroblinkDefines.h"
#import "MBLegacyRecognizerResult.h"

#import "MBCombinedRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBDigitalSignatureResult.h"
#import "MBCombinedFullDocumentImageResult.h"

#import "MBEncodedFaceImageResult.h"
#import "MBEncodedSignatureImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning both front and back side of Czech ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCzechiaCombinedRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBCombinedFullDocumentImageResult, MBSignatureImageResult, MBDigitalSignatureResult, MBEncodedFaceImageResult, MBEncodedSignatureImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The document number of the Czech ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The sex of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The nationality of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The date of birth of Czech ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The date of expiry of Czech ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * The place of birth of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The full address of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The issuing authority of Czech ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The date of issue of Czech ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The personal identification number of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *personalIdentificationNumber;

/**
 * YES if all check digits inside MRZ are correct, NO otherwise.
 * More specifically, YES if MRZ complies with ICAO Document 9303 standard, NO otherwise.
 */
@property (nonatomic, readonly) BOOL mrzVerified;

@end

NS_ASSUME_NONNULL_END
