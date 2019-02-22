//
//  MBMalaysiaMyKadBackRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 12/06/2018.
//

#import "MBRecognizer.h"
#import "MBMalaysiaMyKadBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Kad Back Recognizer.
 *
 * MyKadBack recognizer is used for scanning back side of MyKad.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMalaysiaMyKadBackRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning MyKad back side
 */
@property (nonatomic, strong, readonly) MBMalaysiaMyKadBackRecognizerResult *result;

/**
 * Defines if old NRIC should be extracted from back side of the MyKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractOldNric;

@end

NS_ASSUME_NONNULL_END
