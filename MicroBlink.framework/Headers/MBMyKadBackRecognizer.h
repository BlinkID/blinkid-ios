//
//  MBMyKadBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 12/06/2018.
//

#import "MBRecognizer.h"
#import "MBMyKadBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Kad Back Recognizer.
 *
 * MyKadBack recognizer is used for scanning back side of MyKad.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBMyKadBackRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBFullDocumentImageDpi, MBSignatureImage, MBSignatureImageDpi, MBGlareDetection>

MB_INIT

/**
 * Result of scanning MyKad back side
 */
@property (nonatomic, strong, readonly) MBMyKadBackRecognizerResult *result;

@end

NS_ASSUME_NONNULL_END
