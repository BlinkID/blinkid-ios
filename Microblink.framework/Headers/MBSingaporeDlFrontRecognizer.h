//
//  MBSingaporeDlFrontRecognizer.h
//  MicroblinkDev
//
//  Created by dodo on 25/07/2018.
//

#import "MBRecognizer.h"
#import "MBSingaporeDlFrontRecognizerResult.h"

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
 * Class for configuring Singapore Dl Front Recognizer.
 *
 * Singapore Dl Front recognizer is used for scanning front side of the Singapore Driver's license..
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeDlFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Singapore DL Front
 */
@property (nonatomic, strong, readonly) MBSingaporeDlFrontRecognizerResult *result;

/**
 * Defines if owner's birth date should be extracted from front side of the Singapore DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractBirthDate;

/**
 * Defines if the issue date should be extracted from front side of the Singapore DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssueDate;

/**
 * Defines if owner's name should be extracted from front side of the Singapore DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if valid till should be extracted from front side of the Singapore DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidTill;

@end

NS_ASSUME_NONNULL_END
