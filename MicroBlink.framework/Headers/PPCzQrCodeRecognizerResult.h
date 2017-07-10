//
//  PPCzQrCodeRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 24/03/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"


/**
 * Result of scanning CZK payment QR codes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCzQrCodeRecognizerResult : PPPhotoPayRecognizerResult

/**
 * String representing valid international bank account number of the account to which the payment goes
 */
@property (nonatomic, readonly, nonnull) NSString *iban;

/**
 * String representing reference number of the payment
 */
@property (nonatomic, readonly, nonnull) NSString *reference;

/**
 * Name of the recipient
 */
@property (nonatomic, readonly, nonnull) NSString *recipientName;

/**
 * Due date for payment. Date is formatted in the same format as defined by the HUB3 standard.
 */
@property (nonatomic, readonly, nonnull) NSString *dueDate;

/**
 * Type of payment
 */
@property (nonatomic, readonly, nonnull) NSString *paymentType;

/**
 * Payment description code
 */
@property (nonatomic, readonly, nonnull) NSString *paymentDescription;

/**
 * Variable code of payment order
 */
@property (nonatomic, readonly, nonnull) NSString *variableSymbol;

/**
 * Specific code of payment order
 */
@property (nonatomic, readonly, nonnull) NSString *specificSymbol;

/**
 * Constant code of payment order
 */
@property (nonatomic, readonly, nonnull) NSString *constantSymbol;

/**
 * Version of protocol
 */
@property (nonatomic, readonly, nonnull) NSString *formVersion;

@end
