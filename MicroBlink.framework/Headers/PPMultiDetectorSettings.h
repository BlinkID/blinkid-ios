//
//  PPMultiDetectorSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 06/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPDetectorSettings.h"

/**
 * Settings for detector which combines multiple detectors inside.
 *
 * As only one PPDetectorSettings can be used at a time, PPMultiDetectorSettings wraps multiple settings so they can be used simultaneously.
 * In other words, it is necessary to use PPMultiDetectorSettings when more than 1 detectors are needed.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPMultiDetectorSettings : PPDetectorSettings

/**
 * Creates detector with array of concrete detectors.
 */
- (instancetype)initWithSettingsArray:(NSArray<__kindof PPDetectorSettings *> *)settingsArray;

/**
 * Array of contained detector settings
 */
@property (nonatomic, readonly) NSArray<__kindof PPDetectorSettings *> *settingsArray;

/**
 * If YES, detector will try to find all detection results based on a given set of detector settings
 *
 * Default: NO
 */
@property (nonatomic) BOOL allowMultipleResults;

@end
