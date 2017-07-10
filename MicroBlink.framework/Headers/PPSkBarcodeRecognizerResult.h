//
//  PPSkBarcodeRecognizerResult.h
//  PhotoPayFramework
//
//  Created by DoDo on 21/12/2016.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPSkRecognizerResult.h"

/**
 * Result of scanning Slovak payment barcodes (QR and DataMatrix)
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSkBarcodeRecognizerResult : PPSkRecognizerResult

/**
 * Payment description code
 */
@property (nonatomic, readonly, nullable) NSString *paymentDescription;

@end
