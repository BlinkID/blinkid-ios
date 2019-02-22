//
//  MBSingaporeIdFrontRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBRecognizer.h"
#import "MBSingaporeIdFrontRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Singapore ID Front Recognizer.
 *
 * Singapore ID Front recognizer is used for scanning front side of Singapore ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeIdFrontRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Singapore ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBSingaporeIdFrontRecognizerResult *result;

/**
 *  Defines if name of Singaporean ID card owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractName;

/**
 *  Defines if race of Singaporean ID card owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractRace;

/**
 *  Defines if date of birth of Singaporean ID card owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractDateOfBirth;

/**
 *  Defines if sex of Singaporean ID card owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractSex;

/**
 *  Defines if country/place of birth of Singaporean ID card owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractCountryOfBirth;

@end

NS_ASSUME_NONNULL_END
