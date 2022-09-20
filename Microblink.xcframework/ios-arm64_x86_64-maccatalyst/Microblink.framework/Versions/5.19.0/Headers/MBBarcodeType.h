//
//  MBBarcodeResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 28/11/2017.
//

/**
 * Enumeration of possible barcode formats
 */
typedef NS_ENUM(NSInteger, MBBarcodeType) {
    MBBarcodeNone = 0,
    /** QR code */
    MBBarcodeTypeQR,
    /** Data Matrix */
    MBBarcodeTypeDataMatrix,
    /** UPCE */
    MBBarcodeTypeUPCE,
    /** UPCA */
    MBBarcodeTypeUPCA,
    /** EAN 8 */
    MBBarcodeTypeEAN8,
    /** EAN 13 */
    MBBarcodeTypeEAN13,
    /** Code 128 */
    MBBarcodeTypeCode128,
    /** Code 39 */
    MBBarcodeTypeCode39,
    /** ITF */
    MBBarcodeTypeITF,
    /** Code 39 */
    MBBarcodeTypeAztec,
    /** PDF 417 */
    MBBarcodeTypePdf417
};
