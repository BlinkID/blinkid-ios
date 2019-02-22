//
//  MBDocumentOverlayViewControllerDelegate.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 25/05/2018.
//

#import <Foundation/Foundation.h>
#import "MBDocumentOverlayViewController.h"
#import "MBRecognizerRunnerViewController.h"
#import "MBRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for obtaining scanning results
 */
@protocol MBDocumentOverlayViewControllerDelegate <NSObject>
@required
/**
 * Scanning library did output scanning results
 *
 * Depending on how you want to treat the result, you might want to
 * dismiss the scanningViewController here.
 *
 * This method is the default way for getting access to results of scanning.
 *
 * Note:
 * - there may be 0, 1, or more than one scanning results.
 * - each scanning result belongs to a common MBRecognizerResult type
 * - handle different types differently
 *
 *  @param documentOverlayViewController documentOverlayViewController Scanning view controller responsible for scanning
 *  @param state                  state of scanning
 *
 *
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)documentOverlayViewControllerDidFinishScanning:(nonnull MBDocumentOverlayViewController *)documentOverlayViewController state:(MBRecognizerResultState)state;

/**
 * Scanning library was closed, usually by the user pressing close button and cancelling the scan
 *
 *  @param documentOverlayViewController Scanning view controller responsible for scanning
 */
- (void)documentOverlayViewControllerDidTapClose:(nonnull MBDocumentOverlayViewController *)documentOverlayViewController;

@optional
/**
 * Scanning library did output high resolution image
 *
 *  @param documentOverlayViewController Scanning view controller responsible for scanning
 *  @param highResImage High resolution image of finished scan
 *
 *
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)documentOverlayViewControllerDidCaptureHighResolutionImage:(nonnull MBDocumentOverlayViewController *)documentOverlayViewController highResImage:(MBImage *)highResImage;

@end

NS_ASSUME_NONNULL_END
