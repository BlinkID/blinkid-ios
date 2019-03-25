//
// MBSwedenDlFrontRecognizer.h
//
// Created by juraskrlec on 18/03/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBSwedenDlFrontRecognizerResult.h"

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
* Recognizer which can scan front side of Sweden DL.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSwedenDlFrontRecognizer : MBRecognizer<NSCopying, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors, MBSignatureImage, MBSignatureImageDpi, MBEncodeSignatureImage>

MB_INIT

/**
 * Result of scanning SwedenDlFrontRecognizer
 */
@property (nonatomic, strong, readonly) MBSwedenDlFrontRecognizerResult *result;

/**
* Defines if date of birth of Sweden DL owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
* Defines if date of expiry of Sweden DL should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
* Defines if date of issue of Sweden DL should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
* Defines if issuing agency of Sweden DL should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractIssuingAgency;

/**
* Defines if licence categories of Sweden DL should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractLicenceCategories;

/**
* Defines if name of Sweden DL owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractName;

/**
* Defines if reference number of Sweden DL should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractReferenceNumber;

/**
* Defines if surname of Sweden DL owner should be extracted.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
