//
//  PPFormOcrOverlayViewController.h
//  BlinkOCR
//
//  Created by Jura on 01/03/15.
//  Copyright (c) 2015 PhotoPay. All rights reserved.
//

#import <MicroBlink/MicroBlink.h>
#import <MicroBlink/PPBaseOverlayViewController.h>

#import "PPScanElement.h"

@protocol PPFormOcrOverlayViewControllerDelegate;

/**
 * View Controller responsible for view hierarchy for Form OCR scannning.
 * This view hierarchy is added as an overlay to Camera preview
 */
@interface PPFormOcrOverlayViewController : PPBaseOverlayViewController

// needs to be weak to avoid a reference cycle
@property(nonatomic, weak) PPCoordinator *coordinator;

/**
 * Delegate which is notified with important UI events
 */
@property(nonatomic, weak) id<PPFormOcrOverlayViewControllerDelegate> delegate;

/**
 * Array of PPScanElement objects which defines which Elements are scanned
 */
@property(nonatomic, strong) NSArray *scanElements;

/**
 * Button for turning on/off the light
 */
@property(weak, nonatomic) IBOutlet UIButton *buttonLight;

/**
 * Button for moving on to next scannning element
 */
@property(weak, nonatomic) IBOutlet UIButton *buttonNext;

/**
 * Button for moving on to next scannning element
 */
@property (weak, nonatomic) IBOutlet UIButton *buttonSkip;

/**
 * Container for Pivot view (a list with scanning elements which can be scrolled)
 */
@property(weak, nonatomic) IBOutlet UIView *pivotViewContainer;

/**
 * Tooltip which displays help message
 */
@property(weak, nonatomic) IBOutlet UILabel *labelTooltip;

/**
 * Viewfinder view
 */
@property(weak, nonatomic) IBOutlet UIView *viewfinder;

/**
 * Called when user presses Close button
 *
 *  @param sender Close button
 */
- (IBAction)didPressClose:(id)sender;

/**
 * Called when the user presses Light button
 *
 *  @param sender Light button
 */
- (IBAction)didPressLight:(id)sender;

/**
 * Called when the user presses Help button
 *
 *  @param sender Help button
 */
- (IBAction)didPressHelp:(id)sender;

/**
 * Called when the user presses Next button
 *
 *  @param sender Next button
 */
- (IBAction)didTapNext:(id)sender;

@property(weak, nonatomic) IBOutlet UIView *resultViewPlaceholder;
/**
 * Used for easier instantiation from Nib file
 *
 *  @param nibName Name of the nib file
 *
 *  @return View controller instance
 */
+ (instancetype)allocFromNibName:(NSString *)nibName;

@end

/**
 * Protocol for observing important events with scanning
 */
@protocol PPFormOcrOverlayViewControllerDelegate

/**
 * Called when Overlay will close. This can happen if the user pressed close button
 *
 * Perform here your VC dismiss logic.
 *
 *  @param vc View Controller responsible for scanning
 */
- (void)formOcrOverlayViewControllerWillClose:(PPFormOcrOverlayViewController *)vc;

/**
 * Called when Scanning finishes and Overlay will dissapear.
 *
 * Perform here your VC dismiss logic, as well as result handling
 *
 *  @param vc           View Controller responsible for scanning
 *  @param scanElements Array of PPScanElement objects with all scanning results
 */
- (void)formOcrOverlayViewController:(PPFormOcrOverlayViewController *)vc didFinishScanningWithElements:(NSArray *)scanElements;

@end
