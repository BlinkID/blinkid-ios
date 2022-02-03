//
//  MBBaseOverlaySettings.h
//  Microblink
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
 * Default: YES on iPhones with notch, NO otherwise.
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
 * Default: YES.
 */
@property (nonatomic, assign) BOOL displayTorchButton;

@end

NS_ASSUME_NONNULL_END
