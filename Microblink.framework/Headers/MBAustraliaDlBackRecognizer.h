//
// MBAustraliaDlBackRecognizer.h
//
// Created by juraskrlec on 21/01/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBAustraliaDlBackRecognizerResult.h"


#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan the back side of Australian driver's licences
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBAustraliaDlBackRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning AustraliaDlBackRecognizer
 */
@property (nonatomic, strong, readonly) MBAustraliaDlBackRecognizerResult *result;

/**
* Defines if address of the Australia DL owner should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractAddress;

/**
* Defines if last name of the Australia DL owner should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractLastName;

/**
* Defines if the licence number of the Australia DL should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractLicenceNumber;

/**
* Defines if date of expiry of the Australia DL should be extracted
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractLicenseExpiry;

@end

NS_ASSUME_NONNULL_END
