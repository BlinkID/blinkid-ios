//
//  MBCroatiaCombinedRecognizerResult.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBMicroblinkDefines.h"
#import "MBRecognizerResult.h"

#import "MBCombinedRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBDigitalSignatureResult.h"
#import "MBCombinedFullDocumentImageResult.h"

#import "MBEncodedFaceImageResult.h"
#import "MBEncodedSignatureImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

#import "MBDateResult.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning both front and back side of Austria ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustriaCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBCombinedFullDocumentImageResult, MBSignatureImageResult, MBDigitalSignatureResult, MBEncodedFaceImageResult, MBEncodedSignatureImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The gien name of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *givenName;

/**
 * The surname of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *surname;

/**
 * The document number of the Austrian ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The nationaliy of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The sex of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The date of birth of Austrian ID owner
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
 * The place of birth of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The issuing authority of Austrian ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The principal residence of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *principalResidence;

/**
 * The height of Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *height;

/**
 * The date of issuance of the Austrian ID
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfIssuance;

/**
 * The date of expiry of Austrian ID
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfExpiry;

/**
 * The eye eyeColour of Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *eyeColour;

/**
 * Whether check digits in machine readable zone of the Austrian ID are OK.
 */
@property (nonatomic, readonly, assign) BOOL mrtdVerified;

@end

NS_ASSUME_NONNULL_END
