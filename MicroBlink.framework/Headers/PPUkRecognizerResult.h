//
//  PPUkRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 19/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Result of scanning of UK giro slips or payement QR codes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPUkRecognizerResult : PPPhotoPayRecognizerResult

/**
 * String representing sorting code for the payment
 */
@property (nonatomic, readonly, nullable) NSString *sortingCode;

/**
 * String representing valid bank account number to which the payment goes
 */
@property (nonatomic, readonly, nullable) NSString *accountNumber;

/**
 * String representing reference number of the payment
 */
@property (nonatomic, readonly, nullable) NSString *reference;

@end
