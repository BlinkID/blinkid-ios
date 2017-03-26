//
//  PPAztecRecognizerResult.h
//  BlinkIDDev
//
//  Created by Jura on 25/03/2017.
//  Copyright (c) 2017 MicroBlink Ltd. All rights reserved.

#import "PPRecognizerResult.h"

/**
 * Result of scanning with Aztec Recognizer
 *
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPAztecRecognizerResult : PPRecognizerResult

/**
 * Byte array with result of the scan
 */
@property (nonatomic, readonly, strong, nullable) NSData *barcodeData;

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
@property (nonatomic, readonly, strong, nullable) NSString *barcodeStringWithGuessedEncoding;

/**
 * Retrieves string content of the scanned data using given encoding.
 *
 *  @param encoding The encoding for the returned string.
 *
 *  @return String created from data property, using given encoding
 */
- (NSString *_Nullable)barcodeStringUsingEncoding:(NSStringEncoding)encoding;

/**
 * Location of the barcode in the coordinate system of the image
 */
@property (nonatomic, readonly, strong, nullable) PPQuadrangle *barcodeLocation;

@end
