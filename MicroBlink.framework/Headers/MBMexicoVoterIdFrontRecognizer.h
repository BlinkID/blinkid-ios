//
// MBMexicoVoterIdFrontRecognizer.h
//
// Created by juraskrlec on 13/11/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBMexicoVoterIdFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Mexican voter id.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBMexicoVoterIdFrontRecognizer : MBRecognizer <NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning MexicoVoterIdFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBMexicoVoterIdFrontRecognizerResult *result;

/**
* Defines if address of Mexico Voter ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if CURP of Mexico Voter ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractCurp;

/**
* Defines if full name of Mexico Voter ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFullName;


@end

NS_ASSUME_NONNULL_END