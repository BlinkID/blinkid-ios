//
//  MBDriverLicenseDetailedInfo.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 17/06/2019.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDriverLicenseDetailedInfo : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * The restrictions to driving privileges for the United States driver license owner.
 */
@property (nonatomic, readonly, nullable) NSString *restrictions;

/**
 * The additional privileges granted to the United States driver license owner.
 */
@property (nonatomic, readonly, nullable) NSString *endorsements;

/**
 * The type of vehicle the driver license owner has privilege to drive.
 */
@property (nonatomic, readonly, nullable) NSString *vehicleClass;

@end

NS_ASSUME_NONNULL_END
