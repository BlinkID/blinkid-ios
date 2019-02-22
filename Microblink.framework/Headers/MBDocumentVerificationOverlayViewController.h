//
//  MBDocumentVerificationOverlayViewController.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 28/05/2018.
//

#import "MBBaseOverlayViewController.h"
#import "MBDocumentVerificationOverlaySettings.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MBDocumentVerificationOverlayViewControllerDelegate;

@class MBDocumentVerificationOverlaySettings;
@class MBRecognizerCollection;

typedef NS_ENUM(NSUInteger, MBDocumentVerificationHighResImageState) {
    MBDocumentVerificationHighResImageStateFrontSide,
    MBDocumentVerificationHighResImageStateBackSideSide
};

/**
 * Default overlay when using ID card combined recognizers for verification.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBDocumentVerificationOverlayViewController : MBBaseOverlayViewController

/**
 * Common settings
 */
@property (nonatomic, strong, readonly) MBDocumentVerificationOverlaySettings *settings;

/**
 * Delegate
 */
@property (nonatomic, weak, readonly) id<MBDocumentVerificationOverlayViewControllerDelegate> delegate;

/**
 * Designated intializer.
 *
 *  @param settings MBDocumentOverlaySettings object
 *
 *  @param recognizerCollection MBRecognizerCollection object
 *
 *  @return initialized overlayViewController
 */
- (instancetype)initWithSettings:(MBDocumentVerificationOverlaySettings *)settings recognizerCollection:(MBRecognizerCollection *)recognizerCollection delegate:(nonnull id<MBDocumentVerificationOverlayViewControllerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
