//
//  PPSkCode128RecognizerResult.h
//  PhotoPayFramework
//
//  Created by DoDo on 21/12/2016.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPSkRecognizerResult.h"

/**
 * Result of scanning Slovak payment Cdoe 128 barcodes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSkCode128RecognizerResult : PPSkRecognizerResult

/** String representing raw contents inside Code 128 */
@property (nonatomic, readonly, nullable) NSString *rawResult;

/** String representing processing code found in Slovakian Code 128 payment codes */
@property (nonatomic, readonly, nullable) NSString *processingCode;

/** String representing product code found in Slovakian Code 128 payment codes */
@property (nonatomic, readonly, nullable) NSString *productCode;

/** String representing service code found in Slovakian Code 128 payment codes */
@property (nonatomic, readonly, nullable) NSString *serviceCode;

/** String representing operational code */
@property (nonatomic, readonly, nullable) NSString *operationalCode;

/** String representing bank code of the recipient of the payment */
@property (nonatomic, readonly, nullable) NSString *bankCode;

/** String representing account number of the recipient of the payment */
@property (nonatomic, readonly, nullable) NSString *accountNumber;

@end
