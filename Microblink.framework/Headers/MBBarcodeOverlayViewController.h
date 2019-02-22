//
//  MBBarcodeOverlayViewController.h
//  BarcodeFramework
//
//  Created by Jura on 22/12/13.
//  Copyright (c) 2015 Microblink Ltd. All rights reserved.
//

#import "MBBaseOverlayViewController.h"
#import "MBBarcodeOverlaySettings.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MBBarcodeOverlayViewControllerDelegate;

@class MBBarcodeOverlaySettings;
@class MBRecognizerCollection;

MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBarcodeOverlayViewController : MBBaseOverlayViewController

/**
 * Common settings
 */
@property (nonatomic, strong, readonly) MBBarcodeOverlaySettings *settings;

/**
 * Delegate
 */
@property (nonatomic, weak, readonly) id<MBBarcodeOverlayViewControllerDelegate> delegate;

/**
 * Designated intializer.
 *
 *  @param settings MBBarcodeOverlaySettings object
 *
 *  @param recognizerCollection MBRecognizerCollection object
 *
 *  @return initialized overlayViewController
 */
- (instancetype)initWithSettings:(MBBarcodeOverlaySettings *)settings recognizerCollection:(MBRecognizerCollection *)recognizerCollection delegate:(nonnull id<MBBarcodeOverlayViewControllerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
