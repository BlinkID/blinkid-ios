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
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSettings : NSObject <NSCopying>

/**
 * Initializes the PPSettings with all default values.
 *
 * @see individual properties for defaults.
 *
 * @return Initialized PPSettings object
 */
- (instancetype)init;

/**
 * Initializes the PPSettings with a given resource bundle.
 *
 * @see individual properties for defaults. Resource bundle will be set to the bundle passed as parametere here.
 *
 * @return Initialized PPSettings object
 */
- (instancetype)initWithResourceBundle:(NSBundle *)bundle NS_DESIGNATED_INITIALIZER;

/**
 * Settings related to Camera control
 */
@property (nonatomic) PPCameraSettings *cameraSettings;

/**
 * Settings for license key (without it, scanning might not work)
 */
@property (nonatomic) PPLicenseSettings *licenseSettings;

/**
 * Settings for camera UI
 */
@property (nonatomic) PPUiSettings *uiSettings;

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
@property (nonatomic) PPScanSettings *scanSettings;

/**
 * Settings for obtaining metadata in the scanning process.
 */
@property (nonatomic) PPMetadataSettings *metadataSettings;

/**
 * Bundle in which the resources for the scanning process should be found. Usually, by default, this
 * is equal to Microblink.bundle located in Main app bundle.
 *
 * i.e, this is by default initialized to:
 *   [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"MicroBlink" ofType:@"bundle"];
 *
 * This is a readonly property. If you want to set it, please use initWithResourceBundle: initialized
 */
@property (nonatomic, readonly) NSBundle *resourcesBundle;

@end

NS_ASSUME_NONNULL_END

#endif
