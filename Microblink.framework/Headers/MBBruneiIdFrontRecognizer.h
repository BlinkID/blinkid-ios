//
// MBBruneiIdYellowFrontRecognizer.h
//
// Created by juraskrlec on 17/12/2018
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBBruneiIdFrontRecognizerResult.h"

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
* Recognizer which can scan front side of yellow version of Brunei ID.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBruneiIdFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning BruneiIdYellowFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBBruneiIdFrontRecognizerResult *result;

/**
* Defines if date of birth of Brunei ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
* Defines if full name of Brunei ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractFullName;

/**
* Defines if place of birth of Brunei ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
* Defines if sex of Brunei ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
