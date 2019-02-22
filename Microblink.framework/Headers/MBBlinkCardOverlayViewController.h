//
//  MBBlinkCardOverlayViewController.h
//  MicroBlinkDev
//
//  Created by Jura on 31/01/2019.
//

#import "MBBaseOverlayViewController.h"
#import "MBBlinkCardOverlaySettings.h"

@protocol MBBlinkCardOverlayViewControllerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing UI information for BlinkCard
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBlinkCardOverlayViewController : MBBaseOverlayViewController

/**
 * Common settings
 */
@property (nonatomic, strong, readonly) MBBlinkCardOverlaySettings *settings;

/**
 * Delegate
 */
@property (nonatomic, weak, readonly) id<MBBlinkCardOverlayViewControllerDelegate> delegate;

/**
 * Designated intializer.
 *
 *  @param settings MBBlinkCardOverlaySettings object
 *
 *  @param recognizerCollection MBRecognizerCollection object
 *
 *  @return initialized overlayViewController
 */
- (instancetype)initWithSettings:(MBBlinkCardOverlaySettings *)settings
            recognizerCollection:(MBRecognizerCollection *)recognizerCollection
                        delegate:(nonnull id<MBBlinkCardOverlayViewControllerDelegate>)delegate;


@end

/**
 * Protocol for obtaining scanning results
 */
@protocol MBBlinkCardOverlayViewControllerDelegate <NSObject>

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
 *  @param blinkCardOverlayViewController documentOverlayViewController Scanning view controller responsible for scanning
 *  @param state                  state of scanning
 *
 *
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)blinkCardOverlayViewControllerDidFinishScanning:(nonnull MBBlinkCardOverlayViewController *)blinkCardOverlayViewController state:(MBRecognizerResultState)state;

/**
 * Scanning library was closed, usually by the user pressing close button and cancelling the scan
 *
 *  @param blinkCardOverlayViewController Scanning view controller responsible for scanning
 */
- (void)blinkCardOverlayViewControllerDidTapClose:(nonnull MBBlinkCardOverlayViewController *)blinkCardOverlayViewController;

@optional
/**
 * Called when scanning library finished scanning first side of the document
 *
 *  @param blinkCardOverlayViewController blinkCardOverlayViewController Scanning view controller responsible for scanning
 */
- (void)blinkCardOverlayViewControllerDidFinishScanningFirstSide:(nonnull MBBlinkCardOverlayViewController *)blinkCardOverlayViewController;

@end

NS_ASSUME_NONNULL_END
