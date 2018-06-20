//
//  MBUsdlRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 03/01/2018.
//

#import <Foundation/Foundation.h>

#import "MBMicroBlinkDefines.h"
#import "MBRecognizerResult.h"
#import "MBUsdlKeys.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A recognizer that can scan PDF417 2D barcodes.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBUsdlRecognizerResult : MBRecognizerResult<NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Byte array with result of the scan
 */
- (NSData *_Nullable)data;

/**
 * Flag indicating uncertain scanning data
 * E.g obtained from damaged barcode.
 */
- (BOOL)isUncertain;

/**
 * Returns a string value for a given key.
 *
 *  @param usdlKey field key
 *
 *  @return value for a given key
 */
- (NSString *_Nullable)getField:(MBUsdlKeys)usdlKey;

/**
* Array of elements that are not part of AAMVA standard and are specific to each US state.
* If no specific elements existed inside 2D barcode, this is an empty array. Otherwise,
* this array contains list of state-specific elements in the same order as given inside
* barcode.
* NOTE: Size of this array is both state-specific and barcode-specific. Each US state has
* ability to arbitrarily define size and contents of these elements. You can obtain the
* as a parameter.
*/
- (NSArray<NSString *> *_Nullable)optionalElements;

@end

NS_ASSUME_NONNULL_END
