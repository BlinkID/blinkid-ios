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

/**
 * MicroBlink scanning libraries run several Recognizers on each video frame.
 *
 * Each recognizer is configured with the appropriate settings object.
 *
 * This class is common superclass for each of the Recognizer settings,
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPRecognizerSettings : NSObject <NSCopying>

/**
 * Property which determines if the recognizer is enabled
 *
 *  If YES, recognizer is enabled, and it peroforms recognition on each video frame.
 *
 * Default: YES
 */
@property (nonatomic, getter=isEnabled) BOOL enabled;

- (Class) getIdealOverlayViewControllerClass;

- (UIInterfaceOrientationMask)getOptimalHudOrientation;

@end

NS_ASSUME_NONNULL_END
