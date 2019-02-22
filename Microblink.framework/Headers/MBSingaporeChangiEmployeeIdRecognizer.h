//
//  MBSingaporeChangiEmployeeIdRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 07/08/2018.
//

#import "MBRecognizer.h"
#import "MBSingaporeChangiEmployeeIdRecognizerResult.h"

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
 * Class for configuring Singapore Changi Employee Id Recognizer.
 *
 * Singapore Changi Employee Id recognizer is used for scanning front side of the Singapore Driver's license..
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeChangiEmployeeIdRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Singapore Changi Employee Id
 */
@property (nonatomic, strong, readonly) MBSingaporeChangiEmployeeIdRecognizerResult *result;

/**
 * Defines if owner's name should be extracted from the Singapore Changi Employee Id
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if company name should be extracted from the Singapore Changi Employee Id
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCompanyName;

/**
 * Defines if birth of expiry should be extracted from the Singapore Changi Employee Id
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

@end

NS_ASSUME_NONNULL_END
