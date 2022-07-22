//
//  MBVehicleClassInfo.h
//  BlinkShowcaseDev
//
//  Created by Mijo Gracanin on 09.03.2022..
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

@class MBDateResult;

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(9.0)
@interface MBVehicleClassInfo : NSObject

/**
 * The type of vehicle the driver license owner has privilege to drive.
 */
@property (nonatomic, readonly) NSString *vehicleClass;

/**
 * The type of driver licence.
 */
@property (nonatomic, readonly) NSString *licenceType;

/**
 * The date since licence is effective.
 */
@property (nonatomic, readonly) MBDateResult *effectiveDate;

/**
 * The date of expiry of licence.
 */
@property (nonatomic, readonly) MBDateResult *expiryDate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithVehicleClass:(NSString *)vehicleClass licenceType:(NSString *)licenceType effectiveDate:(MBDateResult *)effectiveDate expiryDate:(MBDateResult *)expiryDate NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
