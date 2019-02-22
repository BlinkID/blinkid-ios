//
//  MBItalyDlFrontRecognizer.h
//  MicroblinkDev
//
//  Created by juraskrlec on 09/10/2018.
//

#import "MBRecognizer.h"
#import "MBItalyDlFrontRecognizerResult.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBSignatureImage.h"
#import "MBEncodeSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer which can scan front side of Italian driver licence.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBItalyDlFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBSignatureImage, MBEncodeSignatureImage, MBSignatureImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Italy Dl Front Recognizer
 */
@property (nonatomic, strong, readonly) MBItalyDlFrontRecognizerResult *result;

/**
 * Defines if address of Italian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if date of birth of Italian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if date of expiry of Italian DL card should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if date of issue of Italian DL card should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if given name of Italian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractGivenName;

/**
 * Defines if issuing authority of Italian DL card should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
 * Defines if licence categories of Italian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLicenceCategories;

/**
 * Defines if place of birth of Italian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if surname of Italian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
