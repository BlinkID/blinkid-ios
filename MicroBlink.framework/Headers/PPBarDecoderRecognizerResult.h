//
//  PPBarDecoderRecognizerResult.h
//  Pdf417Framework
//
//  Created by Jura on 11/07/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"
#import "PPBarcodeDetailedData.h"

/**
 * Type of the barcode which BarDecoderRecognizer returnes
 */
typedef NS_ENUM(NSUInteger, PPBarDecoderBarcodeType){
    /** Code 128 */
    PPBarDecoderBarcodeTypeCode128,
    /** Code 39 */
    PPBarDecoderBarcodeTypeCode39
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Result of scanning with BarDecoder Recognizer
 *
 * Contains raw Barcode detailed data, barcode type, and methods for getting string representation of results.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPBarDecoderRecognizerResult : PPRecognizerResult

/**
 * Type of the barcode scanned
 *
 *  @return Type of the barcode
 */
- (PPBarDecoderBarcodeType)barcodeType;

/**
 * Flag indicating uncertain scanning data
 * E.g obtained from damaged barcode.
 */
- (BOOL)isUncertain;

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
 * This method uses NSString stringEncodingForData:encodingOptions:convertedString:usedLossyConversion: method for
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
 * Byte array with extended result of the scan, if available.
 */
- (NSData *)extendedData;

/**
 * Retrieves string content of the extended scanned data using guessed encoding.
 *
 * If you're 100% sure you know the exact encoding in the barcode, use stringUsingEncoding: method.
 * Otherwise stringUsingDefaultEncoding.
 *
 * This method uses NSString stringEncodingForData:encodingOptions:convertedString:usedLossyConversion: method for
 * guessing the encoding.
 *
 *  @return created string, or nil if encoding couldn't be found.
 */
- (NSString *)extendedStringUsingGuessedEncoding;

/**
 * Retrieves string content of the extended scanned data using given encoding.
 *
 *  @param encoding The encoding for the returned string.
 *
 *  @return String created from extendedData property, using given encoding
 */
- (NSString *)extendedStringUsingEncoding:(NSStringEncoding)encoding;

/**
 * Extended Raw barcode detailed result
 */
- (PPBarcodeDetailedData *)extendedRawData;

/**
 * Method which gives string representation for a given PPBarDecoderBarcodeType enum value.
 *
 *  @param type PPBarDecoderBarcodeType enum value
 *
 *  @return String representation of a given PPBarDecoderBarcodeType enum value.
 */
+ (NSString *)toTypeName:(PPBarDecoderBarcodeType)type;

@end

NS_ASSUME_NONNULL_END
