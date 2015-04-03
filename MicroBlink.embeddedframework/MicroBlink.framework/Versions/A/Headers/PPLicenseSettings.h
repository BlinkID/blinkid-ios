//
//  PPLicenseSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 24/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Settings class containing License information
 */
@interface PPLicenseSettings : NSObject <NSCopying>

/**
 * License key for unlocking the scanning library
 */
@property (nonatomic, strong) NSString *licenseKey;

/**
 * If the license is Enterprise (for more than one app!), you will also need to set the licensee para,
 * Otherwise keep this value nil!
 */
@property (nonatomic, strong) NSString *licensee;

/**
 * Designated initializer for regular licenses
 *
 *  @param licenseKey the key
 *
 *  @return license settings instance
 */
- (instancetype)initWithLicenseKey:(NSString *)licenseKey;

/**
 * Designated initializer for Enterprise licenses
 *
 *  @param licenseKey the key
 *  @param licensee name of the licensee
 *
 *  @return license settings instance
 */
- (instancetype)initWithLicenseKey:(NSString *)licenseKey
                          licensee:(NSString *)licensee;

@end
