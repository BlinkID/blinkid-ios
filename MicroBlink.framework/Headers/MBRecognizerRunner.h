//
//  MBRecognizerRunnerView.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 20/12/2017.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBRecognizerRunnerMetadataDelegates.h"
#import "MBScanningRecognizerRunnerDelegate.h"
#import "MBImageProcessingRecognizerRunnerDelegate.h"
#import "MBStringProcessingRecognizerRunnerDelegate.h"

@class MBCoordinator;
@class MBImage;
@class MBRecognizerCollection;

NS_ASSUME_NONNULL_BEGIN

/**
 * Factory class containing static methods for creating camera view controllers.
 * Camera view controllers created this way will be managed internally by the SDK, and input frames will be processed.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBRecognizerRunner : NSObject

@property (nonatomic, strong, nonnull, readonly) MBRecognizerRunnerMetadataDelegates *metadataDelegates;
@property (nonatomic, weak) id<MBScanningRecognizerRunnerDelegate> scanningRecognizerRunnerDelegate;
@property (nonatomic, weak, nullable) id<MBImageProcessingRecognizerRunnerDelegate> imageProcessingRecognizerRunnerDelegate;
@property (nonatomic, weak, nullable) id<MBStringProcessingRecognizerRunnerDelegate> stringProcessingRecognizerRunnerDelegate;

@property (nonatomic, nullable) MBCoordinator *coordinator;

- (instancetype)init NS_UNAVAILABLE;

/** Initializes the recognizer runner */
- (instancetype)initWithRecognizerCollection:(MBRecognizerCollection *)recognizerCollection NS_DESIGNATED_INITIALIZER;

- (void)resetState;

- (void)resetState:(BOOL)hard;

/**
 * Cancels all dispatched, but not yet processed image processing requests issued with processImage.
 * NOTE: next call to processImage will resume processing.
 */
- (void)cancelProcessing;

/**
 * Processes a MBImage object synchronously using current settings.
 * Since this method is synchronous, calling it from a main thread will switch the call to alternate thread internally and output a warning.
 *
 * Results are passed a delegate object given upon a creation of MBCoordinator.
 *
 *  @param image            image for processing
 */
- (void)processImage:(MBImage *)image;

/**
 * Processes a NSString object synchronously using current settings.
 * Since this method is synchronous, calling it from a main thread will switch the call to alternate thread internally and output a warning.
 *
 * Results are passed a delegate object given upon a creation of MBCoordinator.
 *
 *  @param string            string for processing
 */
- (void)processString:(NSString *)string;

/**
 * Method which is used to apply MBSettings object given by currentSettings property
 *
 * Usual use case is to update settings on the fly, to perform some complex scanning functionality
 * where a reconfiguration of the recognizers is needed.
 */
- (void)reconfigureRecognizers:(MBRecognizerCollection *)recognizerCollection;

@end

NS_ASSUME_NONNULL_END
