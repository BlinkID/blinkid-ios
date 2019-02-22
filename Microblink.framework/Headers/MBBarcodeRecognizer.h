//
//  MBBarcodeRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 28/11/2017.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBRecognizer.h"
#import "MBBarcodeRecognizerResult.h"
#import "MBMicroblinkInitialization.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * MBBarcodeRecognizer is used for scanning most of 1D barcode formats, and 2D format
 * such as Aztec, DataMatrix and QR code
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBarcodeRecognizer : MBRecognizer<NSCopying>

MB_INIT

/**
 * Barcode recognizer results
 */
@property (nonatomic, strong, readonly) MBBarcodeRecognizerResult *result;

/**
 * Set this to YES to scan Aztec 2D barcodes
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanAztecCode;

/**
 * Set this to YES to scan Code 128 1D barcodes
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanCode128;

/**
 * Set this to YES to scan Code 39 1D barcodes
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanCode39;

/**
 * Set this to YES to scan DataMatrix 2D barcodes
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanDataMatrix;

/**
 * Set this to YES to scan EAN 13 barcodes
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanEan13;

/**
 * Set this to YES to scan EAN8 barcodes
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanEan8;

/**
 * Set this to YES to scan ITF barcodes
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanItf;

/**
 * Set this to YES to scan QR barcodes
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanQrCode;

/**
 * Set this to YES to scan UPCA barcodes
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanUpca;

/**
 * Set this to YES to scan UPCE barcodes
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanUpce;

/**
 * Set this to YES to scan Pdf417 barcodes
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanPdf417;

/**
 * Set this to YES to allow slower, but better image processing.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL slowerThoroughScan;

/**
* Allow enabling the autodetection of image scale when scanning barcodes.
* If set to true, prior reading barcode, image scale will be
* corrected. This enabled correct reading of barcodes on high
* resolution images but slows down the recognition process.
*
* NOTE: This setting is applied only for Code39 and Code128 barcode scanning.
*
 * Default: YES
*/
@property (nonatomic, assign) BOOL autoScaleDetection;

/**
* Enable reading code39 barcode contents as extended data. For more information about code39
* extended data (a.k.a. full ASCII mode), see https://en.wikipedia.org/wiki/Code_39#Full_ASCII_Code_39
*
* Default: NO
*/
@property (nonatomic, assign) BOOL readCode39AsExtendedData;

/**
 * Set this to YES to allow scanning barcodes with inverted intensities
 * (i.e. white barcodes on black background)
 *
 * NOTE: this options doubles the frame processing time
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanInverse;

/**
 * Set this to YES to scan even barcode not compliant with standards
 * For example, malformed PDF417 barcodes which were incorrectly encoded
 *
 * Use only if necessary because it slows down the recognition process
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL scanUncertain;

/**
 * Set this to YES to scan barcodes which don't have quiet zone (white area) around it
 *
 * Use only if necessary because it slows down the recognition process
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL nullQuietZoneAllowed;

@end

NS_ASSUME_NONNULL_END
