//
//  PPSerbianRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 21/06/2017.
//
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Result of scanning of Serbian barcodes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSerbianRecognizerResult : PPPhotoPayRecognizerResult

/**
 * recipientName - name of the receiving side
 */
@property (nonatomic, readonly, nullable) NSString *recipientName;

/**
 * payer name - name of the payer
 */
@property (nonatomic, readonly, nullable) NSString *payerName;

/**
 * String representing valid bank account number to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *accountNumber;

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
 * String that represents the purpose code
 */
@property (nonatomic, readonly, nullable) NSString *purposeCode;


@end
