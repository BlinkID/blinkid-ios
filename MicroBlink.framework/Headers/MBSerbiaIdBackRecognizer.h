//
//  MBSerbiaIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSerbiaIdBackRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Serbian ID Back Recognizer.
 *
 * Serbian ID Back recognizer is used for scanning back side of Serbian ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBSerbiaIdBackRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Serbian ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBSerbiaIdBackRecognizerResult *result;



@end

NS_ASSUME_NONNULL_END
