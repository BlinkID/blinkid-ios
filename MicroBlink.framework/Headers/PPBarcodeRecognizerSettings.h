//
//  PPBarcodeRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 26/06/2017.
//
//

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring Barcode Recognizer
 *
 * VarcodeRecognizer recognizer is used for scanning most of 1D barcode formats, and 2D format
 * such as Aztec, DataMatrix and QR code
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPBarcodeRecognizerSettings : PPRecognizerSettings

/**
 * Set this to YES to scan Aztec 2D barcodes
 *
 * Default: NO
 */
@property (nonatomic) BOOL scanAztec;

/**
 * Set this to YES to scan Code 128 1D barcodes
 *
 * Default: NO
 */
@property (nonatomic) BOOL scanCode128;

/**
 * Set this to YES to scan Code 39 1D barcodes
 *
 * Default: NO
 */
@property (nonatomic) BOOL scanCode39;

/**
 * Set this to YES to scan DataMatrix 2D barcodes
 *
 * Default: NO
 */
@property (nonatomic) BOOL scanDataMatrix;

/**
 * Set this to YES to scan EAN 13 barcodes
 *
 * Default: NO
 */
@property (nonatomic) BOOL scanEAN13;

/**
 * Set this to YES to scan EAN8 barcodes
 *
 * Default: NO
 */
@property (nonatomic) BOOL scanEAN8;

/**
 * Set this to YES to scan ITF barcodes
 *
 * Default: NO
 */
@property (nonatomic) BOOL scanITF;

/**
 * Set this to YES to scan QR barcodes
 *
 * Default: NO
 */
@property (nonatomic) BOOL scanQR;

/**
 * Set this to YES to scan UPCA barcodes
 *
 * Default: NO
 */
@property (nonatomic) BOOL scanUPCA;

/**
 * Set this to YES to scan UPCE barcodes
 *
 * Default: NO
 */
@property (nonatomic) BOOL scanUPCE;

/**
 * Set this to YES to allow scanning barcodes with inverted intensities
 * (i.e. white barcodes on black background)
 *
 * Default: NO
 *
 * @Warning: this option doubles frame processing time
 */
@property (nonatomic) BOOL scanInverse;

/**
 * Set this to YES to allow slower, but better image processing.
 *
 * Defailt: YES
 *
 */
@property (nonatomic, assign) BOOL useSlowerThoroughScan;


/**
 * Set manatee license key and unlock the aztec scanning feature.
 */
@property (nonatomic) NSString *manateeKey;

@end

NS_ASSUME_NONNULL_END
