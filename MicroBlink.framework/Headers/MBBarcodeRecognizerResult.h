//
//  MBBarcodeRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 28/11/2017.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBRecognizerResult.h"
#import "MBBarcodeResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Result of MBBarcodeRecognizer; is used for scanning most of 1D barcode formats, and 2D format
 * such as Aztec, DataMatrix and QR code
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBarcodeRecognizerResult : MBRecognizerResult<NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Byte array with result of the scan
 */
@property(nonatomic, strong, readonly, nullable) NSData* rawData;

/**
 * Retrieves string content of scanned data
 */
@property(nonatomic, strong, readonly, nullable) NSString* stringData;

/**
 * Flag indicating uncertain scanning data
 * E.g obtained from damaged barcode.
 */
@property(nonatomic, assign, readonly) BOOL uncertain;

/**
 * Method which gives string representation for a given PPBarcodeType enum value.
 *
 *  @param type PPBarcodeType enum value
 *
 *  @return String representation of a given PPBarcodeType enum value.
 */
+ (NSString *_Nonnull)toTypeName:(MBBarcodeType)type;

/**
 * Type of the barcode scanned
 *
 *  @return Type of the barcode
 */
@property(nonatomic, assign, readonly) MBBarcodeType barcodeType;


@end

NS_ASSUME_NONNULL_END
