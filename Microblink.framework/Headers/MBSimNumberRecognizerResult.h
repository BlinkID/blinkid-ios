//
//  MBSimNumberRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 21/11/2017.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer that can perform recognition of barcodes on SIM packaging.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSimNumberRecognizerResult : MBRecognizerResult<NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Returns the recognized SIM number from barcode or empty string if recognition failed.
 */

@property (nonatomic, nullable, strong, readonly) NSString *simNumber;

@end

NS_ASSUME_NONNULL_END
