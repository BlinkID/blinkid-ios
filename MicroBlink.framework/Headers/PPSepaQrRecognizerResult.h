//
//  PPSepaQrRecognizerResult.h
//  PhotoPayFramework
//
//  Created by DoDo on 28/10/2016.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Class representing result of scanning SEPA payment QR codes.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSepaQrRecognizerResult : PPPhotoPayRecognizerResult

/**
 * Name of the receiving side
 */
@property (nonatomic, readonly, nullable) NSString *recipientName;

/**
 * String representing valid international bank account number of the account to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *iban;

/**
 * String representing valid Bank Identifier Code of the bank to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *bic;

/**
 * String representing valid reference number of the payment
 */
@property (nonatomic, readonly, nullable) NSString *referenceNumber;

/**
 * PaymentDescription - string that describes the payment purpose
 */
@property (nonatomic, readonly, nullable) NSString *paymentDescription;

/**
 * Purpose code - string that represents the purpose code read from QR code, if available
 */
@property (nonatomic, readonly, nullable) NSString *purposeCode;

/**
 * Display data for payment description
 */
@property (nonatomic, readonly, nullable) NSString *displayData;

/**
  * Optional data from the end of QR code (if exists)
  */
@property (nonatomic, readonly, nullable) NSString *optionalData;

@end
