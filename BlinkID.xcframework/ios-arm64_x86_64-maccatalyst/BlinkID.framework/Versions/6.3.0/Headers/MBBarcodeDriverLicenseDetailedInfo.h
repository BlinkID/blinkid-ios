//
//  MBBarcodeDriverLicenseDetailedInfo.h
//  BlinkIDDev
//
// Copyright (c) 2022 Microblink Ltd. All rights reserved.
// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#ifndef MBBarcodeDriverLicenseDetailedInfo_h
#define MBBarcodeDriverLicenseDetailedInfo_h

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

@class MBBarcodeVehicleClassInfo;

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBBarcodeDriverLicenseDetailedInfo : NSObject

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

/**
 * The driver license conditions.
 */
@property (nonatomic, readonly, nullable) NSString *conditions;

/**
 * The additional information on vehicle class.
 */
@property (nonatomic, readonly, nullable) NSArray<MBBarcodeVehicleClassInfo *> *vehicleClassesInfo;

@end

NS_ASSUME_NONNULL_END

#endif /* MBBarcodeDriverLicenseDetailedInfo_h */
