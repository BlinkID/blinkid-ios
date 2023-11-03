//
//  MBBlinkIdOverlayTheme.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 17/09/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBBlinkIdOverlayTheme : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/**
 * Intructions text font
 *
 * Default: System 17.f
 */
@property (nonatomic, strong) UIFont *instructionsFont;

/**
 * Instructions text color
 *
 * Default: white
*/
@property (nonatomic, strong) UIColor *instructionsTextColor;

/**
 * Instructions view corner radius
 *
 * Default: 6
*/
@property (nonatomic, assign)  CGFloat instructionsCornerRadius;

/**
 * Flashlight warning font
 *
 * Default: System (iPhone - 14pt, iPad - 16pt)
 */
@property (nonatomic, strong) UIFont *flashlightWarningFont;

/**
 * Flashlight warning background color
 *
 * Default: #3A3A3C
*/
@property (nonatomic, strong) UIColor *flashlightWarningBackgroundColor;

/**
 * Flashlight warning text color
 *
 * Default: white
*/
@property (nonatomic, strong) UIColor *flashlightWarningTextColor;

/**
 * Flashlight warning corner radius
 *
 * Default: 4
*/
@property (nonatomic, assign) CGFloat flashlightWarningCornerRadius;

/**
 * First image in animation queu that is shown on first side finished scanning
 *
 * Default: check mark image
*/
@property (nonatomic, strong) UIImage *frontCardImage;

/**
 * Second image in animation array that is shown on first side finished scanning
 *
 * Default: check mark image
*/
@property (nonatomic, strong) UIImage *backCardImage;

/**
 * Need help tootlip background color.
 *
 * Default: Microblink blue for light and Microblink dark blue for dark mode
*/
@property (nonatomic) UIColor *tooltipBackgroundColor;

/**
 * Need help tootlip text color.
 *
 * Default: white
*/
@property (nonatomic) UIColor *tooltipTextColor;

/**
 * Need help tootlip corner radius.
 *
 * Default: 4
*/
@property (nonatomic) CGFloat tooltipCornerRadius;

/**
 * Initial onboarding alert view title color.
 *
 * Default: Microblink blue for light and white for dark mode
*/
@property (nonatomic) UIColor *onboardingAlertViewTitleTextColor;

/**
 * Initial onboarding alert view font.
 *
 * Default: SystemFont 17pt Semibold
*/
@property (nonatomic) UIFont *onboardingAlertViewTitleFont;

/**
 * Initial onboarding alert view title color.
 *
 * Default: Label
*/
@property (nonatomic) UIColor *onboardingAlertViewMessageTextColor;

/**
 * Initial onboarding alert view font.
 *
 * Default: SystemFont 14pt Regular
*/
@property (nonatomic) UIFont *onboardingAlertViewMessageFont;

/**
 * Initial onboarding alert view title color.
 *
 * Default: Microblink blue for light and Microblink cobalt for dark mode
*/
@property (nonatomic) UIColor *onboardingAlertViewDoneButtonTextColor;

/**
 * Initial onboarding alert view font.
 *
 * Default: SystemFont 17pt SemiBold
*/
@property (nonatomic) UIFont *onboardingAlertViewDoneButtonFont;

/**
 * Need help tutorial view title text color.
 *
 * Default: Microblink blue for light and white for dark mode
*/
@property (nonatomic) UIColor *tutorialViewTitleTextColor;

/**
 * Need help tutorial view title font.
 *
 * Default: SystemFont 22pt SemiBold
*/
@property (nonatomic) UIFont *tutorialViewTitleFont;

/**
 * Need help tutorial view message text color.
 *
 * Default: Label
*/
@property (nonatomic) UIColor *tutorialViewMessageTextColor;

/**
 * Need help tutorial view message font.
 *
 * Default: SystemFont 15pt
*/
@property (nonatomic) UIFont *tutorialViewMessageFont;

/**
 * Need help tutorial view action buttons text color.
 *
 * Default: Microblink blue for light and Microblink cobalt for dark mode
*/
@property (nonatomic) UIColor *tutorialViewActionButtonsTextColor;

/**
 * Need help tutorial view action button next and done font.
 *
 * Default: SystemFont 17pt Bold
*/
@property (nonatomic) UIFont *tutorialViewActionButtonNextFont;

/**
 * Need help tutorial view action button close and back font.
 *
 * Default: SystemFont 17pt
*/
@property (nonatomic) UIFont *tutorialViewActionButtonCloseFont;

/**
 * Need help tutorial view page control color.
 *
 * Default: Microblink blue for light and Microblink cobalt for dark mode
*/
@property (nonatomic) UIColor *tutorialViewPageControlColor;

/**
 * Help button image
 * Dimensions: 32x32
 *
 * Default: need-help-tooltip
*/
@property (nonatomic) UIImage *helpButtonImage;

/**
 * Help button dark image
 * Dimensions: 32x32
 *
 * Default: need-help-tooltip-dark
*/
@property (nonatomic) UIImage *helpButtonDarkImage;

/**
 * Default Reticle image
 *
 * Default: nil
*/
@property (nullable, nonatomic, strong) UIImage *defaultReticleImage;

/**
 * Image that animates when scanning is successful
 *
 * Default: check mark image
*/
@property (nonatomic, strong) UIImage *successScanningImage;

/**
 * Reticle error image
 *
 * Default: nil
*/
@property (nullable, nonatomic, strong) UIImage *errorReticleImage;

/**
 * Reticle animation color that is active before a card is detected
 *
 * Default: white
*/
@property (nonatomic, strong) UIColor *reticleColor;

/**
 * Reticle error color
 *
 * Default: red alpha .4f
*/
@property (nonatomic, strong) UIColor *reticleDefaultColor;

/**
 * Reticle error color
 *
 * Default: red alpha .4f
*/
@property (nonatomic, strong) UIColor *reticleErrorColor;

/**
 * Success flash color
 *
 * Default: white
*/
@property (nonatomic, strong) UIColor *successFlashColor;

@end

NS_ASSUME_NONNULL_END
