//
//  MBColombiaIdFrontRecognizerRecognizer.h
//  MicroblinkDev
//
//  Created by dodo on 24/07/2018.
//

#import "MBRecognizer.h"
#import "MBColombiaIdFrontRecognizerResult.h"

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
 * Class for configuring Colombia Id Front Recognizer.
 *
 * Colombia Id Front recognizer is used for scanning front side of the Colombia Id.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBColombiaIdFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBSignatureImage, MBEncodeSignatureImage, MBSignatureImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Colombia Id Front
 */
@property (nonatomic, strong, readonly) MBColombiaIdFrontRecognizerResult *result;

/**
 * Defines if owner's first name should be extracted from front side of the Colombia Id
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFirstName;

/**
 * Defines if owner's last name should be extracted from front side of the Colombia Id
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLastName;

@end

NS_ASSUME_NONNULL_END
