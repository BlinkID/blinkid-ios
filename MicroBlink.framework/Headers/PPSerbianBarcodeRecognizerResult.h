//
//  PPSerbianBarcodeRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 21/06/2017.
//
//

#import "PPSerbianRecognizerResult.h"

/**
 * Result of scanning of Serbian payment barcodes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSerbianBarcodeRecognizerResult : PPSerbianRecognizerResult

/**
 * Address of the payment receiver
 */
@property (nonatomic, readonly, nullable) NSString *recipientAddress;

/**
 * Additional address detailes for the payment receiver
 */
@property (nonatomic, readonly, nullable) NSString *recipientDetailedAddress;

/**
 * Additional data available at the end of HUB3 QR and PDF417 barcode
 */
@property (nonatomic, readonly, nullable) NSString *optionalData;

/**
 * Address of the payer
 */
@property (nonatomic, readonly, nullable) NSString *payerAddress;

/**
 * Additional detailed address of the payer
 */
@property (nonatomic, readonly, nullable) NSString *payerDetailedAddress;

@end
