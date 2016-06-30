//
//  PPCoordinator.h
//  PhotoPaySdk
//
//  Created by Jurica Cerovec on 11/19/11.
//  Copyright (c) 2011 Racuni.hr. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import "PPMicroBlinkDefines.h"
#import "PPScanningViewController.h"
#import "PPCameraSettings.h"
#import "PPCoordinatorDelegate.h"
#import "PPImage.h"
#import "PPSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This object is the mastermind of the recognition process.
 *
 * PPCoordinator coordinates hardware control with the recognition algorithms, 
 * and provides facotry method for creating ViewController with UI for the camera.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCoordinator : NSObject

/** delegate object which will be control camera view related events */
@property (nonatomic, weak) id<PPCoordinatorDelegate> delegate;

/** Scanning settings pending to be used with applySettings method */
@property (nonatomic) PPSettings *currentSettings;

/**----------------------*/
/** @name Initialization */
/**----------------------*/
#pragma mark - Initialization

- (instancetype)init NS_UNAVAILABLE;

/**
 * Initializes the object in proper state.
 *
 * Sets the settings for scanning, camera control, licensing, UI and Metadata handling.
 *
 *  @param settings settings used for initialization
 *
 *  @return initialized coordinator object
 */
- (instancetype)initWithSettings:(PPSettings *)settings delegate:(id<PPCoordinatorDelegate>)delegate NS_DESIGNATED_INITIALIZER;

/**-------------------------------*/
/** @name Settings recofiguration */
/**-------------------------------*/
#pragma mark - Settings recofiguration

- (void)resetState;

/**
 * Method which is used to apply PPSettings object given by currentSettings property
 *
 * Usual use case is to update settings on the fly, to perform some complex scanning functionality
 * where a reconfiguration of the recognizers is needed.
 */
- (void)applySettings;

/**-----------------------------------*/
/** @name Direct processing of images */
/**-----------------------------------*/
#pragma mark - Direct processing of images

/**
 * Processes a PPImage object synchronously using current settings.
 * Since this method is synchronous, calling it from a main thread will switch the call to alternate thread internally and output a warning.
 *
 * Results are passed a delegate object given upon a creation of PPCoordinator.
 *
 *  @param image            image for processing
 */
- (void)processImage:(PPImage *)image;

/**-------------------------------------------*/
/** @name Obtaining information about the SDK */
/**-------------------------------------------*/
#pragma mark - Obtaining information about the SDK

/**
 * Returns the string that contains the library build version
 *
 *  @return string that contains the library build version
 */
+ (NSString *)buildVersionString;

@end

NS_ASSUME_NONNULL_END