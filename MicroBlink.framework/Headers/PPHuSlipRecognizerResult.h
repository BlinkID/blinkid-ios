//
//  PPHuSlipRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 11/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Slip format id. Can be one of the below:
 */
typedef NS_ENUM(NSUInteger, PPHuSlipID) {
    /** White hungarian payslip */
    PPHuSlipIDWhite,
    /** Yellow hungarian payslip */
    PPHuSlipIDYellow,
};


/**
 * Result of scanning of Hungarian payment slips
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPHuSlipRecognizerResult : PPPhotoPayRecognizerResult

/**
 * String representing valid bank code value of the receiver bank (e.g. 0034000).
 */
@property (nonatomic, readonly, nullable) NSString *bankCode;

/**
 * String representing valid bank account number to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *accountNumber;

/**
 * ID which payer can use to identify payment
 */
@property (nonatomic, readonly, nullable) NSString *payerId;

/**
 * recipientName - name of the receiving side
 */
@property (nonatomic, readonly, nullable) NSString *recipientName;

/**
 * String representing valid bank code value of the payer's bank (e.g. 0034000).
 */
@property (nonatomic, readonly, nullable) NSString *payerBankCode;

/**
 * String representing valid bank account number of the payer
 */
@property (nonatomic, readonly, nullable) NSString *payerAccountNumber;

/**
 * Id of the payslip (Yellow, White)
 */
@property (nonatomic, readonly) PPHuSlipID slipId;

@end
