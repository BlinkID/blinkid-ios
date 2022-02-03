//
//  MBDebugRecognizerRunnerViewDelegate.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 04/01/2018.
//

#import <Foundation/Foundation.h>

@class MBImage;
@protocol MBRecognizerRunnerViewController;

/**
 * Protocol for obtaining debug metadata
 */
@protocol MBDebugRecognizerRunnerViewControllerDelegate <NSObject>
@required

/**
 * Scanning library did output debug image
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)recognizerRunnerViewController:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController didOutputDebugImage:(nonnull MBImage *)image;

/**
 * Scanning library did output debug text
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)recognizerRunnerViewController:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController didOutputDebugText:(nonnull NSString *)text;

@end
