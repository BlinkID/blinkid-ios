//
//  PPKosRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 19/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Result of scanning of Kosovo payment slips and barcodes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPKosRecognizerResult : PPPhotoPayRecognizerResult

/**
 * String representing reference number of the payment
 */
@property (nonatomic, readonly, nullable) NSString *reference;

/**
 * String representing payer's account number
 */
@property (nonatomic, readonly, nullable) NSString *payerAccountNumber;

/**
 * String representing utility ID that idenitifies the receiver of the payment
 */
@property (nonatomic, readonly, nullable) NSString *utilityId;

@end
