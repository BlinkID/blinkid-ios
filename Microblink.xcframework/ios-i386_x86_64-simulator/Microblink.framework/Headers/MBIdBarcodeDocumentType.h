//
//  MBIdBarcodeDocumentType.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 16/03/2020.
//

/**
 * Enumeration of possible barcode formats
 */
typedef NS_ENUM(NSInteger, MBIdBarcodeDocumentType) {
    MBIdBarcodeDocumentTypeNone = 0,
    /** AAMVACompliant */
    MBIdBarcodeDocumentTypeAAMVACompliant,
    /** Argentina ID */
    MBIdBarcodeDocumentTypeArgentinaID,
    /** Argentina DL */
    MBIdBarcodeDocumentTypeArgentinaDL,
    /** Colombia ID */
    MBIdBarcodeDocumentTypeColombiaID,
    /** Colombia DL */
    MBIdBarcodeDocumentTypeColombiaDL,
    /** Nigeria Voter ID */
    MBIdBarcodeDocumentTypeNigeriaVoterID,
    /** Nigeria DL */
    MBIdBarcodeDocumentTypeNigeriaDL,
    /** Panama ID */
    MBIdBarcodeDocumentTypePanamaID,
    /** South African ID */
    MBIdBarcodeDocumentTypeSouthAfricaID
};
