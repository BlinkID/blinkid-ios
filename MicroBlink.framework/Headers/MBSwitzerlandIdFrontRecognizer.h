//
//  MBSwitzerlandIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSwitzerlandIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBSignatureImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Swiss ID Front Recognizer.
 *
 * Swiss ID Front recognizer is used for scanning front side of Swiss ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwitzerlandIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBSignatureImage, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Swiss ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBSwitzerlandIdFrontRecognizerResult *result;

/**
 * Defines if owner's first name should be extracted from Swiss ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractGivenName;

/**
 * Defines if owner's last name should be extracted from Swiss ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
