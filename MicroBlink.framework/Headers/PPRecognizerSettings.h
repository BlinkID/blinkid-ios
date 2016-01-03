//
//  PPRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 03/11/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

struct RecognizerSettingsImpl;
typedef struct RecognizerSettingsImpl RecognizerSettingsImpl;

/**
 * MicroBlink scanning libraries run several Recognizers on each video frame.
 *
 * Each recognizer is configured with the appropriate settings object.
 *
 * This class is common superclass for each of the Recognizer settings,
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPRecognizerSettings : NSObject <NSCopying>

@property (nonatomic, readonly, assign) RecognizerSettingsImpl *settings;

- (instancetype)initWithSettings:(RecognizerSettingsImpl *)settings;

/**
 * Property which determines if the recognizer is enabled
 *
 *  @param enabled If YES, recognizer is enabled, and it peroforms recognition on each video frame.
 */
- (void)setEnabled:(BOOL)enabled;

/**
 * Determines if recognizer is enabled
 *
 *  @return YES if recognizer is enabled
 */
- (BOOL)isEnabled;

@end

NS_ASSUME_NONNULL_END