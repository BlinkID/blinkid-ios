//
//  MBAustriaIdFrontRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBAustriaIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
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
#import "MBRecognizer.h"
#import "MBMicroblinkInitialization.h"
#import "MBMicroblinkDefines.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Austrian ID Front Recognizer.
 *
 * Aus ID Front recognizer is used for scanning front side of Austrian Id.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBAustriaIdFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBSignatureImage, MBEncodeSignatureImage, MBSignatureImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

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
