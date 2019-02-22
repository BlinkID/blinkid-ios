//
//  MBAmountParserResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 09/03/2018.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBParserResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * MBAmountParser is used for extracting amount from OCR result
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBAmountParserResult : MBParserResult <NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Returns the recognized amount number or empty string if recognition failed.
 */
@property (nonatomic, nullable, strong, readonly) NSString *amount;

@end

NS_ASSUME_NONNULL_END
