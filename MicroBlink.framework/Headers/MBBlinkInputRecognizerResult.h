//
//  MBBlinkInputRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 02/03/2018.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBRecognizerResult.h"
#import "MBMicroblinkInitialization.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A recognizer result for BlinkInput API and general OCR recognition
 */
MB_CLASS_AVAILABLE_IOS(8.0)

@interface MBBlinkInputRecognizerResult : MBRecognizerResult <NSCopying>

MB_INIT_UNAVAILABLE

@end

NS_ASSUME_NONNULL_END
