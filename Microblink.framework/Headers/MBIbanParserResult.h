//
//  MBIbanParserResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 09/03/2018.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBParserResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * MBAmountParser that can extract IBAN (International Bank Account Number) from OCR result.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBIbanParserResult : MBParserResult <NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Returns the rparsed IBAN or empty string if recognition failed.
 */
@property (nonatomic, nullable, strong, readonly) NSString *iban;

@end

NS_ASSUME_NONNULL_END
