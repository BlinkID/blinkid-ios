//
// MBGermanyCombinedRecognizerResult.h
//
// Created by juraskrlec on 19/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBCombinedRecognizerResult.h"
#import "MBDigitalSignatureResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBCombinedFullDocumentImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front and back side of German national ID cards,
 front side of German old ID card and front side of German Passport.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBDigitalSignatureResult, MBFaceImageResult, MBEncodedFaceImageResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult, MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of the Germany ID owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The issuing authority of the Germany ID card.
*/
@property (nonatomic, readonly) NSString *authority;

/**
* The CAN number of the Germany ID card.
*/
@property (nonatomic, readonly) NSString *canNumber;

/**
* The colour of eyes of the Germany ID owner.
*/
@property (nonatomic, readonly) NSString *colourOfEyes;

/**
* The date of birth of the Germany ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The date of expiry of the Germany ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
* The date of issue of the Germany ID card.
*/
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

/**
* The document number of the Germany ID card.
*/
@property (nonatomic, readonly) NSString *documentNumber;

/**
* The given names of the Germany ID owner.
*/
@property (nonatomic, readonly) NSString *givenNames;

/**
* The height of the Germany ID owner.
*/
@property (nonatomic, readonly) NSString *height;

/**
* Determines if all check digits inside MRZ are correct
*/
@property (nonatomic, readonly) BOOL mrzVerified;

/**
* The nationality of the Germany ID owner.
*/
@property (nonatomic, readonly) NSString *nationality;

/**
* The place of birth of the Germany ID owner.
*/
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
* The sex of the Germany ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The surname of the Germany ID owner.
*/
@property (nonatomic, readonly) NSString *surname;
    
/**
 * The full mrz string result.
 */
@property (nonatomic, readonly) NSString *rawMrzString;

@end

NS_ASSUME_NONNULL_END
