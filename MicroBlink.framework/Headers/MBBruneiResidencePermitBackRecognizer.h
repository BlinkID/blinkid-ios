//
// MBBruneiResidencePermitBackRecognizer.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBBruneiResidencePermitBackRecognizerResult.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Brunei national Residence Permit cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBruneiResidencePermitBackRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning BruneiResidencePermitBackRecognizer
 */
@property (nonatomic, strong, readonly) MBBruneiResidencePermitBackRecognizerResult *result;

/**
* Defines if address of Brunei Residence Permit card owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if date of issue of Brunei Residence Permit card should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if the race of Brunei Residence Permit card owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractRace;

@end

NS_ASSUME_NONNULL_END
