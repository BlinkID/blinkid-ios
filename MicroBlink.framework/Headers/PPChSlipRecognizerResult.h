//
//  PPChSlipRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Jura on 19/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Result of scanning of Swiss orange payment slips
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPChSlipRecognizerResult : PPPhotoPayRecognizerResult

/**
 * String representing reference number of the payment
 */
@property (nonatomic, readonly, nullable) NSString *reference;

/**
 * String representing subscriber number for the payment
 */
@property (nonatomic, readonly, nullable) NSString *subscriberNumber;

@end
