//
//  PPNedSlipRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 22/06/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Result of scanning Dutch Acceptgiros
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPNedSlipRecognizerResult : PPPhotoPayRecognizerResult

/**
 * String representing valid international bank account number of the account to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString* iban;

/**
 * String representing valid bank account number to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString* accountNumber;

/**
 * String representing reference number of the payment
 */
@property (nonatomic, readonly, nullable) NSString* referenceNumber;

@end
