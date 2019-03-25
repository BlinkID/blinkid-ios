//
// MBGermanyCombinedRecognizer.h
//
// Created by juraskrlec on 19/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBGermanyCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"
#import "MBDigitalSignature.h"

#import "MBGlareDetection.h"
#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"
#import "MBSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBEncodeSignatureImage.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front and back side of German national ID cards,
 front side of German old ID card and front side of German Passport.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBGermanyCombinedRecognizer : MBRecognizer<NSCopying, MBCombinedRecognizer, MBDigitalSignature, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning GermanyCombinedRecognizer
 */
@property (nonatomic, strong, readonly) MBGermanyCombinedRecognizerResult *result;

/**
* Defines if address of German ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if issuing authority of German ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAuthority;

/**
* Defines if CAN number of Germany ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractCanNumber;

/**
* Defines if colour of eyes of German ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractColourOfEyes;

/**
* Defines if date of expiry of Germany ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if date of issue of German ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if document number of Germany ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDocumentNumber;

/**
* Defines if given name of German passport owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractGivenName;

/**
* Defines if given names of Germany ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractGivenNames;

/**
* Defines if height of German ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractHeight;

/**
* Defines if nationality  of Germany ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractNationality;

/**
* Defines if place of birth of Germany ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
* Defines if surname of Germany ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
