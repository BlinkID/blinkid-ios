//
//  MBDocumentVerificationOverlayViewController.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 28/05/2018.
//

#import "MBBaseOverlayViewController.h"
#import "MBLegacyDocumentVerificationOverlaySettings.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MBLegacyDocumentVerificationOverlayViewControllerDelegate;

@class MBLegacyDocumentVerificationOverlaySettings;
@class MBRecognizerCollection;

typedef NS_ENUM(NSInteger, MBLegacyDocumentVerificationHighResImageState) {
    MBLegacyDocumentVerificationHighResImageStateFrontSide,
    MBLegacyDocumentVerificationHighResImageStateBackSideSide
};

/**
 * Default overlay when using ID card combined recognizers for verification.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_CLASS_DEPRECATED("Use MBBlinkIdOverlayViewController.") MB_FINAL
@interface MBLegacyDocumentVerificationOverlayViewController : MBBaseOverlayViewController

/**
 * Common settings
 */
@property (nonatomic, strong, readonly) MBLegacyDocumentVerificationOverlaySettings *settings;

/**
 * Delegate
 */
@property (nonatomic, weak, readonly) id<MBLegacyDocumentVerificationOverlayViewControllerDelegate> delegate;

/**
 * Designated intializer.
 *
 *  @param settings MBDocumentOverlaySettings object
 *
 *  @param recognizerCollection MBRecognizerCollection object
 *
 *  @return initialized overlayViewController
 */
- (instancetype)initWithSettings:(MBLegacyDocumentVerificationOverlaySettings *)settings recognizerCollection:(MBRecognizerCollection *)recognizerCollection delegate:(nonnull id<MBLegacyDocumentVerificationOverlayViewControllerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
