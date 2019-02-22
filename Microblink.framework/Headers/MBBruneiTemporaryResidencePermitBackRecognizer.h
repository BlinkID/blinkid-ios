//
// MBBruneiTemporaryResidencePermitBackRecognizer.h
//
// Created by jcular on 20/02/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBBruneiTemporaryResidencePermitBackRecognizerResult.h"


#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan back side of Brunei temporary residence permit cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBruneiTemporaryResidencePermitBackRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning BruneiTemporaryResidencePermitBackRecognizer
 */
@property (nonatomic, strong, readonly) MBBruneiTemporaryResidencePermitBackRecognizerResult *result;

/**
* Defines if address of Brunei temporary residence permit owner's employer should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if date of issue of Brunei temporary residence permit should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if the passport number of Brunei temporary residence permit owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPassportNumber;

@end

NS_ASSUME_NONNULL_END
