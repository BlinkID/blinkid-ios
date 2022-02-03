//
//  PPUiSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 24/02/15.
//  Copyright (c) 2015 Microblink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "MBRecognizerCollection.h"
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class MBCameraSettings;

/**
 * Settings class containing UI information
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBOverlaySettings : NSObject <NSCopying>

/**
 * If default overlay contains textual information, text will be localized to this language
 *
 * Default: nil, because it uses default language of the device
 */
@property (nonatomic, strong, nullable) NSString *language;

/** Camera settings */
@property (nonatomic, strong) MBCameraSettings *cameraSettings;

/**
 * Initializes the object with default settings (see above for defaults).
 *
 *  @return object initialized with default values.
 */
- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
