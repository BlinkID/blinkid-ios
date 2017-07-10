//
//  PPSloQrRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 01/02/2017.
//  Copyright © 2017 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Result of scanning of Slovenian UPN QR codes which are found on UPN payment slips
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSloQrCodeRecognizerResult : PPPhotoPayRecognizerResult

/**
 * YES if deposit option is included in payment, NO otherwise
 */
@property (nonatomic, readonly) BOOL deposit;

/**
 * Due date of the payment
 */
@property (nonatomic, readonly, nullable) NSDate *dueDate;

/**
 * Date of execution of the payment
 */
@property (nonatomic, readonly, nullable) NSDate *executionDate;

/**
 * The International bank account number of the account to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *iban;

/**
 * The street of the payer, if it exists
 */
@property (nonatomic, readonly, nullable) NSString *payerStreet;

/**
 * The place of the payer, if it exists
 */
@property (nonatomic, readonly, nullable) NSString *payerPlace;

/**
 * The international bank account number of the account from where the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *payerIban;

/**
 * The name of the payer, if it exists
 */
@property (nonatomic, readonly, nullable) NSString *payerName;

/**
 * The reference of the payment's payer
 */
@property (nonatomic, readonly, nullable) NSString *payerReference;

/**
 * Description of the payment
 */
@property (nonatomic, readonly, nullable) NSString *paymentDescription;

/**
 * Reference of the payment
 */
@property (nonatomic, readonly, nullable) NSString *paymentReference;

/**
 * The purpose code of the payment
 */
@property (nonatomic, readonly, nullable) NSString *purposeCode;

/**
 * The street of the recipient
 */
@property (nonatomic, readonly, nullable) NSString *recipientStreet;

/**
 * The place of the recipient
 */
@property (nonatomic, readonly, nullable) NSString *recipientPlace;

/**
 * The name of the recipient
 */
@property (nonatomic, readonly, nullable) NSString *recipientName;

/**
 * YES if withdraw option is included in payment, NO otherwise
 */
@property (nonatomic, readonly) BOOL withdraw;

/**
 * Returns raw content of the barcode
 */
@property (nonatomic, readonly, nullable) NSString *rawResult;

@end
