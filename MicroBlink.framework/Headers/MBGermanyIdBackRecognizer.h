//
//  MBGermanyIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBGermanyIdBackRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring German ID Back Recognizer.
 *
 * German ID Back recognizer is used for scanning back side of German ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyIdBackRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * German ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBGermanyIdBackRecognizerResult *result;

/**
 * If eye color should be extracted, set this to YES
 *
 * Default: YES
 */
@property (nonatomic) BOOL extractEyeColour;

/**
 * If height should be extracted, set this to YES
 *
 * Default: YES
 */
@property (nonatomic) BOOL extractHeight;

/**
 * If date of issue should be extracted, set this to YES
 *
 * Default: YES
 */
@property (nonatomic) BOOL extractDateOfIssue;

/**
 * If authority should be extracted, set this to YES
 *
 * Default: YES
 */
@property (nonatomic) BOOL extractAuthority;

/**
 * Defines if owner's address should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

@end

NS_ASSUME_NONNULL_END
