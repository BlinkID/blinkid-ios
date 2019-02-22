//
//  MBAustriaDlFrontRecognizer.h
//  MicroblinkDev
//
//  Created by juraskrlec on 09/10/2018.
//

#import "MBRecognizer.h"
#import "MBAustriaDlFrontRecognizerResult.h"

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
 * Recognizer which can scan front side of Austrian national DL cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustriaDlFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBSignatureImage, MBEncodeSignatureImage, MBSignatureImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Austria Dl Front Recognizer
 */
@property (nonatomic, strong, readonly) MBAustriaDlFrontRecognizerResult *result;

/**
 * Defines if date of birth of Austrian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if date of expiry of Austrian DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if date of issue of Austrian DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if first name of Austrian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFirstName;

/**
 * Defines if issuing authority of Austrian DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
 * Defines if name of Austrian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if place of birth of Austrian DL owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if vehicle categories of Austrian DL should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractVehicleCategories;

@end

NS_ASSUME_NONNULL_END
