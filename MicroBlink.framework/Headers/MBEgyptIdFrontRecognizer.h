//
//  MBEgyptIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBEgyptIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBFaceImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Egypt ID Front Recognizer.
 *
 * Egypt ID Front recognizer is used for scanning front side of Egypt ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBEgyptIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBFaceImage, MBGlareDetection>

MB_INIT

/**
 * Egypt ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBEgyptIdFrontRecognizerResult *result;

/**
 * Defines if owner's national number should be extracted from Egypt ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationalNumber;

@end

NS_ASSUME_NONNULL_END
