//
//  MBSwitzerlandIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSwitzerlandIdBackRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Swiss ID Back Recognizer.
 *
 * Swiss ID Back recognizer is used for scanning back side of Swiss ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwitzerlandIdBackRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Swiss ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBSwitzerlandIdBackRecognizerResult *result;

/**
 * Defines if authority of Swiss ID should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAuthority;

/**
 * Defines if date of issue of Swiss ID should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if date of expiry of Swiss ID should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if place of origin of Swiss ID holder should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfOrigin;

/**
 * Defines if height of Swiss ID holder should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractHeight;

/**
 * Defines if sex of Swiss ID folder should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
