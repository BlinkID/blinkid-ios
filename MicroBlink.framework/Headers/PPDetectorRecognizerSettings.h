//
//  PPDetectorRecogizerSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 06/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

#import "PPDetectorSettings.h"

#import "PPDocumentDetectorSettings.h"
#import "PPMrtdDetectorSettings.h"
#import "PPMultiDetectorSettings.h"
#import "PPFaceDetectorSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer class for detector settings (Esentially a weapper around PPDetectorSettings).
 * Detector recognizer is used to detect various documents on the image.
 *
 * If multiple detectors are needed, please check PPMultiDetectorSettings.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPDetectorRecognizerSettings : PPRecognizerSettings

/**
 * Initializes the recognizer with desired detector settings.
 */
- (instancetype)initWithDetectorSettings:(PPDetectorSettings *)detectorSettings NS_DESIGNATED_INITIALIZER;

/**
 * Please use designated initializer.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
