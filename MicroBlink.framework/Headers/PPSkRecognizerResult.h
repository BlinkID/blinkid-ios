//
//  PPSkRecognizerResult.h
//  PhotoPayFramework
//
//  Created by DoDo on 21/12/2016.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Result of scanning Slovak payment objects (slips or barcodes)
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSkRecognizerResult : PPPhotoPayRecognizerResult

/**
 * Variable code of payment order
 */
@property (nonatomic, readonly, nullable) NSString *variableSymbol;

/**
 * Specific code of payment order
 */
@property (nonatomic, readonly, nullable) NSString *specificSymbol;

/**
 * Constant code of payment order
 */
@property (nonatomic, readonly, nullable) NSString *constantSymbol;

/**
 * String representing reference number of the payment
 */
@property (nonatomic, readonly, nullable) NSString *reference;

/**
 * String representing iban of the recipient of the payment
 */
@property (nonatomic, readonly, nullable) NSString *iban;

/**
 * String representing recipient name
 */
@property (nonatomic, readonly, nullable) NSString *recipientName;

/**
 * String representing recipient address
 */
@property (nonatomic, readonly, nullable) NSString *recipientAddress;

@end
