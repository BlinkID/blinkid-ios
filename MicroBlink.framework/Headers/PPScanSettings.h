//
//  PPScanSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 25/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Denotes the mode in which Recognizers performs recognition
 */
typedef NS_ENUM(NSUInteger, PPRecognitionMode) {

    /** Classic, production mode. Results are returned after first valid scanning */
    PPRecognitionModeDefault,

    /** Recognition Test. Results are never returned, recognition is performed repeatedly */
    PPRecognitionModeTest,

    /** Recognition Test. Results are never returned, only detection is performed repeatedly */
    PPRecognitionModeDetectionTest
};

/**
 *  Denotes the mode in which FrameQuality estimation works
 */
typedef NS_ENUM(NSUInteger, PPFrameQualityEstimationMode) {

    /** Default. Frame quality estimation is ON if enabled recognizers require it by default.*/
    PPFrameQualityEstimationModeDefault,

    /** Frame quality estimation is always on */
    PPFrameQualityEstimationModeOn,

    /** Frame quality estimation is always off */
    PPFrameQualityEstimationModeOff
};

/**
 * Settings class containing settings related to scanner behaviour
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPScanSettings : NSObject <NSCopying>

/**
 * Contains PPRecognizerSettings objects - settings for each individual recognizer.
 * On each video frame taken by device scamera, processing is performed by a series of recognizers.
 * Ordering of these recognizers is specified by this array.
 *
 * @see PPRecognizerSettings.
 */
@property (nonatomic, strong, readonly) NSArray<PPRecognizerSettings *> *recognizerSettingsList;

/**
 * If NO, recognizer chain will stop when finds first valid scan results and will return just it.
 * If YES, recognizer chain can sometimes return more than one scanning result. 
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL allowMultipleResults;

/**
 * Timeout interval in which the partial scanning results in PhotoPay will be returned to the user.
 * If <= 0.0, no timeout event will be reported.
 *
 * Default: 7.0 seconds
 */
@property (nonatomic, assign) NSTimeInterval partialRecognitionTimeout;

/**
 * Recognition mode.
 *
 * Default: PPRecognitionModeDefault
 */
@property (nonatomic, assign) PPRecognitionMode recognitionMode;

/**
 * Frame quality estimation mode. If frame quality estimation is on, some video frames will be skipped, if
 * frame quality estimator determines the quality is too low (i.e. frame is too blurry, too dark, or something similar).
 *
 * The downside is that frame quality estimation spends some valuable CPU time.
 *
 * Default PPFrameQualityEstimationModeDefault
 */
@property (nonatomic, assign) PPFrameQualityEstimationMode frameQualityEstimationMode;

/**
 * Designated initializer. Initializes the object with default settings (see above for defaults)
 *
 *  @return object initialized with default values.
 */
- (instancetype)init;

/**
 * Adds recognizer setting to the list of all recognizer.
 * Adding recognizer settings results with this recognizer being applied on each video frame in the processing stage.
 *
 * @param setting Concerete recognizer setting.
 */
- (void)addRecognizerSettings:(PPRecognizerSettings*)setting;

/**
 * Removes recognizer setting to the list of all recognizer.
 * Removing recognizer settings means this recognizer will ne longer be applied in the processing stage
 *
 * @param setting Concerete recognizer setting.
 */
- (void)removeRecognizerSettings:(PPRecognizerSettings*)setting;

@end

NS_ASSUME_NONNULL_END