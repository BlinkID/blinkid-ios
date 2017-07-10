//
//  PPCroSlipResult.h
//  PhotoPayFramework
//
//  Created by Jura on 08/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPCroRecognizerResult.h"

/**
 * Reference status after validation. Can be one of the below values
 */
typedef NS_ENUM(NSUInteger, PPCroReferenceNumberStatus) {
    /** valid (model matches the check digits) */
    PPCroReferenceNumberStatusValid,
    /** Invalid (wrong format of the reference) */
    PPCroReferenceNumberStatusInvalid,
    /** Invalid checksum (model doesn't match check digits) */
    PPCroReferenceNumberStatusInvalidChecksum,
    /** Model is unkown (maybe it's missing) */
    PPCroReferenceNumberStatusModelUnknown,
    /** Reference format doesn't define check digits */
    PPCroReferenceNumberStatusNoChecksum
};

/**
 * Slip format id. Can be one of the below:
 */
typedef NS_ENUM(NSUInteger, PPCroSlipID) {
    /** Left side of HUB 1 payslip */
    PPCroSlipIDHUB1Left,
    /** Right side of HUB 1 payslip */
    PPCroSlipIDHUB1Right,
    /** Left side of HUB 3 payslip */
    PPCroSlipIDHUB3Left,
    /** Right side of HUB 3 payslip */
    PPCroSlipIDHUB3Right,
};

/**
 * Result of scanning of Croatian payment slips
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCroSlipRecognizerResult : PPCroRecognizerResult

/**
 * Status of the reference
 * @see PPCroReferenceNumberStatus
 */
@property (nonatomic, readonly) PPCroReferenceNumberStatus referenceNumberStatus;


/**
 * Id of the payslip (HUB1 left, HUB1 right, HUB3 left, HUB3 right)
 */
@property (nonatomic, readonly) PPCroSlipID slipId;

@end
