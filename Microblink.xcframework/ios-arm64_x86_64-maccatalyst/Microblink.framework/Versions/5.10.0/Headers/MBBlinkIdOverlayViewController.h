//
//  MBBlinkIdOverlayViewController.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 03/06/2019.
//

#import "MBBaseOverlayViewController.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MBBlinkIdOverlayViewControllerDelegate;

@class MBBlinkIdOverlaySettings;
@class MBRecognizerCollection;

/**
 * Default version of overlay view controller with modern design.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBlinkIdOverlayViewController : MBBaseOverlayViewController

/**
 * Common BlinkId UI settings
 */
@property (nonatomic, readonly) MBBlinkIdOverlaySettings *settings;

/**
 * Delegate
 */
@property (nonatomic, weak, readonly) id<MBBlinkIdOverlayViewControllerDelegate> delegate;

/**
 * Designated intializer.
 *
 *  @param settings MBBlinkIdOverlaySettings object
 *
 *  @param recognizerCollection MBRecognizerCollection object
 *
 *  @return initialized overlayViewController
 */
- (instancetype)initWithSettings:(MBBlinkIdOverlaySettings *)settings recognizerCollection:(MBRecognizerCollection *)recognizerCollection delegate:(nonnull id<MBBlinkIdOverlayViewControllerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
