//
//  MBCroatiaIdFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by DoDo on 11/04/2018.
//

#ifndef MBCroatiaIdFrontRecognizerResult_h
#define MBCroatiaIdFrontRecognizerResult_h

#import "MBMicroBlinkDefines.h"
#import "MBLegacyRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBSignatureImageResult.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Croatian ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCroatiaIdFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFaceImageResult, MBFullDocumentImageResult, MBSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The identity card number of Croatian ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The sex of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The citizenship of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *citizenship;

/**
 * The date of birth of Croatian ID owner in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of Croatian ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The document date of expiry of the Croatian ID in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDocumentDateOfExpiry;

/**
 * The document date of expiry of the Croatian ID
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * Check if date of expiry is permanent on the Croatian ID.
 */
@property (nonatomic, readonly) BOOL dateOfExpiryPermanent;

/**
 * YES if the document is bilingual
 */
@property (nonatomic, readonly) BOOL documentBilingual;

@end

NS_ASSUME_NONNULL_END

#endif /* MBCroatiaIdFrontRecognizerResult_h */
