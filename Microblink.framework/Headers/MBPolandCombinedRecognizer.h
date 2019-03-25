//
// MBPolandCombinedRecognizer.h
//
// Created by juraskrlec on 18/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBPolandCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"
#import "MBDigitalSignature.h"

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
* Recognizer which can scan front and back side of Poland national ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBPolandCombinedRecognizer : MBRecognizer<NSCopying, MBCombinedRecognizer, MBDigitalSignature, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning PolandCombinedRecognizer
 */
@property (nonatomic, strong, readonly) MBPolandCombinedRecognizerResult *result;

/**
* Defines if date of birth of Poland ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
* Defines if family name of Poland ID owner should be extracted.
*
* Default: 'false'
*/
@property (nonatomic, assign) BOOL extractFamilyName;

/**
* Defines if given names of Poland ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractGivenNames;

/**
* Defines if parents given names of Poland ID owner should be extracted.
*
* Default: 'false'
*/
@property (nonatomic, assign) BOOL extractParentsGivenNames;

/**
* Defines if sex of Poland ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSex;

/**
* Defines if surname of Poland ID owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
