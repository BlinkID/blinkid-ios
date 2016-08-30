//
//  ViewControllerFactory.h
//  BlinkIdFramework
//
//  Created by Domagoj Boros on 24/02/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPMicroBlinkDefines.h"

@class PPOverlayViewController;
@class PPCameraCoordinator;

@protocol PPScanningDelegate;
@protocol PPScanningViewController;

NS_ASSUME_NONNULL_BEGIN

/**
 * Factory class containing static methods for creating camera view controllers.
 * Camera view controllers created this way will be managed internally by the SDK, and input frames will be processed.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPViewControllerFactory : NSObject

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
 *  @param delegate     PPScanDelegate object which will get notified about scanning events
 *  @param coordinator  PPCameraCoordinator object used for camera & recognizer coordination
 *
 *  @return Scanning view controller fully initialized for presenting on screen.
 */
+ (UIViewController<PPScanningViewController> *)cameraViewControllerWithDelegate:(id<PPScanningDelegate>)delegate
                                                                     coordinator:(PPCameraCoordinator *)coordinator
                                                                           error:(NSError **)error;

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
 *  @param coordinator              PPCameraCoordinator object used for camera & recognizer coordination
 *
 *  @return Scanning view controller fully initialized for presenting on screen.
 */
+ (UIViewController<PPScanningViewController> *)cameraViewControllerWithDelegate:(nullable id<PPScanningDelegate>)delegate
                                                           overlayViewController:(PPOverlayViewController *)overlayViewController
                                                                     coordinator:(PPCameraCoordinator *)coordinator
                                                                           error:(NSError **)error;
@end

NS_ASSUME_NONNULL_END