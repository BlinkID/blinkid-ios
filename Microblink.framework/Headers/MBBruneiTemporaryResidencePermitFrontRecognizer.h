//
// MBBruneiTemporaryResidencePermitFrontRecognizer.h
//
// Created by jcular on 21/02/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBBruneiTemporaryResidencePermitFrontRecognizerResult.h"


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
* Recognizer which can scan front side of Brunei Temporary Residence Permit.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBruneiTemporaryResidencePermitFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning BruneiTemporaryResidencePermitFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBBruneiTemporaryResidencePermitFrontRecognizerResult *result;

/**
* Defines if address of Brunei Temporary Residence Permit owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if date of birth of Brunei Temporary Residence Permit owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
* Defines if full name of Brunei Temporary Residence Permit owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFullName;

/**
* Defines if place of birth of Brunei Temporary Residence Permit owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
* Defines if sex of Brunei Temporary Residence Permit owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
