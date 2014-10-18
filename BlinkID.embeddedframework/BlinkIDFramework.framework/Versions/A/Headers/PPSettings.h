//
//  SettingsKeys.h
//  PhotoPayFramework
//
//  Created by Jurica Cerovec on 6/5/12.
//  Copyright (c) 2012 Racuni.hr. All rights reserved.
//

#ifndef PhotoPayFramework_SettingsKeys_h
#define PhotoPayFramework_SettingsKeys_h

/** You should put a License key here to remove "noncommercial" message on camera view */
extern NSString* const kPPLicenseKey;
/** If you have got license key that supports multiple bundle IDs, then besides license key, you need to provide license key owner to which license key is bound */
extern NSString* const kPPLicenseOwner;

/** PhotoPay setup. What we recognize */

/** If YES, recognition of Hungarian slips is performed */
extern NSString* const kPPRecognizeHungarianSlipsKey;
/** If YES, recognition of Croatian slips is performed */
extern NSString* const kPPRecognizeCroatianSlipsKey;
/** If YES, recognition of Croatian PDF417 barcodes is performed */
extern NSString* const kPPRecognizeCroatianPdf417Key;
/** If YES, recognition of Croatian QR Codes is performed */
extern NSString* const kPPRecognizeCroatianQRCodeKey;
/** If YES, recognition of Slovenian slips is performed */
extern NSString* const kPPRecognizeSlovenianSlipsKey;
/** If YES, recognition of Austrian slips is performed */
extern NSString* const kPPRecognizeAustrianSlipsKey;
/** If YES, recognition of photbull barcodes is performed */
extern NSString* const kPPRecognizePhotoBullKey;
/** If YES, recognition of German slips is performed */
extern NSString* const kPPRecognizeGermanSlipsKey;
/** If YES, ocr only recognition is performed */
extern NSString* const kPPRecognizeOcrOnly;
/** If YES, recognition of belgian slips is performed */
extern NSString* const kPPRecognizeBelgianSlipsKey;
/** If YES, recognition of dutch slips is performed */
extern NSString* const kPPRecognizeDutchSlipsKey;
/** If YES, recognition of dutch ocr line is performed */
extern NSString* const kPPRecognizeDutchOcrLineKey;
/** If YES, recognition of UK giro slips is performed */
extern NSString* const kPPRecognizeUKGiroSlipsKey;
/** If YES, recognition of UK barcodes is performed */
extern NSString* const kPPRecognizeUKBarcodes;
/** If YES, recognition of Kosovar slips is performed */
extern NSString* const kPPRecognizeKosovoSlipsKey;
/** If YES, recognition of Kosovar barcodes on payment slips is performed */
extern NSString* const kPPRecognizeKosovoBarcodesKey;
/** If YES, recognition of PhotoMath is performed */
extern NSString* const kPPRecognizePhotoMath;
/** If YES, recognition of ID cards with MRTD is performed */
extern NSString* const kPPRecognizeIdCardMrtd;
/** If YES, recognition of USDL barcodes is performed */
extern NSString* const kPPRecognizeUSDLKey;

/** Keys for OCR engine setup */

/** You must provide a filename to Ocr Patterns file */
extern NSString* const kPPOcrPatternsFile;
/** You must provide a filename to the license file */
extern NSString* const kPPOcrLicenseFile;
/** You don't have to provide a filename to Ocr Keywords file */
extern NSString* const kPPOcrKeywordsFile;
/** You don't have to provide a filename to Ocr Dictionary file */
extern NSString* const kPPOcrDictionaryFile;
/** You have to provide filename for blz list for german recognition */
extern NSString* const kPPBlzListFile;
/** You have to provide model file to uze ZICER ocr */
extern NSString* const kPPZicerModelFile;

/** Keys for math solving engine */

/** You have to provide rules file to use PhotoMath */
extern NSString* const kPPPhotoMathRulesFile;

