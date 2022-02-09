//
// MBIDBarcodeRecognizer.h
//
// Created by juraskrlec on 16/03/2020
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBIdBarcodeRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* The ID Barcode Recognizer is used for scanning ID Barcode.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBIdBarcodeRecognizer : MBRecognizer<NSCopying>

MB_INIT

/**
 * Result of scanning IDBarcodeRecognizer
 */
@property (nonatomic, strong, readonly) MBIdBarcodeRecognizerResult *result;

@end

NS_ASSUME_NONNULL_END
