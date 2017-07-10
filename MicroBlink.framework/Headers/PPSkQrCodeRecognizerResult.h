//
//  PPCzQrCodeRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 24/03/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPSkBarcodeRecognizerResult.h"

/**
 * Result of scanning Slovak payment QR codes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSkQrCodeRecognizerResult : PPSkBarcodeRecognizerResult

/**
 * String representing valid Bank Identifier Code of the bank to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *bic;

/**
 * Due date for payment. Date is formatted in the same format as defined by the HUB3 standard.
 */
@property (nonatomic, readonly, nullable) NSString *dueDate;

/**
 * Name of the recipient
 */
@property (nonatomic, readonly, nullable) NSString *recipientName;

/**
 * Address of the payment receiver
 */
@property (nonatomic, readonly, nullable) NSString *recipientAddress;

/**
 * Additional address detailes for the payment receiver
 */
@property (nonatomic, readonly, nullable) NSString *recipientDetailedAddress;

/**
 * Identification number of invoice
 */
@property (nonatomic, readonly, nullable) NSString *invoiceId;

@end
