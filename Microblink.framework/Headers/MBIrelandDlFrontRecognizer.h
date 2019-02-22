//
//  MBIrelandDlFrontRecognizer.h
//  MicroblinkDev
//
//  Created by juraskrlec on 25/09/2018.
//

#import "MBRecognizer.h"
#import "MBIrelandDlFrontRecognizerResult.h"

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
 * Recognizer which can scan front side of Ireland drivers license.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBIrelandDlFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBSignatureImage, MBEncodeSignatureImage, MBSignatureImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Ireland Dl Front Recognizer
 */
@property (nonatomic, strong, readonly) MBIrelandDlFrontRecognizerResult *result;

/**
 * Defines if address of Ireland DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if date of birth of Ireland DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if date of expiry of Ireland DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if date of issue of Ireland DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if first name of Ireland DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFirstName;

/**
 * Defines if issuing authority of Ireland DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuedBy;

/**
 * Defines if licence categories of Ireland DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLicenceCategories;

/**
 * Defines if licence number of Ireland DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLicenceNumber;

/**
 * Defines if place of birth of Ireland DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if surname of Ireland DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
