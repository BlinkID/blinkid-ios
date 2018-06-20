//
//  MBJordanIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBJordanIdBackRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Jordan ID Back Recognizer.
 *
 * Jordan ID Back recognizer is used for scanning back side of Jordan ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBJordanIdBackRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Jordan ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBJordanIdBackRecognizerResult *result;



@end

NS_ASSUME_NONNULL_END
