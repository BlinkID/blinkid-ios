//
//  MBSwitzerlandDlFrontRecognizer.h
//  MicroblinkDev
//
//  Created by dodo on 25/07/2018.
//

#import "MBRecognizer.h"
#import "MBSwitzerlandDlFrontRecognizerResult.h"

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
 * Class for configuring Switzerland DL Front Recognizer.
 *
 * Switzerland DL Front recognizer is used for scanning front side of the Switzerland DL.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwitzerlandDlFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBSignatureImage, MBEncodeSignatureImage, MBSignatureImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Switzerland DL Front
 */
@property (nonatomic, strong, readonly) MBSwitzerlandDlFrontRecognizerResult *result;

/**
 * Defines if owner's date of birth should be extracted from front side of the Switzerland DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if date of expiry should be extracted from front side of the Switzerland DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if date of issue should be extracted from front side of the Switzerland DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if owner's first name should be extracted from front side of the Switzerland DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFirstName;

/**
 * Defines if issuing authority should be extracted from front side of the Switzerland DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
 * Defines if owner's last name should be extracted from front side of the Switzerland DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLastName;

/**
 * Defines if owner's place of birth should be extracted from front side of the Switzerland DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if vehicle categories should be extracted from front side of the Switzerland DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractVehicleCategories;

@end

NS_ASSUME_NONNULL_END
