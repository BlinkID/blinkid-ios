//
//  MBColombiaDlFrontRecognizer.h
//  MicroblinkDev
//
//  Created by juraskrlec on 25/09/2018.
//

#import "MBRecognizer.h"
#import "MBColombiaDlFrontRecognizerResult.h"

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
 * Recognizer which can scan front side of Colombia drivers licence.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBColombiaDlFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Colombia Dl Front Recognizer
 */
@property (nonatomic, strong, readonly) MBColombiaDlFrontRecognizerResult *result;

/**
 * Defines if the date of birth of the Colombia Dl owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if the driver restrictions of the Colombia Dl owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDriverRestrictions;

/**
 * Defines if the issuing agency of the Colombia Dl card should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAgency;

/**
 * Defines if the name of the Colombia Dl owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

@end

NS_ASSUME_NONNULL_END
