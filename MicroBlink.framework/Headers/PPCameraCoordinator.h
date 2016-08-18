//
//  PPCameraCoordinator.h
//  BlinkIdFramework
//
//  Created by Domagoj Boros on 19/02/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "PPCoordinator.h"
#import "PPMicroBlinkDefines.h"
#import "PPScanningViewController.h"
#import "PPScanningDelegate.h"
#import "PPCameraSettings.h"

@class PPCameraManager;

NS_ASSUME_NONNULL_BEGIN

/**
 * PPCameraCoordinator coordinates hardware control with the recognition algorithms,
 * and provides facotry method for creating ViewController with UI for the camera.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCameraCoordinator : PPCoordinator

/**
 * Delegate for PPCoordinator related events
 */
@property (nonatomic, weak) id<PPCoordinatorDelegate> delegate;

/** Object which will take care of the camera */
@property (nonatomic) PPCameraManager *cameraManager;

/**----------------------*/
/** @name Initialization */
/**----------------------*/
#pragma mark - Initialization

/**
 * Initializes the object in proper state.
 *
 * Sets the settings for scanning, camera control, licensing, UI and Metadata handling.
 *
 *  @param settings settings used for initialization
 *  @param delegate delegate for coordinator related events
 *
 *  @return initialized coordinator object
 */
- (instancetype)initWithSettings:(PPSettings *)settings delegate:(nullable id<PPCoordinatorDelegate>)delegate NS_DESIGNATED_INITIALIZER;

/**
 * Initializes the object in proper state.
 *
 * Sets the settings for scanning, camera control, licensing, UI and Metadata handling.
 *
 *  @param settings settings used for initialization
 *
 *  @return initialized coordinator object
 */
- (instancetype)initWithSettings:(PPSettings *)settings;

/**
 * This method returns true when scanning is unsupported on a specific device.
 * Error object contains description of the reason for that.
 *
 *  @param type The camera type you want to check for.
 *  @param error If scanning is not supported, when method this method returns, this parameter contains an NSError object that describes the problem. If you are not interested in possible errors, pass in NULL.
 *
 *  @return YES if scanning is not supported, NO otherwise.
 */
+ (BOOL)isScanningUnsupportedForCameraType:(PPCameraType)type error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NOTHROW;

/**
 * Creates the scanning view controller with this coordinator and given delegate object.
 * Calling this method is equivalend of calling [PPViewControllerFactory cameraViewControllerWithDelegate:self error:nil]
 *
 * @see PPViewControllerFactory
 */
- (UIViewController<PPScanningViewController> *)cameraViewControllerWithDelegate:(id<PPScanningDelegate>)delegate;

/**
 * Creates the scanning view controller with this coordinator and given delegate object and given custom overlay.
 * Calling this method is equivalend of calling [PPViewControllerFactory cameraViewControllerWithDelegate:self overlayViewController:overlayViewController error:nil]
 *
 * @see PPViewControllerFactory
 */
- (UIViewController<PPScanningViewController> *)cameraViewControllerWithDelegate:(id<PPScanningDelegate>)delegate overlayViewController:(PPOverlayViewController *)overlayViewController;

/** 
 * Sets the scanning region. CGRect is given in coordinate system of the camera
 */
- (void)setScanningRegion:(CGRect)scanningRegion;

/** 
 * Tell coordinator that scanning has started
 */
- (void)start;

/** 
 * Tell coordinator scanning has stopped
 */
- (void)stop;

/**
 * Pauses recognition of input images. Any image inputted will not be processed
 */
- (void)pauseRecognition;

/**
 * Resumes recognition if it was paused.
 */
- (void)resumeRecognition;

/**
 * Returns state of recognition.
 */
- (BOOL)isRecognitionPaused;

@end

NS_ASSUME_NONNULL_END
