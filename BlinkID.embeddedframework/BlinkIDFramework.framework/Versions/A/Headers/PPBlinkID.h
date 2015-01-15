//
//  PPIdScan.h
//  PhotoPayFramework
//
//  Created by Jura on 14/10/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#ifndef PhotoPayFramework_PPIdScan_h
#define PhotoPayFramework_PPIdScan_h

#import "PPApp.h"
#import "PPCoordinator.h"
#import "PPBaseResult.h"
#import "PPUSDLResult.h"
#import "PPIdCardResult.h"
#import "PPSettings.h"
#import "PPDetectionStatus.h"
#import "PPOverlayViewController.h"
#import "PPScanningViewController.h"

/**
 * Protocol for retrieving results from PhotoPay
 */
@protocol PPPhotoPayDelegate <NSObject>
@required

/**
 * Scanning library requested authorization for Camera access from the user, but the user declined it. 
 * This case means scanning cannot be performed, because accessing camera images is now allowed.
 *
 * In this callback you have the chance to handle this case and present some kind of a message to the user on top 
 * of cameraViewController.
 */
- (void)cameraViewControllerUnauthorizedCamera:(UIViewController<PPScanningViewController>*)cameraViewController;

/**
 * Scanning library returned with error. The error object is returned and contains
 * description of the error, in a specified language. Do your error handling here.
 *
 * This is where the PhotoPay's UIViewController should be dismissed
 * if it's presented modally.
 */
- (void)cameraViewController:(UIViewController<PPScanningViewController>*)cameraViewController
          didFinishWithError:(NSError*)error;

/**
 * Scanning library did output scanning results Do your next steps here.
 *
 * Depending on how you want to treat the result, you might want to
 * dismiss the PhotoPay library's UIViewController here.
 *
 * This method is the default way for getting access to results of scanning.
 *
 * Note:
 * - there may be more 0, 1, or more than one scanning results.
 * - each scanning result belongs to a common PPBaseResult type. Check it's property resultType to get the actual type
 * - handle different types differently
 *
 * @see PPBaseResult
 * @see PPRecognitionResult
 */
- (void)cameraViewController:(UIViewController<PPScanningViewController>*)cameraViewController
            didOutputResults:(NSArray*)results;

@optional

/**
 * Called when Scanning library wants to display help screens. This can happen when the user press
 * help button on PhotoPay UI, or on first run of the application
 */
- (void)cameraViewControllerShouldPresentHelp:(UIViewController<PPScanningViewController>*)cameraViewController;

/**
 * Called when PhotoPay requires the display of more info view
 */
- (void)cameraViewControllerDidRequestMoreInfo:(UIViewController<PPScanningViewController>*)cameraViewController;


/**
 Called when coordinator obtaines intermediate images

 Intended for private Scanning library use.
 */
- (void)cameraViewController:(UIViewController<PPScanningViewController>*)cameraViewController
               obtainedImage:(UIImage *)image
                    withName:(NSString *)name
                        type:(NSString *)type;

/**
 Called when coordinator obtaines intermediate texts

 Intended for private Scanning library use.
 */
- (void)cameraViewController:(UIViewController<PPScanningViewController>*)cameraViewController
                obtainedText:(NSString*)text
                    withName:(NSString*)name
                        type:(NSString*)type;

@end

#endif
