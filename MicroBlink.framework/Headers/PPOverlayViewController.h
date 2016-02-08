//
//  PPOverlayViewController.h
//  PhotoPayFramework
//
//  Created by Jurica Cerovec on 5/28/13.
//  Copyright (c) 2013 MicroBlink Ltd. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import "PPScanningViewController.h"
#import "PPDetectionStatus.h"
#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PPOverlayContainerViewController;
@class PPOcrLayout;
@class PPMetadata;
@class PPRecognizerResult;


/**
 Overlay View Controller is an abstract class for all overlay views placed on top PhotoPay's Camera View Controller.

 It's responsibility is to provide meaningful and useful interface for the user to interact with.

 Typical actions which need to be allowed to the user are:

 - intuitive and meaniningful way to guide the user through scanning process. This is usually done by presenting a 
    "viewfinder" in which the user need to place the scanned object
 - a way to cancel the scanining, typically with a "cancel" or "back" button
 - a way to power on and off the light (i.e. "torch") button

 PhotoPay always provides it's own default implementation of the Overlay View Controller for every specific use. 
 Your implementation should closely mimic the default implementation as it's the result of thorough testing with 
 end users. Also, it closely matches the underlying scanning technology.

 For example, the scanning technology usually gives results very fast after the user places the device's camera in the 
 expected way above the scanned object. This means a progress bar for the scan is not particularly useful to the user. 
 The majority of time the user spends on positioning the device's camera correctly. That's just an example which 
 demonstrates careful decision making behind default camera overlay view.

 PhotoPay demo project in your development package contain `PPCameraOverlayViewController` class, an example of 
 custom overlay view implementation.

 # Initialization

 To use your custom overlay with PhotoPay's camera view, you must subclass PPOverlayViewController and 
 specify it when initializing CameraViewController:

    PPCameraOverlayViewController *overlayViewController =
        [[PPCameraOverlayViewController alloc] initWithNibName:@"PPCameraOverlayViewController" bundle:nil];

    // Create camera view controller
    UIViewController *cameraViewController =
        [coordinator cameraViewControllerWithDelegate:self overlayViewController:overlayViewController];

 Note: if you create camera view controller without specifying overlay view, the default overlay implementation will be used:

    // Create camera view controller
    UIViewController *cameraViewController =
        [coordinator cameraViewControllerWithDelegate:self];

 As with any view controller, you are responsible for specifying UI elements and handling their actions.
 Besides that, there are some requirements for interaction with Camera View Controller.

 # Interaction with CameraViewController

 CameraViewController is a Container view controller to the PPOverlayViewController instances. 
 For more about Container View Controllers, read official Apple [View Controller Programming Guide].

 Also, each instance of PPOverlayViewController and it's subclasses has access to the Container View Controller.

    // Overlay View's delegate object. Responsible for sending messages
    // to PhotoPay's Camera View Controller
    @property (nonatomic, assign) id<PPOverlayContainerViewController> containerViewController;

 # Handling orientation changes

 Camera view controller is always presented in Portrait mode, but nevertheless, your overlay view be presented in the 
 current device orientation. There are two ways to handle orientation changes.

 The first, built in way is a simple way to achieve autorotation. Your Overlay View Controller only needs to implement 
 standard UIViewController methods which specify which orientations are supported. For example, to support only landscape 
 orientations, you need to add the following methods to your Overlay View Controller implementation.

    - (NSUInteger)supportedInterfaceOrientations {
        return UIInterfaceOrientationMaskLandscape;
    }

    - (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation {
        return UIInterfaceOrientationLandscapeRight;
    }

    - (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
        return (interfaceOrientation == UIInterfaceOrientationLandscapeLeft || interfaceOrientation == UIInterfaceOrientationLandscapeRight);
    }

 Your Overlay View Controller will automatically rotate to support all orientations returned by `supportedInterfaceOrientations`
 method. You are responsible for standard iOS techniques (auto-layout or autoresizing masks) to adjust the UI to new 
 device orientation.

 You can manually disable autorotation by initializing `PPCoordinator` object with the following setting:

    [coordinatorSettings setValue:@(NO) forKey:kPPOverlayShouldAutorotate];


 # Steps for providing custom Camera Overlay View

 1. Create a subclass of `PPOverlayViewController`. You can use XIB for user interface, or create UI from code.

 2. See if there are any events received from `CameraViewController` which you need to handle for your UI hierarchy

 3. Implement your view hierarchy.

    If you have a Cancel button in your view, don't forget to call `overlayViewControllerWillCloseCamera:`
    method on overlay's delegate object when cancel is pressed.

    If you have Torch button, dont forget to check if Torch should be displayed by using
    `overlayViewControllerShouldDisplayTorch:` method, and to report new torch state with
    `overlayViewController:willSetTorch:` method.

 4. Handle orientation changes, either by implementing standard UIViewController autorotation metods, 
    or by custom rotation management on rotation events.
 
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPOverlayViewController : UIViewController

/** 
 Overlay View's delegate object. Responsible for sending messages to PhotoPay's 
 Camera View Controller
 */
