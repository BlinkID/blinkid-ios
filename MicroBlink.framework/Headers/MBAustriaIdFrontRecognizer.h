//
//  MBAustriaIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBAustriaIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBEncodeFaceImage.h"
#import "MBGlareDetection.h"
#import "MBRecognizer.h"
#import "MBMicroBlinkInitialization.h"
#import "MBMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Austrian ID Front Recognizer.
 *
 * Aus ID Front recognizer is used for scanning front side of Austrian Id.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBAustriaIdFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBFaceImageDpi, MBSignatureImage, MBSignatureImageDpi, MBFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBEncodeFaceImage>

MB_INIT

/**
 * Austrian Id Front recognizer result
 */
@property (nonatomic, strong, readonly) MBAustriaIdFrontRecognizerResult *result;

/**
 *  Defines if sex of Austrian Id owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if surname of Austrian Id owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if given name of Austrian Id owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractGivenName;

/**
 * Defines if date of birth should be extracted from Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

@end

NS_ASSUME_NONNULL_END
