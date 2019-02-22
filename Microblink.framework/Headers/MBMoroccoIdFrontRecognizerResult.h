//
//  MBMoroccoIdFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by dodo on 24/07/2018.
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
 * Class representing values obtained when scanning front side of the Morocco ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMoroccoIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE


/**
 * The date of birth of the Morocco ID owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
 * The date of expiry of the Morocco ID.
 */
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
 * The document number of the Morocco ID.
 */
@property (nonatomic, readonly) NSString *documentNumber;

/**
 * The name of the Morocco ID owner.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The place of birth of the Morocco ID owner.
 */
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
 * The sex of the Morocco ID owner.
 */
@property (nonatomic, readonly) NSString *sex;

/**
 * The surname of the Morocco ID owner.
 */
@property (nonatomic, readonly) NSString *surname;

@end

NS_ASSUME_NONNULL_END
