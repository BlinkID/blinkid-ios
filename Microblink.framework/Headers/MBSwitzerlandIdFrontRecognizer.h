//
// MBSwitzerlandIdFrontRecognizer.h
//
// Created by juraskrlec on 13/11/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBSwitzerlandIdFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Switzerland ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSwitzerlandIdFrontRecognizer : MBRecognizer <NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning SwitzerlandIdFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBSwitzerlandIdFrontRecognizerResult *result;

/**
* Defines if given name of Switzerland ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractGivenName;

/**
* Defines if surname of Switzerland ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSurname;


@end

NS_ASSUME_NONNULL_END