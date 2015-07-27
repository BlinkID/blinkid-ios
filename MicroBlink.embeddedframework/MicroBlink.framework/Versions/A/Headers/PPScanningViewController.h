//
//  PPScanningViewController.h
//  BarcodeFramework
//
//  Created by Jurica Cerovec on 14/11/13.
//  Copyright (c) 2013 PhotoPay. All rights reserved.
//

#import <Foundation/Foundation.h>

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
 * Pause scanning without dismissing the camera view
 */
- (void)pauseScanning;

/**
 * Retrieve the current state of scanning
 *
 *  @return YES if scanning is paused. NO if it's in progress
 */
- (BOOL)isScanningPaused;

/**
 * Resumes scanning. Optionally, internal state of recognizers can be reset in the process.
 * Internal state should NOT be reset if you continue to scan the same object to obtain the result with higher confidence.
 * If you start scanning some new object, state reset should be performed.
 *
 *  @param resetState YES if state should be reset.
 */
- (void)resumeScanningAndResetState:(BOOL)resetState;

@end
