//
//  PPCroBarcodeRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 24/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPCroRecognizerResult.h"

/**
 * Result of scanning of Croatian payment barcodes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCroBarcodeRecognizerResult : PPCroRecognizerResult

/**
 * Due date for payment. Date is formatted in the same format as defined by the HUB3 standard.
 */
@property (nonatomic, readonly, nullable) NSString *dueDate;

/**
 * Address of the payment receiver
 */
@property (nonatomic, readonly, nullable) NSString *recipientAddress;

/**
 * Additional address detailes for the payment receiver
 */
@property (nonatomic, readonly, nullable) NSString *recipientDetailedAddress;

/**
 * Additional data available at the end of HUB3 QR and PDF417 barcode
 */
@property (nonatomic, readonly, nullable) NSString *optionalData;

/**
 * Address of the payer
 */
@property (nonatomic, readonly, nullable) NSString *payerAddress;

/**
 * Additional detailed address of the payer
 */
@property (nonatomic, readonly, nullable) NSString *payerDetailedAddress;

/**
 * Payer's account number
 */
@property (nonatomic, readonly, nullable) NSString *payerAccountNumber;

/**
 * Payer's bank code
 */
@property (nonatomic, readonly, nullable) NSString *payerBankCode;

/**
 * Payer's IBAN
 */
@property (nonatomic, readonly, nullable) NSString *payerIban;

/**
 * Payer's reference model
 */
@property (nonatomic, readonly, nullable) NSString *payerReferenceModel;

/**
 * Payer's reference number
 */
@property (nonatomic, readonly, nullable) NSString *payerReferenceNumber;

@end
