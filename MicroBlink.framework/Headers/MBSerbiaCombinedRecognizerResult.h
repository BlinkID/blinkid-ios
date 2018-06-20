//
//  MBSerbiaCombinedRecognizerResult.h
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
 * Class representing values obtained when scanning both front and back side of Czech ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSerbiaCombinedRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBCombinedFullDocumentImageResult, MBSignatureImageResult, MBDigitalSignatureResult, MBEncodedFaceImageResult, MBEncodedSignatureImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The identity card number of Serbian ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The date of expiry of Serbian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;


/**
 * The date of issue of Serbian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The JMBG of Serbian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *jmbg;

/**
 * The first name of the Serbian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Serbian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The date of birth of Serbian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The nationality of the Serbian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The issuer of Serbian ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuer;

/**
 * The sex of the Serbian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * YES if all check digits inside MRZ are correct, NO otherwise.
 * More specifically, YES if MRZ complies with ICAO Document 9303 standard, NO otherwise.
 */
@property (nonatomic, readonly) BOOL mrzVerified;

@end

NS_ASSUME_NONNULL_END
