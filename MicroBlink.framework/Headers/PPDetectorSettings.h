//
//  PPDetectorSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 06/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * MicroBlink scanning libraries run detector objects to find objects on image.
 * This class is common superclass for each of the Detector settings.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPDetectorSettings : NSObject <NSCopying>

/**
 * This is an abstract class. Please use one of concrete classes.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
