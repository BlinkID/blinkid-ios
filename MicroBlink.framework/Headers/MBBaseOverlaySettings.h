//
//  MBBaseOverlaySettings.h
//  MicroBlink
//
//  Created by Dino Gustin on 04/05/2018.
//

#import "MBOverlaySettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing UI information
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBaseOverlaySettings : MBOverlaySettings

/**
 * If YES, Overlay View Controller will be autorotated independently of ScanningViewController.
 *
 * Default: NO.
 */
@property (nonatomic, assign) BOOL autorotateOverlay;

/**
 * If YES, default camera overlay will display Status bar.
 * Usually, if camera is displayed inside Navigation View Controler, this is reasonable to set to YES.
 *
 * Default: NO.
 */
@property (nonatomic, assign) BOOL showStatusBar;

/**
 * Default: UIInterfaceOrientationMaskPortrait
 */
@property (nonatomic, assign) UIInterfaceOrientationMask supportedOrientations;

/**
 * Full path to the sound file which is played when the valid result is scanned.
 *
 * Default: `[bundle pathForResource:@"PPbeep" ofType:@"wav"];
 */
@property (nonatomic, strong, nullable) NSString *soundFilePath;

/**
 * Default: YES.
 */
@property (nonatomic, assign) BOOL displayCancelButton;

/**
 * Returns/sets cancel button text that is shown if displayCancelButton is on.
 *
 * Default: string defined by "photopay_close"
 * key in strings file in Microblink.bundle
 */
@property(nonatomic, strong) NSString *cancelButtonText;

/**
 * Default: YES.
 */
@property (nonatomic, assign) BOOL displayTorchButton;

/**
 * Returns/sets torch on button text that is shown if displayTorchButton is on.
 *
 * Default: string defined by "photopay_light_on"
 * key in strings file in Microblink.bundle
 */
@property(nonatomic, strong) NSString *torchOnButtonText;

/**
 * Returns/sets torch off button text that is shown if displayTorchButton is on.
 *
 * Default: string defined by "photopay_light_off"
 * key in strings file in Microblink.bundle
 */
@property(nonatomic, strong) NSString *torchOffButtonText;

@end

NS_ASSUME_NONNULL_END