@property (nonatomic, weak) UIViewController <PPOverlayContainerViewController> *containerViewController;

/**
 Scanning region in which the scaning is performed.
 Image is cropped to this region.
 
 Should be provided in the following coordinate system. 
 - Upper left point has coordinates (0.0f, 0.0f) and corresponds to upper left corner of the overlay view
 - Lower right corner has coordinates (1.0f, 1.0f) and corresponds to lower right corner of the overlay view
 
 CGRect provided here specifies the origin (upper left point) of the scanning region, and the size of the
 region in hereby described coordinating system.
 */
@property (nonatomic, assign) CGRect scanningRegion;

/**
 * Scanning library requested authorization for Camera access from the user, but the user declined it.
 * This case means scanning cannot be performed, because accessing camera images is now allowed.
 *
 * In this callback you have the chance to handle this case and present some kind of a message to the user on top
 * of cameraViewController.
 */
- (void)cameraViewControllerUnauthorizedCamera:(UIViewController<PPScanningViewController>*)cameraViewController;

/**
 Camera view appears and the scanning resumes. This happens when the camera view
 is opened, or when the app enters foreground with camera view displayed.
 */
- (void)cameraViewControllerDidResumeScanning:(UIViewController<PPScanningViewController>*)cameraViewController;

/** 
 Camera view disappears and the scanning pauses. This happens when the camera view 
 is closed, or when the app enters background with camera view displayed.
 */
- (void)cameraViewControllerDidStopScanning:(UIViewController<PPScanningViewController>*)cameraViewController;

/** 
 Camera view reports the progress of the current OCR/barcode scanning recognition cycle. 
 Note: this is not the actual progress from the moment camera appears. 
 This might not be meaningful for the user in all cases. 
 */
- (void)cameraViewController:(UIViewController<PPScanningViewController>*)cameraViewController
          didPublishProgress:(float)progress;

/**
 Camera view reports the status of the object detection. Scanning status contain information 
 about whether the scan was successful, whether the user holds the device too far from 
 the object, whether the angles was too high, or the object isn't seen on the camera in 
 it's entirety. If the object was found, the corner points of the object are returned.
 
 Coordinate system of points returned corresponds to overlay view (meaning, [0,0] is the 
 origin of the overlay view, [width, height] is the size of overlay view)
 */
- (void)cameraViewController:(UIViewController<PPScanningViewController>*)cameraViewController
             didFindLocation:(NSArray*)cornerPoints
                  withStatus:(PPDetectionStatus)status;

/**
 Camera view reports obtained OCR result
 
 Besides the OCR result itself, we get the ID of the result so we can
 distinguish consecutive results of the same area on the image
 */
- (void)cameraViewController:(UIViewController<PPScanningViewController>*)cameraViewController
          didObtainOcrResult:(PPOcrLayout*)ocrResult
              withResultName:(NSString*)resultName;

/**
 Camera view controller started the new recognition cycle. Since recognition is done
 on video frames, there might be multiple recognition cycles before the scanning completes
 */
- (void)cameraViewControllerDidStartRecognition:(UIViewController<PPScanningViewController>*)cameraViewController;

/** 
 Camera view controller ended the recognition cycle with a certain Scanning result.
 The scanning result cannot be considered as valid, sometimes here are received objects which
 contain only partial scanning information.

 Use this method only if you need UI update on this event (although this is unnecessary in many cases).
 
 If you're interested in valid data, use cameraViewController:didOutputResult: method
 */
- (void)cameraViewController:(UIViewController<PPScanningViewController>*)cameraViewController
didFinishRecognitionWithResult:(id)result;

/**
 Camera view controller ended the recognition cycle with a certain Scanning result.
 The scanning result can be considered as valid, meaning it can be presented to the user for inspection.
 Use this method only if you need UI update on this event (although this is unnecessary in many cases).
 The actual result will be passed to your PPPhotoPayDelegate object.
 */
- (void)cameraViewController:(UIViewController<PPScanningViewController>*)cameraViewController
            didOutputResults:(NSArray<PPRecognizerResult*>*)results;

- (void)cameraViewController:(UIViewController<PPScanningViewController>*)cameraViewController
           didOutputMetadata:(PPMetadata*)metadata;

/**
 Called when a manual focus (user tapped the screen for example) will be performed at specified point.
 */
- (void)cameraViewController:(UIViewController<PPScanningViewController>*)cameraViewController
          willFocusAtPoint:(CGPoint)point;

/**
 UIViewController's method called when a rotation to a given 
 interface orientation is about to happen
 */
- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
                                duration:(NSTimeInterval)duration;

/**
 UIViewController's method called immediately after the rotation from a given
 interface orientation happened
 */
- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation;

/**
 UIViewController's method called inside an animation block. Any changes you make
 to your UIView's inside this method will be animated
 */
- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
                                         duration:(NSTimeInterval)duration;

@end


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

/**
 Overlay View Controller can get Video Capture Preview Layer object from it's delegete.
 */
- (AVCaptureVideoPreviewLayer*)getPreviewLayer;

@end

NS_ASSUME_NONNULL_END