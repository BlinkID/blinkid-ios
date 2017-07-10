//
//  PPKosBarcodeRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 21/06/2017.
//
//

#import "PPKosRecognizerResult.h"

/**
 * Result of scanning of Kosovo new type 128 barcode
 */
PP_CLASS_AVAILABLE_IOS(6.0)

@interface PPKosBarcodeRecognizerResult : PPKosRecognizerResult

/**
 * District of the payment receiver
 */
@property (nonatomic, readonly, nullable) NSString *district;

/**
 * Due date for payment. Date is formatted in the same format YYMM
 */
@property (nonatomic, readonly, nullable) NSString *dueDate;

/**
 * Customer ID
 */
@property (nonatomic, readonly, nullable) NSString *customerID;

/**
 * Kossovo 128 barcode service code
 */
@property (nonatomic, readonly, nullable) NSString *serviceCode;

@end
