//
//  MBDocumentOverlayViewController.h
//  PhotoPayFramework
//
//  Created by Jura on 29/09/14.
//  Copyright (c) 2014 Microblink Ltd. All rights reserved.
//

#import "MBBaseOverlayViewController.h"
#import "MBDocumentOverlaySettings.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MBDocumentOverlayViewControllerDelegate;

@class MBDocumentOverlaySettings;
@class MBRecognizerCollection;

/**
 * Default overlay when using ID card recognizers.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBDocumentOverlayViewController : MBBaseOverlayViewController

/**
 * Common settings
 */
@property (nonatomic, strong, readonly) MBDocumentOverlaySettings *settings;

/**
 * Delegate
 */
@property (nonatomic, weak, readonly) id<MBDocumentOverlayViewControllerDelegate> delegate;

/**
 * Designated intializer.
 *
 *  @param settings MBDocumentOverlaySettings object
 *
 *  @param recognizerCollection MBRecognizerCollection object
 *
 *  @return initialized overlayViewController
 */
- (instancetype)initWithSettings:(MBDocumentOverlaySettings *)settings recognizerCollection:(MBRecognizerCollection *)recognizerCollection delegate:(nonnull id<MBDocumentOverlayViewControllerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
