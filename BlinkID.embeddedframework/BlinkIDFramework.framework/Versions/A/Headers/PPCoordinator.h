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
#import "PPApiHeader.h"

@protocol PPCameraViewDelegate;
@protocol PPPhotoPayDelegate;
@class PPCameraManager;
@class PPRecognitionResult;
@class PPOverlayViewController;
@class PPAccelerometerManager;

/**
 * This object is the mastermind of the recognition process.
 * It coordinates hardware control with the recognition algorithms.
 * Also, while it provides default implementation of UIViewController which is used,
 * it allows you to create your own UIViewController implementation and use
 * this object's methods for ensuring everything works
 */
@interface PPCoordinator : NSObject

/** delegate object which will be control camera view related events */
@property (nonatomic, weak) id<PPCameraViewDelegate> viewDelegate;

/** delegate object for notifying the caller on recognition results */
@property (nonatomic, weak) id<PPPhotoPayDelegate> photopayDelegate;

/** flag indicating active recognizer */
@property (nonatomic, assign, getter = isActive, readonly) BOOL active;

/** Object which will take care of the camera */
@property (nonatomic, strong) PPCameraManager *cameraManager;

/** We need an acceleration manager object because we're interested in events regarding device movement */
@property (nonatomic, strong) PPAccelerometerManager *accelerometerManager;

/** Plist file with help content */
@property (nonatomic, strong) NSString* helpContentFile;

/** Orientation of toast messages */
@property (nonatomic, assign) UIInterfaceOrientationMask hudOrientation;

/** Current orientation of overlay */
@property (nonatomic, assign) UIInterfaceOrientation overlayOrientation;

/** 
 * Initializes the object in proper state
 * Should always be used for initialization
 */
- (id)initWithSettings:(NSMutableDictionary*)inSettings;

/**
 * Method creates a camera view controller which is responsible for displaying the 
 * camera input on the phone screen. Also, camera view controller delivers PhotoPay
 * results via PPPhotoPayDelegate object.
 *
 * Creating camera view controller with this method creates default overlay view
 */
- (UIViewController<PPScanningViewController>*)cameraViewControllerWithDelegate:(id<PPPhotoPayDelegate>)delegate;

/**
 * Method creates a camera view controller which is responsible for displaying the
 * camera input on the phone screen. Also, camera view controller delivers PhotoPay
 * results via PPPhotoPayDelegate object
 *
 * With this method you can specify custom overlay view to be used on the camera display.
 * The only requirement for the overlay view is that it's a subclass of PPOverlayViewController
 */
- (UIViewController<PPScanningViewController>*)cameraViewControllerWithDelegate:(id<PPPhotoPayDelegate>)delegate
                                                          overlayViewController:(PPOverlayViewController*)overlayViewController;

/** 
 * Starts the camera session, flash, torch and frame saving process. Also makes the camera do the autofocus
 * IMPORTANT: must be called only after initWithSettings...
 */
- (BOOL)start;

/** Camera did load preview */
- (void)cameraDidLoad;

/** 
 * Pauses the frame saving process and stops the camera session.
 * If called before stop, it's a noop.
 */
- (BOOL)stop;

/** Torch mode is set to on or off */
- (BOOL)setTorchEnabled:(BOOL)isEnabled;

/** Returns the size of video frames in pixels (eg 640, 480) */
- (CGSize)getApertureSize;

/** Plays sound which marks scan success */
- (void)playScanSuccesSound;

/** Starts the frame retreiving process */
- (void)startReceivingFrames;

/** Stops the frame retreiving process */
- (void)stopReceivingFrames;

/** Retrieve the current state of frame processing */
- (BOOL)isReceivingFrames;

/** Updates the aperture size to current camera view size */
- (void)updateApertureSize;

/** Sets the scanning region. CGRect is given in coordinate system of the camera */
- (void)setScanningRegion:(CGRect)scanningRegion;

/** Clears the paused recognition flag that stops recognition after a result is produced */
- (void)resumeRecognition;

/** Resets the internal state */
- (void)resetRecognizerState;

/**
 * This method is called when PhotoPay is unsupported on a specific device.
 * Error object contains description of the reason for that.
 */
+ (BOOL)isPhotoPayUnsupported:(NSError **)error;

/**
 * This method returns the string that contains the library build version
 * information.
 */
+ (NSString*)getBuildVersionString;

@end