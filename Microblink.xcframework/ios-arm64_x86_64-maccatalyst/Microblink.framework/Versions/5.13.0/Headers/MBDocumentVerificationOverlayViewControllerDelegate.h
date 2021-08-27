//
//  MBDocumentVerificationOverlayViewControllerDelegate.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 28/05/2018.
//

#import <Foundation/Foundation.h>
#import "MBDocumentVerificationOverlayViewController.h"
#import "MBRecognizerRunnerViewController.h"
#import "MBRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for obtaining scanning results
 */
@protocol MBDocumentVerificationOverlayViewControllerDelegate <NSObject>
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
 *  @param documentVerificationOverlayViewController documentVerificationOverlayViewController Scanning view controller responsible for scanning
 *  @param state                  state of scanning
 *
 *
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)documentVerificationOverlayViewControllerDidFinishScanning:(nonnull MBDocumentVerificationOverlayViewController *)documentVerificationOverlayViewController state:(MBRecognizerResultState)state;

/**
 * Scanning library was closed, usually by the user pressing close button and cancelling the scan
 *
 *  @param documentVerificationOverlayViewController Scanning view controller responsible for scanning
 */
- (void)documentVerificationOverlayViewControllerDidTapClose:(nonnull MBDocumentVerificationOverlayViewController *)documentVerificationOverlayViewController;

@optional
/**
 * Called when scanning library finished scanning first side of the document
 *
 *  @param documentVerificationOverlayViewController documentVerificationOverlayViewController Scanning view controller responsible for scanning
 */
- (void)documentVerificationOverlayViewControllerDidFinishScanningFirstSide:(nonnull MBDocumentVerificationOverlayViewController *)documentVerificationOverlayViewController;

/**
 * Scanning library did output high resolution image
 *
 *  @param documentVerificationOverlayViewController Scanning view controller responsible for scanning
 *  @param highResImage High resolution image of finished scan
 *
 *
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)documentVerificationOverlayViewControllerDidCaptureHighResolutionImage:(nonnull MBDocumentVerificationOverlayViewController *)documentVerificationOverlayViewController highResImage:(MBImage *)highResImage state:(MBDocumentVerificationHighResImageState)state;

@end

NS_ASSUME_NONNULL_END
