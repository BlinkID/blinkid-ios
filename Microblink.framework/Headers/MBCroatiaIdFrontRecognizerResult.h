//
//  MBCroatiaIdFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by DoDo on 11/04/2018.
//

#ifndef MBCroatiaIdFrontRecognizerResult_h
#define MBCroatiaIdFrontRecognizerResult_h

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
 * Class representing values obtained when scanning front side of Croatian ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCroatiaIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

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
 * The document number of the Croatian ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The sex of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The citizenship of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *citizenship;

/**
 * The date of birth of Croatian ID owner
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
 * The document date of expiry of the Croatian ID
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfExpiry;

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
