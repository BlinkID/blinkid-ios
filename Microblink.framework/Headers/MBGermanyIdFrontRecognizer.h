//
// MBGermanyIdFrontRecognizer.h
//
// Created by juraskrlec on 13/11/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBGermanyIdFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Germany national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBGermanyIdFrontRecognizer : MBRecognizer <NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning GermanyIdFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBGermanyIdFrontRecognizerResult *result;

/**
* Defines if CAN number of Germany ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractCanNumber;

/**
* Defines if date of expiry of Germany ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if document number of Germany ID should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDocumentNumber;

/**
* Defines if given names of Germany ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractGivenNames;

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