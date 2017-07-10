//
//  PPBarcodeRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 26/06/2017.
//
//

#import "PPRecognizerResult.h"
#import "PPBarcodeDetailedData.h"

/**
 * Type of the barcode which BarDecoderRecognizer returnes
 */
typedef NS_ENUM(NSUInteger, PPBarcodeType) {
    PPBarcodeNone = 0,
    /** QR code */
    PPBarcodeTypeQR,
    /** Data Matrix */
    PPBarcodeTypeDataMatrix,
    /** UPCE */
    PPBarcodeTypeUPCE,
    /** UPCA */
    PPBarcodeTypeUPCA,
    /** EAN 8 */
    PPBarcodeTypeEAN8,
    /** EAN 13 */
    PPBarcodeTypeEAN13,
    /** Code 128 */
    PPBarcodeTypeCode128,
    /** Code 39 */
    PPBarcodeTypeCode39,
    /** ITF */
    PPBarcodeTypeITF,
    /** Code 39 */
    PPBarcodeTypeAztec
};


/**
 * Result of scanning with Barcode Recognizer
 *
 * Contains raw Barcode detailed data, barcode type, and methods for getting string representation of results.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPBarcodeRecognizerResult : PPRecognizerResult

/**
 * Type of the barcode scanned
 *
 *  @return Type of the barcode
 */
- (PPBarcodeType)barcodeType;

/**
 * Byte array with result of the scan
 */
- (NSData *_Nullable)data;

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
- (NSString *_Nullable)stringUsingGuessedEncoding;

/**
 * Retrieves string content of the scanned data using given encoding.
 *
 *  @param encoding The encoding for the returned string.
 *
 *  @return String created from data property, using given encoding
 */
- (NSString *_Nullable)stringUsingEncoding:(NSStringEncoding)encoding;

/**
 * Raw barcode detailed result
 */
- (PPBarcodeDetailedData *_Nullable)rawData;

/**
 * Method which gives string representation for a given PPBarcodeType enum value.
 *
 *  @param type PPBarcodeType enum value
 *
 *  @return String representation of a given PPBarcodeType enum value.
 */
+ (NSString *_Nonnull)toTypeName:(PPBarcodeType)type;

@end
