//
//  MBRegexParserResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 15/03/2018.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBParserResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * MBDateParser that can extract date from OCR result.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBRegexParserResult : MBParserResult <NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Returns string containing parsed OCR result according to given regular expression.
 */
@property (nonatomic, strong, readonly) NSString *parsedString;

@end

NS_ASSUME_NONNULL_END
