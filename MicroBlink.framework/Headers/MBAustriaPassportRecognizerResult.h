//
//  MBAustriaPassportRecognizerResult.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 11/06/2018.
//

#import "MBRecognizerResult.h"
#import "MBMrzResult.h"
#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning Aus Passport
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustriaPassportRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE
/**
 * The mrz of the back side of Austria Passport.
 */
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
 * The surname of the Austrian Passport owner.
 */
@property (nonatomic, readonly) NSString *surname;

/**
 * The given Name of the Austrian Passport owner.
 */
@property (nonatomic, readonly) NSString *givenName;

/**
 * The nationality of the Austrian Passport owner.
 */
@property (nonatomic, readonly) NSString *nationality;

/**
 * The place Of Birth of the Austrian Passport owner.
 */
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
 * The issuing Authority of the Austrian Passport.
 */
@property (nonatomic, readonly) NSString *issuingAuthority;

/**
 * The height of the Austrian Passport owner.
 */
@property (nonatomic, readonly) NSString *height MB_PROPERTY_DEPRECATED;

/**
 * The sex of the Austrian Passport owner.
 */
@property (nonatomic, readonly) NSString *sex;

/**
 * The passport Number of the Austrian Passport.
 */
@property (nonatomic, readonly) NSString *passportNumber;

/**
 * The date Of Issue of the Austrian Passport.
 */
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
 * The date Of Birth of the Austrian Passport owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
 * The date Of Expiry of the Austrian Passport.
 */
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

@end

NS_ASSUME_NONNULL_END
