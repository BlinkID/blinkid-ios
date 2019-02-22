//
//  MBUnitedArabEmiratesDlFrontRecognizer.h
//  MicroblinkDev
//
//  Created by juraskrlec on 21/08/2018.
//

#import "MBRecognizer.h"
#import "MBUnitedArabEmiratesDlFrontRecognizerResult.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer which can scan front side of UAE drivers license.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBUnitedArabEmiratesDlFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning United Arab Emirates Dl Front Recognizer
 */
@property (nonatomic, strong, readonly) MBUnitedArabEmiratesDlFrontRecognizerResult *result;

/**
 * Defines if date of birth of UAE DL owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if issue date of UAE DL should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssueDate;

/**
 * Defines if license number of UAE DL should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLicenseNumber;

/**
 * Defines if licensing authority code of UAE DL should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLicensingAuthority;

/**
 * Defines if name of UAE DL owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if nationality of UAE DL owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if place of issue of UAE DL should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfIssue;

@end

NS_ASSUME_NONNULL_END
