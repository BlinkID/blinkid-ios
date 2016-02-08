//
//  PPDetectorSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 06/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

struct DetectorSettingsImpl;
typedef struct DetectorSettingsImpl DetectorSettingsImpl;

/**
 * MicroBlink scanning libraries run detector objects to find objects on image
 *
 * Each detector is configured with PPDetectorSettings object
 *
 * This class is common superclass for each of the Detector settings,
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPDetectorSettings : NSObject <NSCopying>

@property (nonatomic, readonly, assign) DetectorSettingsImpl* settings;

/**
 * YES if detector should display detected location on device screen
 *
 * Default: YES
 */
@property (nonatomic) BOOL displayDetectedLocation;

/**
 * Designated initializer. Internal.
 *
 *  @param settings implementation object
 *
 *  @return instantiated object
 */
- (instancetype)initWithSettings:(DetectorSettingsImpl*)settings NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END