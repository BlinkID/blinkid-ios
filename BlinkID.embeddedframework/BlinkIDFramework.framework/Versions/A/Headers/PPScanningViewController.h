//
//  PPScanningViewController.h
//  BarcodeFramework
//
//  Created by Jurica Cerovec on 14/11/13.
//  Copyright (c) 2013 PhotoPay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Protocol for View controllers which present camera and provide scanning features
 */
@protocol PPScanningViewController <NSObject>

/** Pause scanning instantaneously without dismissing the camera view */
- (void)pauseScanning;

/** Resumes scanning instantaneously */
- (void)resumeScanning;

/** Retrieve the current state of scanning */
- (BOOL)isScanningPaused;

/** Sets the scanning region */
- (void)setScanningRegion:(CGRect)region;

@end
