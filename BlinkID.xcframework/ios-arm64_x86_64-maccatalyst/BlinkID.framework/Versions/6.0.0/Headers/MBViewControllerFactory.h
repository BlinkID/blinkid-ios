//
//  MBViewControllerFactory.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 15/12/2017.
//

#import "MBMicroblinkDefines.h"
#import "MBRecognizerRunnerViewController.h"
#import "MBOverlayViewController.h"
#import "MBBlinkIdMultiSideRecognizerResult.h"

typedef void (^MBScanningResultBlock)(MBBlinkIdMultiSideRecognizerResult * _Nonnull result);
typedef void(^MBScanningOverlayCloseButtonTappedBlock)(void);

/**
 * Factory class containing static methods for creating camera view controllers.
 * Camera view controllers created this way will be managed internally by the SDK, and input frames will be processed.
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBViewControllerFactory : NSObject

/**------------------------------------------*/
/** @name Creating Scanning view controllers */
/**------------------------------------------*/
#pragma mark - Creating Scanning view controllers

/**
 * Method creates a camera view controller which is responsible for displaying the
 * camera input on the phone screen.
 *
 * With this method you can specify custom overlay view to be used on the camera display.
 * The only requirement for the overlay view is that it's a subclass of MBOverlayViewController
 *
 *  @param overlayViewController    View Controller which is presented on top of scanning view controller as a child.
 *
 *  @return Scanning view controller fully initialized for presenting on screen.
 */
+ (nullable UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewControllerWithOverlayViewController:(nonnull MBOverlayViewController *)overlayViewController NS_SWIFT_NAME(recognizerRunnerViewController(withOverlayViewController:));

/**
 * The method creates a camera view controller, which is responsible for displaying the camera input on the phone screen.
 * With this method, you can specify blocks for handling when scanning is finished and when scanning is canceled via the cancel button.
 * When scanning is finished with a result, scanning is automatically paused.
 *
 *  @param result    Closure which will be called when the scanning view controller is finished with scanning. Receives one parameter: BlinkIdMultiSideRecognizerResult
 *  @param closeButtonTapped    Closure which will be called when cancel button is tapped
 *
 *  @return Scanning view controller fully initialized for presenting on screen.
 */
+ (nullable UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewControllerWithResult:(nonnull MBScanningResultBlock)result closeButtonTapped:(nonnull MBScanningOverlayCloseButtonTappedBlock) closeButtonTapped NS_SWIFT_NAME(recognizerRunnerViewController(withResult:closeButtonTapped:));

@end
