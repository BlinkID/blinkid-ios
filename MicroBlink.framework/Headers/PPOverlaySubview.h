//
//  PPOverlaySubview.h
//  BarcodeFramework
//
//  Created by Jura on 06/06/14.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPMicroBlinkDefines.h"
#import "PPDetectorResult.h"

#import "PPLivenessAction.h"
#import "PPLivenessError.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PPOverlaySubviewDelegate;

@class PPOcrLayout;
@class PPMetadata;
@class PPOverlayViewController;
@class PPRecognizerResult;

/**
 * Common interface for all OverlaySubviews
 */
@protocol PPOverlaySubview <NSObject>

/** Delegate which is notified on Overlay events */
@property (nonatomic, weak, nullable) id<PPOverlaySubviewDelegate> delegate;

/** The overlay view controller containing this overlay subview (if any) */
@property (nonatomic, weak) PPOverlayViewController *overlay;

@optional

/**
 Overlay view appears and the scanning resumes. This happens when the camera view
 is opened, or when the app enters foreground with camera view displayed.
 */
- (void)overlayDidResumeScanning;

/**
 Overlay disappears and the scanning pauses. This happens when the camera view
 is closed, or when the app enters background with camera view displayed.
 */
- (void)overlayDidStopScanning;

/**
 Overlay started the new recognition cycle. Since recognition is done on video frames,
 there might be multiple recognition cycles before the scanning completes
 */
- (void)overlayDidStartRecognition;

/**
 Overlay finished recognition of the first side of the document. After this, recognition of the back side immediately
 Follows. Overlay is responsible for changing the appearance.
 */
- (void)overlayDidFinishRecognitionFirstSide:(PPRecognizerResult *)result;

/**
 Overlay ended the recognition cycle with a certain result.
 The scanning result cannot be considered as valid, sometimes here are received objects which
 contain only partial scanning information.

 Use this method only if you need UI update on this event (although this is unnecessary in many cases).

 If you're interested in valid data, use cameraViewController:didOutputResults: method
 */
- (void)overlayDidFinishRecognition;

/**
 * Overlay started new detection cycle.  Since detection is done on video frames,
 there might be multiple detection cycles before the scanning completes.
 */
- (void)overlayDidStartDetection;

/**
 Overlay reports the progress of the current OCR/barcode scanning recognition cycle.
 Note: this is not the actual progress from the moment camera appears.
 This might not be meaningful for the user in all cases.
 */
- (void)overlayDidPublishProgress:(CGFloat)progress;

/**
 * Overlay reports the status of the object detection. Scanning status contain information
 * about whether the scan was successful, whether the user holds the device too far from
 * the object, whether the angles was too high, or the object isn't seen on the camera in
 * it's entirety. If the object was found, the corner points of the object are returned.
 */
- (void)overlayDidFinishDetectionWithResult:(PPDetectorResult *)result;

/**
 * Overlay reports obtained ocr layout
 *
 * Besides the ocr layout itself, we get the ID of the layout so we can
 * distinguish consecutive layouts of the same area on the image
 */
- (void)overlayDidObtainOcrLayout:(PPOcrLayout *)ocrLayout withIdentifier:(NSString *)identifier;

/**
 * Overlay ended with recognition metadata.
 * This is always called *before* method did output results
 *
 *  @param metadata             returned metadata
 */
- (void)overlayDidOutputMetadata:(PPMetadata *)metadata;

/**
 * Overlay ended the recognition cycle with a certain Scanning result.
 * The scanning result can be considered as valid, meaning it can be presented to the user for inspection.
 * Use this method only if you need UI update on this event (although this is unnecessary in many cases).
 * The actual result will be passed to your PPPhotoPayDelegate object.
 */
- (void)overlayDidOutputResults:(nullable NSArray<PPRecognizerResult *> *)results;

/**
 * Overlay was tapped and focusing at the given point is initiated
 */
- (void)willFocusAtPoint:(CGPoint)point;

/**
 * Called when overlay received request for a particular liveness verification action. Check
 * PPLivenessAction enum for a list of all available actions.
 *
 *  @param action One particular liveness action
 */
- (void)overlayDidRequestLivenessAction:(PPLivenessAction)action;

/**
 * Called when overlay received error status about the liveness verification action.
 *
 *  @param error One particular liveness aciton error
 */
- (void)overlayDidFindLivenessActionError:(PPLivenessError)error;

/**
 Method called when a rotation to a given
 interface orientation is about to happen
 */
- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;

/**
 Method called immediately after the rotation from a given
 interface orientation happened
 */
- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation;

/**
 Method called inside an animation block. Any changes you make
 to your UIView's inside this method will be animated
 */
- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;

@end

/**
 Base class for all overlay subviews
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPOverlaySubview : UIView <PPOverlaySubview>

@end

/**
 * Protocol which all objects interested in receiving information about overlay subviews need to implement
 */
@protocol PPOverlaySubviewDelegate <NSObject>

/** Delegate method called when animation starts */
- (void)overlaySubviewAnimationDidStart:(PPOverlaySubview *)overlaySubview;

/** Delegate method called when animation finishes */
- (void)overlaySubviewAnimationDidFinish:(PPOverlaySubview *)overlaySubview;

@end

NS_ASSUME_NONNULL_END
