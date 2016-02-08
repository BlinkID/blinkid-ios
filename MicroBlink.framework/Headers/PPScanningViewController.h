//
//  PPScanningViewController.h
//  BarcodeFramework
//
//  Created by Jurica Cerovec on 14/11/13.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for View controllers which present camera and provide scanning features
 */
@protocol PPScanningViewController <NSObject>

/**
 * Scanning region
 * Defines a portion of the screen in which the scanning will be performed.
 * Given as a CGRect with unit coordinating system:
 *
 * @example CGRectMake(0.2f, 0.5f, 0.4f, 0.3f) defines a portion of the screen which starts at 
 *   20% from the left border
 *   50% from the top
 *   covers 40% of screen width
 *   and 30% of screen heeight
 */
@property (nonatomic, assign) CGRect scanningRegion;

/**
 * ScanningViewController's shouldAutorotate will return this value.
 *
 * Default: NO.
 *
 * Set it to YES if you want scanning view controller to autorotate.
 */
@property (nonatomic, assign) BOOL autorotate;

/**
 * ScanningViewController's supportedInterfaceOrientations will return this value.
 *
 * Default: UIInterfaceOrientationMaskPortrait.
 */
@property (nonatomic, assign) NSUInteger supportedOrientations;

/**
 * Pause scanning without dismissing the camera view.
 *
 * If there is camera frame being processed at a time, the processing will finish, but the results of processing 
 * will not be returned.
 *
 * @warning must be called from Main thread to ensure thread synchronization
 */
- (void)pauseScanning;

/**
 * Retrieve the current state of scanning.
 *
 *  @return YES if scanning is paused. NO if it's in progress
 *
 *  @warning must be called from Main thread to ensure thread synchronization
 */
- (BOOL)isScanningPaused;

/**
 * Resumes scanning. Optionally, internal state of recognizers can be reset in the process.
 *
 * If you continue scanning the same object, for example, the same slip, or the same MRTD document, to get result
 * with higher confidence, then pass NO to reset State.
 *
 * If you move to scan another object, for example, another barcode, or another payment slip, then pass YES to reset State.
 *
 * Internal state is used to use the fact that the same object exists on multiple consecutive frames, and using internal
 * state provides better scanning results.
 *
 *  @param resetState YES if state should be reset.
 *
 *  @warning must be called from Main thread to ensure thread synchronization
 */
- (void)resumeScanningAndResetState:(BOOL)resetState;

/**
 * Resumes camera session. This method is automatically called in viewWillAppear when ScanningViewController enters screen.
 */
- (void)resumeCamera;

/**
 * Pauses camera session. This method is automatically called in viewDidDissapear when ScanningViewController exits screen.
 */
- (void)pauseCamera;

@end

NS_ASSUME_NONNULL_END
