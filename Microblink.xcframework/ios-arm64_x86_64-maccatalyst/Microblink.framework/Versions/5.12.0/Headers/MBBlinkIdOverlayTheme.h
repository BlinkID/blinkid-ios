//
//  MBBlinkIdOverlayTheme.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 17/09/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(8.0)
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

/**
 * Image that animates when scanning is successful
 *
 * Default: check mark image
*/
@property (nonatomic, strong) UIImage *successScanningImage;

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

@end

NS_ASSUME_NONNULL_END
