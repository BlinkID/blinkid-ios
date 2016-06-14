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

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring Detector recognizer
 *
 * Detector recognizer is used to detect various documents on the image
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPDetectorRecognizerSettings : PPRecognizerSettings

- (instancetype)initWithDetectorSettings:(PPDetectorSettings *)detectorSettings NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
