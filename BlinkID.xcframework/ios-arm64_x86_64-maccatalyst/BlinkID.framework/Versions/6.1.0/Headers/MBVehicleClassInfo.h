//
//  MBVehicleClassInfo.h
//  BlinkShowcaseDev
//
// Copyright (c) 2022 Microblink Ltd. All rights reserved.
// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

@class MBDateResult;
@class MBStringResult;

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBVehicleClassInfo : NSObject

/**
 * The type of vehicle the driver license owner has privilege to drive.
 */
@property (nonatomic, readonly, nullable) MBStringResult *vehicleClass;

/**
 * The type of driver licence.
 */
@property (nonatomic, readonly, nullable) MBStringResult *licenceType;

/**
 * The date since licence is effective.
 */
@property (nonatomic, readonly, nullable) MBDateResult *effectiveDate;

/**
 * The date of expiry of licence.
 */
@property (nonatomic, readonly, nullable) MBDateResult *expiryDate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithVehicleClass:(nullable MBStringResult *)vehicleClass licenceType:(nullable MBStringResult *)licenceType effectiveDate:(nullable MBDateResult *)effectiveDate expiryDate:(nullable MBDateResult *)expiryDate NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
