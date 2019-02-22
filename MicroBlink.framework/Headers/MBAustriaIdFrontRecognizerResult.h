//
//  MBAustriaIdFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBRecognizerResult.h"

#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"
#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBDateResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Aus ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustriaIdFrontRecognizerResult :  MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the Austrian Id owner.
 */
@property (nonatomic, readonly, nullable) NSString *givenName;

/**
 * The last name of the Austrian Id owner.
 */
@property (nonatomic, readonly, nullable) NSString *surname;

/**
 * The document number of the Austrian Id.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The date of birth of the Austrian Id owner.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
 * The sex of the Austrian Id owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

@end

NS_ASSUME_NONNULL_END
