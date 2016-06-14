//
//  PPLicenseSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 24/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing License information
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPLicenseSettings : NSObject <NSCopying>

/**
 * License key for unlocking the scanning library
 */
@property (nonatomic, strong, nullable) NSString *licenseKey;

/**
 * If the license is Enterprise (for more than one app!), you will also need to set the licensee para,
 * Otherwise keep this value nil!
 */
@property (nonatomic, strong, nullable) NSString *licensee;

/**
 * Designated initializer for regular licenses
 *
 *  @param licenseKey the key
 *
 *  @return license settings instance
 */
- (instancetype)initWithLicenseKey:(nullable NSString *)licenseKey;

/**
 * Designated initializer for Enterprise licenses
 *
 *  @param licenseKey the key
 *  @param licensee name of the licensee
 *
 *  @return license settings instance
 */
- (instancetype)initWithLicenseKey:(nullable NSString *)licenseKey
                          licensee:(nullable NSString *)licensee;

@end

NS_ASSUME_NONNULL_END