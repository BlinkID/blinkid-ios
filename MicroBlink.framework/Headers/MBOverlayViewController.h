//
//  PPOverlayViewController.h
//  PhotoPayFramework
//
//  Created by Jurica Cerovec on 5/28/13.
//  Copyright (c) 2013 Microblink Ltd. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

#import "MBRecognizerRunnerViewController.h"
#import "MBMicroblinkDefines.h"
#import "MBOverlayContainerViewController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Overlay View Controller is an abstract class for all overlay views placed on top View Controller.

 It's responsibility is to provide meaningful and useful interface for the user to interact with.

 Typical actions which need to be allowed to the user are:

 - intuitive and meaniningful way to guide the user through scanning process. This is usually done by presenting a
    "viewfinder" in which the user need to place the scanned object
 - a way to cancel the scanining, typically with a "cancel" or "back" button
 - a way to power on and off the light (i.e. "torch") button
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBOverlayViewController : UIViewController

MB_INIT_UNAVAILABLE

/**
 Overlay View's delegate object. Responsible for sending messages to PhotoPay's
 Camera View Controller
 */
@property (nonatomic, weak) UIViewController<MBOverlayContainerViewController> *recognizerRunnerViewController;

/**
 * Label which is displayed on screen when camera is paused, but still exists on the screen.
 *
 * This happens in split view and slide over modes in iOS 9.
 *
 * The view is centered on screen and displayed with a 0.4s fade in animation. It's dismissed with 0.4s
 * fade out animation.
 *
 * Default:
 *     UILabel *cameraPausedLabel = [[UILabel alloc] init];
 *     cameraPausedLabel.text = @"Camera paused";
 *     cameraPausedLabel.font = [UIFont systemFontOfSize:24.f];
 *     cameraPausedLabel.textColor = [UIColor whiteColor];
 *     cameraPausedLabel.layer.shadowRadius = 5.0f;
 *     cameraPausedLabel.layer.shadowOffset = CGSizeMake(1.0, 1.0);
 *     cameraPausedLabel.layer.shadowOpacity = 1.0f;
 *     cameraPausedLabel.layer.shadowColor = [UIColor blackColor].CGColor;
 *     [cameraPausedLabel sizeToFit];
 */
@property (nonatomic, strong, nullable) UIView *cameraPausedView;

@end

NS_ASSUME_NONNULL_END
