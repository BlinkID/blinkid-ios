//
//  PPCoordinator.h
//  PhotoPaySdk
//
//  Created by Jurica Cerovec on 11/19/11.
//  Copyright (c) 2011 Racuni.hr. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "PPScanningViewController.h"

@protocol PPCoordinatorDelegate;
@protocol PPScanDelegate;
@class PPSettings;
@class PPCameraManager;
@class PPRecognitionResult;
@class PPOverlayViewController;
@class PPAccelerometerManager;

/**
 * This object is the mastermind of the recognition process.
 *
 * PPCoordinator coordinates hardware control with the recognition algorithms, 
 * and provides facotry method for creating ViewController with UI for the camera.
 */
@interface PPCoordinator : NSObject

/** Scanning settings pending to be used with applySettings method */
@property (nonatomic, strong) PPSettings *currentSettings;

/** delegate object for notifying the caller on recognition results */
@property (nonatomic, weak) id<PPScanDelegate> scanDelegate;

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
 *
 *  @return initialized coordinator object
 */
- (instancetype)initWithSettings:(PPSettings *)settings;

/**-------------------------------*/
/** @name Settings recofiguration */
/**-------------------------------*/
#pragma mark - Settings recofiguration

/**
 * Method which is used to apply PPSettings object given by currentSettings property
 *
 * Usual use case is to update settings in the fly, to perform some complex scanning functionality
 * where a reconfiguration of the recognizers is needed.
 */
- (void)applySettings;

/**------------------------------------------*/
/** @name Creating Scanning view controllers */
/**------------------------------------------*/
#pragma mark - Creating Scanning view controllers

/**
 * Method creates a scanning view controller which is responsible for displaying the
 * camera input on the phone screen. Also, scanning view controller delivers PhotoPay
 * results via PPScanDelegate object.
 *
 * Creating scanning view controller with this method creates default overlay view.
 *
 *  @param delegate PPScanDelegate object which will get notified about scanning events
 *
 *  @return Scanning view controller fully initialized for presenting on screen.
 */
- (UIViewController<PPScanningViewController> *)cameraViewControllerWithDelegate:(id<PPScanDelegate>)delegate;

/**
 * Method creates a camera view controller which is responsible for displaying the
 * camera input on the phone screen. Also, camera view controller delivers PhotoPay
 * results via PPPhotoPayDelegate object
 *
 * With this method you can specify custom overlay view to be used on the camera display.
 * The only requirement for the overlay view is that it's a subclass of PPOverlayViewController
 *
 *  @param delegate                 PPScanDelegate object which will get notified about scanning events
 *  @param overlayViewController    View Controller which is presented on top of scanning view controller as a child.
 *
 *  @return Scanning view controller fully initialized for presenting on screen.
 */
- (UIViewController<PPScanningViewController> *)cameraViewControllerWithDelegate:(id<PPScanDelegate>)delegate
                                                          overlayViewController:(PPOverlayViewController *)overlayViewController;

/**-----------------------------------*/
/** @name Direct processing of images */
/**-----------------------------------*/
#pragma mark - Direct processing of images

/**
 * Processes an UIImage object using current settings.
 * Results are passed to a fiven delegate object.
 *
 *  @param image            image for processing
 *  @param scanningRegion   region of the image used for scanning, where the whole image is specified with CGRectMake(0.0, 0.0, 1.0, 1.0)
 *  @param delegate         delegate which is notified on processing events
 */
- (void)processImage:(UIImage *)image
      scanningRegion:(CGRect)scanningRegion
            delegate:(id<PPScanDelegate>)delegate;


/**-------------------------------------------*/
/** @name Obtaining information about the SDK */
/**-------------------------------------------*/
#pragma mark - Obtaining information about the SDK

/**
 * This method returns true when scanning is unsupported on a specific device.
 * Error object contains description of the reason for that.
 *
 *  @param error If scanning is not supported, when method this method returns, this parameter contains an NSError object that describes the problem. If you are not interested in possible errors, pass in NULL.
 *
 *  @return YES if scanning is not supported, NO otherwise.
 */
+ (BOOL)isScanningUnsupported:(NSError **)error;

/**
 * Returns the string that contains the library build version
 *
 *  @return string that contains the library build version
 */
+ (NSString *)getBuildVersionString;

@end