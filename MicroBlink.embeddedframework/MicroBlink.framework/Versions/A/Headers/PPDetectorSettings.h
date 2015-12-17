//
//  PPDetectorSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 06/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

struct DetectorSettingsImpl;
typedef struct DetectorSettingsImpl DetectorSettingsImpl;

/**
 * MicroBlink scanning libraries run detector objects to find objects on image
 *
 * Each detector is configured with PPDetectorSettings object
 *
 * This class is common superclass for each of the Detector settings,
 */
@interface PPDetectorSettings : NSObject <NSCopying>

@property (nonatomic, readonly, assign) DetectorSettingsImpl* settings;

- (instancetype)initWithSettings:(DetectorSettingsImpl*)settings;

@end
