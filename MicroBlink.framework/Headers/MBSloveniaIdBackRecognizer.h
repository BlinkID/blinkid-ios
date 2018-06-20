//
//  MBSloveniaIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSloveniaIdBackRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Slovenian ID Back Recognizer.
 *
 * Slovenian ID Back recognizer is used for scanning back side of Slovenian ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBSloveniaIdBackRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Slovenian ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBSloveniaIdBackRecognizerResult *result;

/**
 *  Defines if issuing authority of Slovenian ID should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractAuthority;

/**
 *  Defines if date of issue of Slovenian ID should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractDateOfIssue;

@end

NS_ASSUME_NONNULL_END
