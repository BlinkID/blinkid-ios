//
//  MBPolandIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBPolandIdBackRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Polish ID Back Recognizer.
 *
 * Polish ID Back recognizer is used for scanning back side of Polish ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBPolandIdBackRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Polish ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBPolandIdBackRecognizerResult *result;



@end

NS_ASSUME_NONNULL_END
