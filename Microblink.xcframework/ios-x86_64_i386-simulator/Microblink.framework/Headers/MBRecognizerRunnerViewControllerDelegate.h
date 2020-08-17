//
//  MBRecognizerRunnerViewControllerDelegate.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 18/12/2017.
//

#import <Foundation/Foundation.h>

@protocol MBRecognizerRunnerViewController;

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for MBRecognizerRunnerViewController actions
 */
@protocol MBRecognizerRunnerViewControllerDelegate <NSObject>
@required
/**
 * Scanning library requested authorization for Camera access from the user, but the user declined it.
 * This case means scanning cannot be performed, because accessing camera images is now allowed.
 *
 * In this callback you have the chance to handle this case and present some kind of a message to the user on top
 * of scanningViewController.
 *
 *  @param recognizerRunnerViewController Scanning view controller which was responsible for scanning
 */
- (void)recognizerRunnerViewControllerUnauthorizedCamera:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController;

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
 *  @param recognizerRunnerViewController Scanning view controller which was responsible for scanning
 *  @param error                  Error object describing the error
 */
- (void)recognizerRunnerViewController:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController didFindError:(NSError *)error;

/**
 * Scanning library was closed, usually by the user pressing close button and cancelling the scan
 *
 *  @param recognizerRunnerViewController Scanning view controller responsible for scanning
 */
- (void)recognizerRunnerViewControllerDidClose:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController;

/**
 * Called when Scanning library will display help. This can happen when the user presses
 * help button on scanning UI, or on first run of the application
 *
 *  @param recognizerRunnerViewController recognizerRunnerViewController Recognizer runner view controller responsible for scanning
 */
- (void)recognizerRunnerViewControllerWillPresentHelp:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController;

/**
 * Called when Scanning library is resuming scanning.
 *
 *  @param recognizerRunnerViewController recognizerRunnerViewController Recognizer runner view controller responsible for scanning
 */
- (void)recognizerRunnerViewControllerDidResumeScanning:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController;

/**
 * Called when Scanning library is stopped scanning.
 *
 *  @param recognizerRunnerViewController recognizerRunnerViewController Recognizer runner view controller responsible for scanning
 */
- (void)recognizerRunnerViewControllerDidStopScanning:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController;

@end

NS_ASSUME_NONNULL_END
