//
//  PPSloSlipRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 26/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Result of scanning of Slovenian UPN payment slips
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSloSlipRecognizerResult : PPPhotoPayRecognizerResult

/**
 * String representing valid international bank account number of the account to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *iban;

/**
 * String representing valid Bank Identifier Code of the bank to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *bic;

/**
 * String representing reference number of the payment
 */
@property (nonatomic, readonly, nullable) NSString *referenceNumber;

/**
 * String representing model of the reference
 */
@property (nonatomic, readonly, nullable) NSString *referenceModel;

/**
 * PaymentDescription - string that describes the payment purpose
 */
@property (nonatomic, readonly, nullable) NSString *paymentDescription;

/**
 * RecipientName - string that describes the receiver of the payment (payee)
 */
@property (nonatomic, readonly, nullable) NSString *recipientName;

@end
