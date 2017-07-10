//
//  PPBeSlipRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 11/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Result of scanning of Belgian payment slips
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPBeSlipRecognizerResult : PPPhotoPayRecognizerResult

/**
 * String representing valid international bank account number of the account to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *iban;

/**
 * String representing valid reference number of the payment
 */
@property (nonatomic, readonly, nullable) NSString *reference;

/**
 * recipientName - name of the receiving side
 */
@property (nonatomic, readonly, nullable) NSString *recipientName;

@end