/** Path to austrian dictionary file */
extern NSString* const kPPPhotoPayAusDictionaryPath;
/** Path to austrian dictionary confusions file */
extern NSString* const kPPPhotoPayAusConfusionsPath;
/** Path to german dictionary file */
extern NSString* const kPPPhotoPayDeDictionaryPath;
/** Path to german dictionary confusions file */
extern NSString* const kPPPhotoPayDeConfusionsPath;
/** Path to slovenian dictionary file */
extern NSString* const kPPPhotoPaySloDictionaryPath;
/** Path to slovenian dictionary confusions file */
extern NSString* const kPPPhotoPaySloConfusionsPath;
/** Path to croatian dictionary file */
extern NSString* const kPPPhotoPayCroDictionaryPath;
/** Path to croatian dictionary confusions file */
extern NSString* const kPPPhotoPayCroConfusionsPath;

/** Language setup */
extern NSString* const kPPLanguage;

/** Keys for camera setup */

/** If YES, 640x480 quality video is used. */
extern NSString* const kPPUseVideoPreset640x480;
/** If YES, High quality video is used. This is the default. */
extern NSString* const kPPUseVideoPresetHigh;
/** If YES, Highest video resolution is used. */
extern NSString* const kPPUseVideoPresetHighest;
/** If YES, Photo Quality video is used: Note: use this only if you don't have other choice.
 That's because camera resolution in Photo preset is equal to screen resolution. */
extern NSString* const kPPUseVideoPresetPhoto;
/** If YES, Still images are used (still beta) */
extern NSString* const kPPUseStillImage;

/** If YES, uncertain barcodes will also be scanned */
extern NSString* const kPPScanUncertainBarcodes;
/** If YES; barcodes with nonexisting quite zone will be scanned */
extern NSString* const kPPAllowNullQuietZone;
/** If YES; inverted barcodes will be scanned */
extern NSString* const kPPAllowInverseBarcodes;
/**
 Use automatic scale detection feature.
 This normally should not be used.
 The only situation where this helps in getting better scanning results is when using kPPUseVideoPresetPhoto on iPad devices.
 Video preview resoution of 2045x1536 in that case is very large and autoscale helps.
 */
extern NSString* const kPPUseAutoscaleDetection;

/** If YES, force PhotoPay to read croatian payment description, if available */
extern NSString* const kPPScanPaymentDescription;
/** If YES, force PhotoPay to read croatian payment description, if available */
extern NSString* const kPPScanCroPaymentDescription;
/** If YES, force PhotoPay to read croatian payer name, if available */
extern NSString* const kPPScanCroPayerName;
/** If YES, sanitization is performed on scanned data */
extern NSString* const kPPUseSanitization;

/**
 Allow scanning of multiple data types on the same image
 For example, if a barcode and OCR text exists on the same image, when this parameter
 is turned on, you can get both results.
 */
extern NSString* const kPPOutputMultipleResults;


/** Presentation of help screens */

/** If YES, Help screens are never presented automatically. */
extern NSString* const kPPPresentHelpNever;
/** If YES, Help screens are presented automatically only on first run after install. This is default */
extern NSString* const kPPPresentHelpOnFirstRun;
/** If YES, Help screens are presented automatically only on every run of the app */
extern NSString* const kPPPresentHelpOnEveryRun;


/** Barcode types */

/** When an object under this key is boolean true, pdf417 is scanned */
extern NSString* const kPPRecognizePdf417Key;
/** When an object under this key is boolean true, Qr code is scanned */
extern NSString* const kPPRecognizeQrCodeKey;
/** When an object under this key is boolean true, All 1D barcodes are enabled */
extern NSString* const kPPRecognize1DBarcodesKey;
/** When an object under this key is boolean true, Code128 barcode is scanned */
extern NSString* const kPPRecognizeCode128Key;
/** When an object under this key is boolean true, Code39 barcode is scanned */
extern NSString* const kPPRecognizeCode39Key;
/** When an object under this key is boolean true, EAN13 barcode is scanned */
extern NSString* const kPPRecognizeEAN13Key;
/** When an object under this key is boolean true, EAN8 barcode is scanned */
extern NSString* const kPPRecognizeEAN8Key;
/** When an object under this key is boolean true, ITF barcode is scanned */
extern NSString* const kPPRecognizeITFKey;
/** When an object under this key is boolean true, UPCA barcode is scanned */
extern NSString* const kPPRecognizeUPCAKey;
/** When an object under this key is boolean true, UPCE barcode is scanned */
extern NSString* const kPPRecognizeUPCEKey;
/** When an object under this key is boolean true, Aztec barcode is scanned */
extern NSString* const kPPRecognizeAztecKey;
/** When an object under this key is boolean true, Data Matrix barcode is scanned */
extern NSString* const kPPRecognizeDataMatrixKey;

