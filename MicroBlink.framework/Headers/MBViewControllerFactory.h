//
//  MBViewControllerFactory.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 15/12/2017.
//

#import "MBMicroblinkDefines.h"
#import "MBRecognizerRunnerViewController.h"
#import "MBOverlayViewController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Factory class containing static methods for creating camera view controllers.
 * Camera view controllers created this way will be managed internally by the SDK, and input frames will be processed.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
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
+ (UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewControllerWithOverlayViewController:(MBOverlayViewController *)overlayViewController NS_SWIFT_NAME(recognizerRunnerViewController(withOverlayViewController:));

@end

NS_ASSUME_NONNULL_END
