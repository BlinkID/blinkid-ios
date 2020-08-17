//
//  MBOverlayContainerViewController.h
//  PhotoMathFramework
//
//  Created by Marko Mihovilić on 30/03/16.
//  Copyright © 2016 Microblink Ltd. All rights reserved.
//

#import "MBRecognizerRunnerViewController.h"

@class MBOverlayViewController;

/**
 Overlay View Controller also needs to notify CameraViewController on certain events.
 Those are events specified by PPOverlayViewControllerDelegate protocol.
 */
@protocol MBOverlayContainerViewController <MBRecognizerRunnerViewController>

@required

/**
 Notification sent when Overlay View Controller wants to close camera, for example,
 by pressing Cancel button.
 */
- (void)overlayViewControllerWillCloseCamera:(MBOverlayViewController *)overlayViewController;

/**
 Overlay View Controller should ask it's delegete if it's necessary to display Torch (Light) button.
 Torch button is not necessary if the device doesn't support torch mode (e.g. iPad devices).
 */
- (BOOL)overlayViewControllerShouldDisplayTorch:(MBOverlayViewController *)overlayViewController;

/**
 Overlay View Controller must notify it's delegete to set the torch mode to On or Off

 Returns YES if torch mode was set successfully, otherwise NO.
 */
- (BOOL)overlayViewController:(MBOverlayViewController *)overlayViewController willSetTorch:(BOOL)isTorchOn;

/**
 * If help mechanism is implemented using PPScanDelegate's scanningViewControllerWillPresentHelp method,
 * Overlay view controller should ask it's container whether it's appropriate do display help button;
 *
 *  @return YES if help button should be displayed.
 */
- (BOOL)shouldDisplayHelpButton;

/**
 Check if status bar is hidden or showed
 */
- (BOOL)isStatusBarPresented;

/**
 Overlay View Controller can ask it's delegete about the status of Torch
 */
- (BOOL)isTorchOn;

/**
 * Overlay View Controller can ask it's owner whether camera was authorized
 */
- (BOOL)isCameraAuthorized;

@end
