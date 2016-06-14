//
//  PPCoordinatorDelegate.h
//  BlinkOcrFramework
//
//  Created by Jura on 17/04/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PPMetadata;
@class PPCoordinator;
@class PPOcrLayout;
@class PPRecognizerResult;
@class PPDetectorResult;

/**
 * Delegate for coordinator methods.
 * Unlike PPScanningDelegate, this protocol is used for direct processing API (processing images without camera).
 * If you are processing images with our camera management, then this protocol can be ignored in most use cases.
 */
@protocol PPCoordinatorDelegate <NSObject>

@optional

/** 
 *Called when the recognition of a current image is initiated 
 */
- (void)coordinatorDidStartDetection:(PPCoordinator *)coordinator;

/**
 * Called when coordinator obtaines metadata
 */
- (void)coordinator:(PPCoordinator *)coordinator didOutputMetadata:(PPMetadata*)metadata;

/**
 * Called when the recognition manager finds the element on the image and returns
 the coordinates of found element
 */
- (void)coordinator:(PPCoordinator *)coordinator didFinishDetectionWithResult:(PPDetectorResult *)result;

/**
 * Called when the recognition of a current image starts
 */
- (void)coordinatorDidStartRecognition:(PPCoordinator *)coordinator;

/**
 * Called when the recognition one recognizer finishes
 */
- (void)coordinatorDidFinishRecognition:(PPCoordinator *)coordinator;

/**
 * Called when the recognition outputs all possible results from a single image
 */
- (void)coordinator:(PPCoordinator *)coordinator didOutputResults:(NSArray<PPRecognizerResult *> *)results;

/**
 * Called when the recognition times out and returns the best result found
 */
- (void)coordinator:(PPCoordinator *)coordinator didPublishProgress:(CGFloat)progress;

/**
 * Called when the recognition obtains the result of the ocr process
 */
- (void)coordinator:(PPCoordinator *)coordinator didObtainOcrResult:(PPOcrLayout*)ocrResult withResultName:(NSString*)resultName;

/**
 * Called when the we have an error in the recognition process and have to quit camera view
 */
- (void)coordinator:(PPCoordinator *)coordinator didFindError:(NSError*)error;

/**
 * Called when the we have an error with the license key
 */
- (void)coordinator:(PPCoordinator *)coordinator invalidLicenseKeyWithError:(NSError*)error;

/**
 * TODO Ugly way of passing UI-related transformation information that should not be here
 */
- (CGAffineTransform)coordinatorAffineTransformToScreen:(PPCoordinator *)coordinator;

@end