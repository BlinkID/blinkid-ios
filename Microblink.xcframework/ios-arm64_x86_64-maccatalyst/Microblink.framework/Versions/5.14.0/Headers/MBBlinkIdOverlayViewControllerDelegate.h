//
//  MBBlinkIdOverlayViewControllerDelegate.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 03/06/2019.
//

#import <Foundation/Foundation.h>
#import "MBBlinkIdOverlayViewController.h"
#import "MBRecognizerRunnerViewController.h"
#import "MBRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for obtaining scanning results
 */
@protocol MBBlinkIdOverlayViewControllerDelegate <NSObject>
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
 *  @param blinkIdOverlayViewController blinkIdOverlayViewController Scanning view controller responsible for scanning
 *  @param state                  state of scanning
 *
 *
 */
- (void)blinkIdOverlayViewControllerDidFinishScanning:(nonnull MBBlinkIdOverlayViewController *)blinkIdOverlayViewController state:(MBRecognizerResultState)state;

/**
 * Scanning library was closed, usually by the user pressing close button and cancelling the scan
 *
 *  @param blinkIdOverlayViewController Scanning view controller responsible for scanning
 */
- (void)blinkIdOverlayViewControllerDidTapClose:(nonnull MBBlinkIdOverlayViewController *)blinkIdOverlayViewController;

@optional
/**
 * Called when scanning library finished scanning first side of the document
 *
 *  @param blinkIdOverlayViewController blinkIdOverlayViewController Scanning view controller responsible for scanning
 */
- (void)blinkIdOverlayViewControllerDidFinishScanningFirstSide:(nonnull MBBlinkIdOverlayViewController *)blinkIdOverlayViewController;

@end

NS_ASSUME_NONNULL_END
