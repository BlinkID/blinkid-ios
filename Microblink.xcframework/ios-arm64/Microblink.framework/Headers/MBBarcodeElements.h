// Created by Jura Skrlec on 16.02.2021..
// Copyright (c) 2021 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBBarcodeElementKey.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(9.0)
@interface MBBarcodeElements : NSObject<NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Flag that indicates if barcode elements is empty
*/
@property (nonatomic, readonly, assign) BOOL empty;

/**
 * Get value for wanted MBBarcodeElementKey
 *
 * @param key The input value representing one key from MBBarcodeElementKey enum
 * @return NSString The string for scanned barcode element key value
 */
- (NSString *)getValue:(MBBarcodeElementKey)key;

@end

NS_ASSUME_NONNULL_END
