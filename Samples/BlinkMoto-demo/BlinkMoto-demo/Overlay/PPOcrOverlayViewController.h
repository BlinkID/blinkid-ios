//
//  PPOcrOverlayViewController.h
//  BlinkMoto-demo
//
//  Created by Jura Skrlec on 02/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import <MicroBlink/MicroBlink.h>
#import "PPOcrFinderView.h"

typedef NS_ENUM(NSInteger, OcrRecognizerType) {
    VIN,
    LicensePlate
};

@protocol PPOcrOverlayViewControllerDelegate;

@interface PPOcrOverlayViewController : PPBaseOverlayViewController

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithOcrRecognizerType:(OcrRecognizerType)ocrRecognizerType;

// needs to be weak to avoid a reference cycle
@property (nonatomic, weak) PPCoordinator *coordinator;

/**
 * Delegate which is notified with important UI events
 */
@property (nonatomic, weak) id<PPOcrOverlayViewControllerDelegate> delegate;


/**
 * Property for scanning view controller to gain features for pausing and resuming camera
 */
@property (nonatomic, strong) UIViewController<PPScanningViewController> *scanningViewController;

@end

/**
 * Protocol for observing important events with scanning
 */
@protocol PPOcrOverlayViewControllerDelegate

/**
 * Called when Overlay will close. This can happen if the user pressed close button
 *
 * Perform here your VC dismiss logic.
 *
 *  @param vc View Controller responsible for scanning
 */
- (void)ocrOverlayViewControllerWillClose:(PPOcrOverlayViewController *)vc;

/**
 * Called when Accept button is tapped to return scanning VIN/License plate result
 */
- (void)ocrOverlayViewControllerDidReturnResult:(NSString *)scanResult;



@end
