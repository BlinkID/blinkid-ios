//
//  PPUkQrRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 19/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPUkRecognizerResult.h"

/**
 * Result of scanning of UK payement QR codes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPUkQrRecognizerResult : PPUkRecognizerResult

/**
 * Recipient name for the payment
 */
@property (nonatomic, readonly, nullable) NSString *recipientName;

@end
