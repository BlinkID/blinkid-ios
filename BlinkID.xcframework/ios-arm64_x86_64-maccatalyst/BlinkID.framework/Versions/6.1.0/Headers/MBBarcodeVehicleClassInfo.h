//
//  MBBarcodeVehicleClassInfo.h
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

@class MBDate;

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBBarcodeVehicleClassInfo : NSObject

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
@property (nonatomic, readonly, nullable) MBDate *effectiveDate;

/**
 * The date of expiry of licence.
 */
@property (nonatomic, readonly, nullable) MBDate *expiryDate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithVehicleClass:(NSString *)vehicleClass licenceType:(NSString *)licenceType effectiveDate:(nullable MBDate *)effectiveDate expiryDate:(nullable MBDate *)expiryDate NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
