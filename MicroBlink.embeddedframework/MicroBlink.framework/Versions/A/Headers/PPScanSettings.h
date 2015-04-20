//
//  PPScanSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 25/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPRecognizerSettings.h"

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
 * Settings class containing settings related to scanner behaviour
 */
@interface PPScanSettings : NSObject <NSCopying>

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

/**
 * Retrieves the list of all recognizer settings
 *
 * @return list of all recognizer settings
 */
- (NSArray*)recognizerSettingsList;

@end
