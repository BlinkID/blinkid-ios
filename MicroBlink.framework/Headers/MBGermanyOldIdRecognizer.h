//
//  MBGermanyOldIdRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBGermanyOldIdRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBSignatureImage.h"
#import "MBFaceImage.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring German Old ID Recognizer.
 *
 * German Old ID recognizer is used for scanning German Old ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyOldIdRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBFaceImage, MBSignatureImage, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * German Old ID recognizer result
 */
@property (nonatomic, strong, readonly) MBGermanyOldIdRecognizerResult *result;

/**
 * Defines if owner's place of birth should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

@end

NS_ASSUME_NONNULL_END
