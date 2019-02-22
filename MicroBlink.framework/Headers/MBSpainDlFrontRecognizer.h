//
//  MBSpainDlFrontRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 17/08/2018.
//

#import "MBRecognizer.h"
#import "MBSpainDlFrontRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBSignatureImage.h"
#import "MBEncodeSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Spain Driver's License Front Recognizer.
 *
 * Recognizer which can scan front side of Spain national DL cards
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSpainDlFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBSignatureImage, MBEncodeSignatureImage, MBSignatureImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Spain Dl Front recognizer result
 */
@property (nonatomic, strong, readonly) MBSpainDlFrontRecognizerResult *result;

/**
 *  Defines if first name of Spain DL owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractFirstName;

/**
 *  Defines if surname of Spain DL owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 *  Defines if date of birth of Spain DL owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 *  Defines if place of birth of Spain DL owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if date of issue of Spain DL should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidFrom;

/**
 * Defines if date of expiry of Spain DL should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidUntil;

/**
 * Defines if issuing authority of Spain DL should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
 * Defines if licence categories of Spain DL should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLicenceCategories;

@end

NS_ASSUME_NONNULL_END
