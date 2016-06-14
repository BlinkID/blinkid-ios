//
//  PPPdf417RecognizerResult.h
//  Pdf417Framework
//
//  Created by Jura on 11/07/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"
#import "PPBarcodeDetailedData.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Result of scanning with PDF417 Recognizer
 *
 * Contains raw Barcode detailed data, and methods for getting string representation of results.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPPdf417RecognizerResult : PPRecognizerResult

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
 * Flag indicating uncertain scanning data
 * E.g obtained from damaged barcode.
 */
- (BOOL)isUncertain;

/**
 * Returns the location of the barcode on the original image. The location is a quadrangle, which is defined
 * with upper left, upper right, lower left and lower right corner.
 *
 * Points are given in image coordinate system
 * (0, 0) - top left point on the image, (width, height) 
 * bottom right point on the image
 *
 *  @return location of the barcode on the original image.
 *
 *  @note - to get the points in NSArray use PPQuadrangle's toPointsArray method.
 */
- (PPQuadrangle *)locationOnImage;

@end

NS_ASSUME_NONNULL_END