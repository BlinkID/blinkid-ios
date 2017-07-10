//
//  PPUkSlipRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 19/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPUkRecognizerResult.h"

/**
 * Result of scanning of UK giro slips
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPUkSlipRecognizerResult : PPUkRecognizerResult

/**
 * Transaction code of the payment
 */
@property (nonatomic, readonly) NSInteger transactionCode;

@end
