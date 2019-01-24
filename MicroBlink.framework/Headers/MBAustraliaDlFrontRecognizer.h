//
// MBAustraliaDlFrontRecognizer.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBAustraliaDlFrontRecognizerResult.h"

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
* Recognizer which can scan the front side of Australian driver's licences.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBAustraliaDlFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning AustraliaDlFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBAustraliaDlFrontRecognizerResult *result;

/**
* Defines if address of Australian DL owner should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if date of birth of Australian DL owner should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
* Defines if full name of Australian DL owner should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFullName;

/**
* Defines if date of expiry of Australian DL should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractLicenseExpiry;

@end

NS_ASSUME_NONNULL_END
