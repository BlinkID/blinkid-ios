//
//  PPScanDelegate.h
//  PhotoPayFramework
//
//  Created by Jura on 09/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPOverlayViewController.h"
#import "PPScanningViewController.h"
#import "PPMetadata.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for obtaining scanning results
 */
@protocol PPScanDelegate <NSObject>
@required

/**
 * Scanning library requested authorization for Camera access from the user, but the user declined it.
 * This case means scanning cannot be performed, because accessing camera images is now allowed.
 *
 * In this callback you have the chance to handle this case and present some kind of a message to the user on top
 * of scanningViewController.
 *
 *  @param scanningViewController Scanning view controller which was responsible for scanning
 */
- (void)scanningViewControllerUnauthorizedCamera:(UIViewController<PPScanningViewController>*)scanningViewController;

/**
 * Scanning library found an error. The error object is returned and contains
 * description of the error, in a specified language. Do your error handling here.
 *
 * Currently, only one situation can result with this callback being called:
 * - Using camera session resulted with AVCaptureSessionRuntimeErrorNotification notification
 *
 * The best way to handle this is to Log the error (GA, Crashlytics, Flurry) and let the user continue
 * using the app.
 *
 *  @param scanningViewController Scanning view controller which was responsible for scanning
 *  @param error                  Error object describing the error
 */
- (void)scanningViewController:(UIViewController<PPScanningViewController>*)scanningViewController
                  didFindError:(NSError*)error;

/**
 * Scanning library was closed, usually by the user pressing close button and cancelling the scan
 *
 *  @param scanningViewController Scanning view controller responsible for scanning
 */
- (void)scanningViewControllerDidClose:(UIViewController<PPScanningViewController>*)scanningViewController;

/**
 * Scanning library did output scanning results (array of PPRecognizerResult objects). Do your next steps here.
 *
 * Depending on how you want to treat the result, you might want to
 * dismiss the scanningViewController here.
 *
 * This method is the default way for getting access to results of scanning.
 *
 * Note:
 * - there may be 0, 1, or more than one scanning results.
 * - each scanning result belongs to a common PPRecognizerResult type
 * - handle different types differently
 *
 *  @param scanningViewController scanningViewController Scanning view controller responsible for scanning
 *  @param results                Array of results returned by the scanner
 *
 * @see PPRecognizerResult
 */
- (void)scanningViewController:(nullable UIViewController<PPScanningViewController>*)scanningViewController
              didOutputResults:(NSArray<PPRecognizerResult*>*)results;

@optional

/**
 * Scanning library found an invalid license key.
 *
 * This can happen in two situations:
 *   1) Completely invalid license key was used (either it's not set, or it's garbage, or it expired)
 *   2) License key is in fact valid, but the features you're using aren't enabled by the license key
 *
 * If you don't implement this method, the SDK will present an UIAlertView with error and call your
 *
 * This is intended for you to easily spot the issue as soon as possible.
 *
 * If you implement this method, you have a chance to handle the situation. However, scanning won't work 
 * without a valid license key!
 *
 *  @param scanningViewController Scanning view controller which was responsible for scanning
 *  @param error                  Error object describing the error
 */
- (void)scanningViewController:(UIViewController<PPScanningViewController>*)scanningViewController
    invalidLicenseKeyWithError:(NSError*)error;

/**
 * Called when Scanning library will display help. This can happen when the user presses
 * help button on scanning UI, or on first run of the application
 *
 *  @param scanningViewController scanningViewController Scanning view controller responsible for scanning
 */
- (void)scanningViewControllerWillPresentHelp:(UIViewController<PPScanningViewController>*)scanningViewController;

/**
 * Called when Scanning library requires the display of more info view
 *
 *  @param scanningViewController scanningViewController Scanning view controller responsible for scanning
 */
- (void)scanningViewControllerDidRequestMoreInfo:(UIViewController<PPScanningViewController>*)scanningViewController;

/**
 * Called when coordinator obtaines metadata information
 *
 *  @param scanningViewController scanningViewController Scanning view controller responsible for scanning
 *  @param metadata               obtained metadata
 */
- (void)scanningViewController:(nullable UIViewController<PPScanningViewController> *)scanningViewController
             didOutputMetadata:(PPMetadata *)metadata;

@end

NS_ASSUME_NONNULL_END