/** Presentation style */

/** If YES, PhotoPay's CameraViewController is presented modally. */
extern NSString* const kPPPresentModal;

/**
 Set a float value between 0 and 1 which denotes the starting position of the scan window
 This is primarily used for scanning OCR lines (like in Dutch payslips)
 */
extern NSString* const kPPScanWindowPositionInPercentage;

/** 
 Set a float value between 0 and 1 which denotes the height of the scan window
 This is primarily used for scanning OCR lines (like in Dutch payslips)
 */
extern NSString* const kPPScanWindowHeightInPercentage;

/**
 Set a float between 0 and 0.5 which denotes the size of the QR code scanning
 rectangle on UK payslip scanning UI
 */
extern NSString* const kPPQRScanWindowSizeInPercentage;

/** Work style */

/** If YES, only detection (not recognition) is performed. Default is NO */
extern NSString* const kPPPerformDetectionOnlyKey;
/** If YES, debug info is presented on screen. Default is NO */
extern NSString* const kPPPresentDebugInfoKey;
/** If YES, toast-like status messages are presented on screen. Default is NO */
extern NSString* const kPPPresentToastMessages;
/** Determines if overlay view should autorotate */
extern NSString* const kPPOverlayShouldAutorotate;
/** Under this key the Color of the PhotoPay skin is stored */
extern NSString* const kPPSkinColor;
/** Under this key the is stored information whether viewfinder is moveable */
extern NSString* const kPPViewfinderMoveable;
/** Under this key the is stored information whether ocr results should be shown */
extern NSString* const kPPShowOcrResults;

/** Saving of images */
/** Debug image saving */
extern NSString* const kPPSaveBgrImageKey;
extern NSString* const kPPSaveGrayscaleImageKey;
extern NSString* const kPPSaveDewarpedImageKey;
extern NSString* const kPPSaveDetectionImageKey;
extern NSString* const kPPSaveSuccessImageKey;
extern NSString* const kPPSaveOcrKey;
extern NSString* const kPPSavePaymentData;
extern NSString* const kPPSaveDeviceInfo;

/** Sound file which will be played on successful recognition */
extern NSString* const kPPSoundFile;

/** If YES, Front facing camera of the device will be used */
extern NSString* const kPPUseFrontFacingCamera;

/** Disable only near autofocus hint on iOS7+ */
extern NSString* const kPPAutofocusFull;

/** Partial recognition timeout interval */

/** Seths the number of seconds before recognition times out. Default is 10. */
extern NSString* const kPPPartialRecognitionTimeoutInterval;

/** UIImage for image recongition is passed here */
extern NSString* const kPPRecognizeImage;

/** Setting for segment scanner */
extern NSString* const kPPSegmentScannerType;

/** Segment scanner type enum */
typedef NS_ENUM(NSUInteger, PPSegmentScannerType) {
    PPSegmentScannerTypeNone,
    PPSegmentScannerTypeIban,
    PPSegmentScannerTypeAmount,
    PPSegmentScannerTypeUrl,
    PPSegmentScannerTypeEmailAddress,
    PPSegmentScannerTypeCroatianPaymentReference,
};

/**
 Abstract class reprezenting general settings objects
 */
@interface PPSettings : NSObject

@end

#endif
