//
//  PPZXingRecognizerResult.h
//  Pdf417Framework
//
//  Created by Jura on 11/07/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"
#import "PPBarcodeDetailedData.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Type of the barcode which BarDecoderRecognizer returnes
 */
typedef NS_ENUM(NSUInteger, PPZXingBarcodeType){
    /** Code 39 */
    PPZXingBarcodeTypeAztec,
    /** Code 128 */
    PPZXingBarcodeTypeCode128,
    /** Code 39 */
    PPZXingBarcodeTypeCode39,
    /** Data Matrix */
    PPZXingBarcodeTypeDataMatrix,
    /** EAN 13 */
    PPZXingBarcodeTypeEAN13,
    /** EAN 8 */
    PPZXingBarcodeTypeEAN8,
    /** ITF */
    PPZXingBarcodeTypeITF,
    /** QR code */
    PPZXingBarcodeTypeQR,
    /** UPCA */
    PPZXingBarcodeTypeUPCA,
    /** UPCE */
    PPZXingBarcodeTypeUPCE,
    
};

/**
 * Result of scanning with ZXing Recognizer
 *
 * Contains raw Barcode detailed data, barcode type, and methods for getting string representation of results.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPZXingRecognizerResult : PPRecognizerResult

/**
 * Type of the barcode scanned
 *
 *  @return Type of the barcode
 */
- (PPZXingBarcodeType)barcodeType;

/**
 * Byte array with result of the scan
 */
- (NSData *)data;

/**
 * Retrieves string content of the scanned data using guessed encoding.
 *
 * If you're 100% sure you know the exact encoding in the barcode, use stringUsingEncoding: method.
 * Otherwise stringUsingDefaultEncoding.
 *
 * This method uses `[NSString stringEncodingForData:encodingOptions:convertedString:usedLossyConversion:` method for
 * guessing the encoding.
 *
 *  @return created string, or nil if encoding couldn't be found.
 */
- (NSString *)stringUsingGuessedEncoding;

/**
 * Retrieves string content of the scanned data using given encoding.
 *
 *  @param encoding The encoding for the returned string.
 *
 *  @return String created from data property, using given encoding
 */
- (NSString *)stringUsingEncoding:(NSStringEncoding)encoding;

/**
 * Raw barcode detailed result
 */
- (PPBarcodeDetailedData *)rawData;

/**
 * Method which gives string representation for a given PPZXingBarcodeType enum value.
 *
 *  @param type PPZXingBarcodeType enum value
 *
 *  @return String representation of a given PPZXingBarcodeType enum value.
 */
+ (NSString *)toTypeName:(PPZXingBarcodeType)type;

@end

NS_ASSUME_NONNULL_END