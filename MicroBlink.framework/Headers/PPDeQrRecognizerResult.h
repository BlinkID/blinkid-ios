//
//  PPDeQrSlipRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 24/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPDeRecognizerResult.h"

/**
 * Result of scanning of German payment QR codes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPDeQrRecognizerResult : PPDeRecognizerResult

/**
 * String representing valid Bank Identifier Code of the bank to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *bic;

/**
 * String that describes the type of the scanned form. E.g, for Stuzza QR code, that's "BCD"
 */
@property (nonatomic, readonly, nullable) NSString *formType;

/**
 * String that describes the version of the scanned form. E.g, for Stuzza QR code, that's "001"
 */
@property (nonatomic, readonly, nullable) NSString *formVersion;

/**
 * String that describes the function of the scanned form. E.g, for Stuzza QR code, that's "SCT" (Sepa Credit Transfer)
 */
@property (nonatomic, readonly, nullable) NSString *formFunction;

/**
 * Purpose code (Geschäftscode) - string that represents the purpose code read from QR code, if available
 */
@property (nonatomic, readonly, nullable) NSString *purposeCode;

/**
 * Receiver uses this data to as an idication related to the payment
 */
@property (nonatomic, readonly, nullable) NSString *displayData;

@end
