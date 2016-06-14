//
//  PPOverlayContainerViewController.h
//  PhotoMathFramework
//
//  Created by Marko Mihovilić on 30/03/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPScanningViewController.h"

@class PPOverlayViewController;

/**
 Overlay View Controller also needs to notify CameraViewController on certain events.
 Those are events specified by PPOverlayViewControllerDelegate protocol.
 */
@protocol PPOverlayContainerViewController <PPScanningViewController>

@required

/**
 Notification sent when Overlay View Controller wants to close camera, for example,
 by pressing Cancel button.
 */
- (void)overlayViewControllerWillCloseCamera:(PPOverlayViewController*)overlayViewController;

/**
 Overlay View Controller should ask it's delegete if it's necessary to display Torch (Light) button.
 Torch button is not necessary if the device doesn't support torch mode (e.g. iPad devices).
 */
- (BOOL)overlayViewControllerShouldDisplayTorch:(PPOverlayViewController*)overlayViewController;

/**
 Overlay View Controller must notify it's delegete to set the torch mode to On or Off

 Returns YES if torch mode was set successfully, otherwise NO.
 */
- (BOOL)overlayViewController:(PPOverlayViewController*)overlayViewController
                 willSetTorch:(BOOL)isTorchOn;

/**
 * If help mechanism is implemented using PPScanDelegate's scanningViewControllerWillPresentHelp method,
 * Overlay view controller should ask it's container whether it's appropriate do display help button;
 *
 *  @return YES if help button should be displayed.
 */
- (BOOL)shouldDisplayHelpButton;

/**
 Overlay View Controller should know if it's presented modally or on navigation view controller.

 Use this method to ask if it's necessary to display Cancel button. (when on navigation view controller, button back is presented by default)

 This method replaced old method overlayViewControllerShouldDisplayCancel.
 */
- (BOOL)isPresentedModally;

/**
 Overlay View Controller can ask it's delegete about the status of Torch
 */
- (BOOL)isTorchOn;

@end
