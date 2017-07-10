//
//  PPSkDataMatrixRecognizerResult.h
//  PhotoPayFramework
//
//  Created by DoDo on 21/12/2016.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPSkBarcodeRecognizerResult.h"

/**
 * Result of scanning Slovak payment DataMatrix codes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSkDataMatrixRecognizerResult : PPSkBarcodeRecognizerResult

/**
 * String representing raw contents inside DataMatrix
 */
@property (nonatomic, readonly, nullable) NSString *rawResult;

/**
 * Name of the payer
 */
@property (nonatomic, readonly, nullable) NSString *payerName;

/**
 * Address of the payer
 */
@property (nonatomic, readonly, nullable) NSString *payerAddress;

@end
