//
//  PPDeRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 24/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Result of scanning of German payment slips and barcodes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPDeRecognizerResult : PPPhotoPayRecognizerResult

/**
 * recipientName - name of the receiving side
 */
@property (nonatomic, readonly, nullable) NSString *recipientName;

/**
 * String representing valid international bank account number of the account to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *iban;

/**
 * String representing valid bank code value (BLZ) of the receiver bank (e.g. 0034000).
 */
@property (nonatomic, readonly, nullable) NSString *bankCode;

/**
 * String representing valid bank account number to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *accountNumber;

/**
 * String representing reference number of the payment
 */
@property (nonatomic, readonly, nullable) NSString *referenceNumber;

/**
 * PaymentDescription - string that describes the payment purpose
 */
@property (nonatomic, readonly, nullable) NSString *paymentDescription;

@end
