//
// MBBruneiResidencePermitFrontRecognizer.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBBruneiResidencePermitFrontRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front side of Brunei residence permits.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBruneiResidencePermitFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning BruneiResidencePermitFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBBruneiResidencePermitFrontRecognizerResult *result;

/**
* Defines if date of birth of Brunei residence permit owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
* Defines if full name of Brunei residence permit owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFullName;

/**
* Defines if place of birth of Brunei residence permit owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
* Defines if sex of Brunei residence permit owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
