//
//  MBCyprusIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by juraskrlec on 21/08/2018.
//

#import "MBRecognizer.h"
#import "MBCyprusIdBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer which can scan back side of Cyprus national ID cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCyprusIdBackRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Cyprus Id Back Recognizer
 */
@property (nonatomic, strong, readonly) MBCyprusIdBackRecognizerResult *result;

/**
 * Defines if sex of Cyprus ID card owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
