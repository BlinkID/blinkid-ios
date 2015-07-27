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
 * Currently, only two situations result with this callback being called:
 * - 1. License key for using scanning library is invalid
 * - 2. Using camera session resulted with AVCaptureSessionRuntimeErrorNotification notification
 *
 * Probably the best option at the moment is to Log the error (GA, Crashlytics, Flurry) and let the user continue
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
- (void)scanningViewController:(UIViewController<PPScanningViewController>*)scanningViewController
              didOutputResults:(NSArray*)results;

@optional

/**
 * Called when Scanning library wants to display help screens. This can happen when the user press
 * help button on scanning UI, or on first run of the application
 *
 *  @param scanningViewController scanningViewController Scanning view controller responsible for scanning
 */
- (void)scanningViewControllerShouldPresentHelp:(UIViewController<PPScanningViewController>*)scanningViewController;

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
- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
             didOutputMetadata:(PPMetadata *)metadata;

@end
