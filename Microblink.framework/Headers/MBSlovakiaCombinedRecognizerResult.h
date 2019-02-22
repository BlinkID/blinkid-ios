//
//  MBSlovakiaCombinedRecognizerResult.h
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

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning both front and back side of Slovak ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSlovakiaCombinedRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBCombinedFullDocumentImageResult, MBSignatureImageResult, MBDigitalSignatureResult, MBEncodedFaceImageResult, MBEncodedSignatureImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the Slovak ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Slovak ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The identity card number of Slovak ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The sex of the Slovak ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The nationality of the Slovak ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The PIN of the Slovak ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *personalIdentificationNumber;

/**
 * The date of birth of Slovak ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The date of expiry of Slovak ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * The address of the Slovak ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The issuing authority of Slovak ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The date of issue of Slovak ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The surname at birth of Slovak ID.
 */
@property (nonatomic, readonly, nullable) NSString *surnameAtBirth;

/**
 * The special remarks of Slovak ID.
 */
@property (nonatomic, readonly, nullable) NSString *specialRemarks;

/**
 * The place of birth of the Slovak ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * YES if all check digits inside MRZ are correct, NO otherwise.
 * More specifically, YES if MRZ complies with ICAO Document 9303 standard, NO otherwise.
 */
@property (nonatomic, readonly) BOOL mrzVerified;

@end

NS_ASSUME_NONNULL_END
