//
//  SettingsKeys.h
//  PhotoPayFramework
//
//  Created by Jurica Cerovec on 6/5/12.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#ifndef PhotoPayFramework_SettingsKeys_h
#define PhotoPayFramework_SettingsKeys_h

#import "PPCameraSettings.h"
#import "PPLicenseSettings.h"
#import "PPUiSettings.h"
#import "PPScanSettings.h"
#import "PPMetadataSettings.h"

#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class with all possible customizable settings in the scanning process
 *
 * Contains:
 *  - Camera Settings: for customizing camera controls
 *  - License Settings:
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPSettings : NSObject <NSCopying>

/**
 * Settings related to Camera control
 */
@property (nonatomic, strong) PPCameraSettings* cameraSettings;

/**
 * Settings for license key (without it, scanning might not work)
 */
@property (nonatomic, strong) PPLicenseSettings* licenseSettings;

/**
 * Settings for camera UIg
 */
@property (nonatomic, strong) PPUiSettings* uiSettings;

/**
 * Settings to control scanning.
 *
 * Here you need to define what type of scanning will be performed on video frames.
 * You can do that by adding different PPRecognizerSettings object.
 *
 * Each PPRecognizerSettings object initializes one Recognizer object which is then responsible for performing
 * recognition on each video frame
 *
 * @see PPRecognizerSettings
 */
@property (nonatomic, strong) PPScanSettings* scanSettings;

/**
 * Settings for obtaining metadata in the scanning process.
 */
@property (nonatomic, strong) PPMetadataSettings* metadataSettings;

@end

NS_ASSUME_NONNULL_END

#endif
