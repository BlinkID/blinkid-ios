//
//  MBBarcodeOverlayViewControllerDelegate.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 17/01/2018.
//


#import <Foundation/Foundation.h>
#import "MBBarcodeOverlayViewController.h"
#import "MBRecognizerRunnerViewController.h"
#import "MBRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for obtaining scanning results
 */
@protocol MBBarcodeOverlayViewControllerDelegate <NSObject>
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
 *  @param barcodeOverlayViewController barcodeOverlayViewController Scanning view controller responsible for scanning
 *  @param state                  state of scanning
 *
 *
 */
- (void)barcodeOverlayViewControllerDidFinishScanning:(nonnull MBBarcodeOverlayViewController *)barcodeOverlayViewController state:(MBRecognizerResultState)state;

/**
 * Scanning library was closed, usually by the user pressing close button and cancelling the scan
 *
 *  @param barcodeOverlayViewController Scanning view controller responsible for scanning
 */
- (void)barcodeOverlayViewControllerDidTapClose:(nonnull MBBarcodeOverlayViewController *)barcodeOverlayViewController;

@end

NS_ASSUME_NONNULL_END
