//
//  MBSlovakiaIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSlovakiaIdBackRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Slovak ID Back Recognizer.
 *
 * Slovak ID Back recognizer is used for scanning back side of Slovak ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBSlovakiaIdBackRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Slovak ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBSlovakiaIdBackRecognizerResult *result;

/**
 * Defines if owner's surname at birth should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurnameAtBirth;

/**
 * Defines if owner's place of birth should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if owner's special remarks should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSpecialRemarks;

@end

NS_ASSUME_NONNULL_END
