//
//  MBUnitedArabEmiratesIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 28/05/2018.
//

#import "MBRecognizer.h"
#import "MBUnitedArabEmiratesIdBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring United Arab Emirates ID Back Recognizer.
 *
 * United Arab Emirates ID Back recognizer is used for scanning back side of United Arab Emirates ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBUnitedArabEmiratesIdBackRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection>

MB_INIT

/**
 * United Arab Emirates ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBUnitedArabEmiratesIdBackRecognizerResult *result;

@end

NS_ASSUME_NONNULL_END
