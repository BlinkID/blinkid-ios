//
//  MBDateParser.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 12/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBParser.h"
#import "MBDateParserResult.h"
#import "MBMicroblinkInitialization.h"

/**
 * Available date formats for date parser. To activate parsing of dates with month names in
 * English, use formats which contain MONTH, e.g. MBDateFormatDDMONTHYYYY.
 * Month names in uppercase and short month names are supported (for example March and Mar).
 */
typedef NS_ENUM(NSUInteger, MBDateFormat) {
    MBDateFormatDDMMYYYY = 0,
    MBDateFormatDDMMYY,
    MBDateFormatMMDDYYYY,
    MBDateFormatMMDDYY,
    MBDateFormatYYYYMMDD,
    MBDateFormatYYMMDD,
    MBDateFormatDDMONTHYYYY,
    MBDateFormatDDMONTHYY,
    MBDateFormatMONTHDDYYYY,
    MBDateFormatMONTHDDYY,
    MBDateFormatYYYYMONTHDD,
    MBDateFormatYYMONTHDD
};

typedef NSArray<NSNumber *> MBDateFormatArray;
typedef NSArray<NSString *> MBDateSeparatorCharsArray;

NS_ASSUME_NONNULL_BEGIN

/**
 * MBDateParser that can extract date from OCR result.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBDateParser : MBParser <NSCopying>

MB_INIT

/**
 * Date parser result
 */
@property (nonatomic, strong, readonly) MBDateParserResult *result;

/**
 * Specifies the date formats that will be accepted by date parser. By default, all available
 * numeric date formats from MBDateFormat enum will be accepted (all formats in which month
 * is numeric).
 * Array of expected date formats, if it is nil or empty, date formats will be set to default value.
 */
- (void)setDateFormats:(nonnull MBDateFormatArray *)dateFormats;

/**
 * Specifies the date separator characters between date parts (day, month, year) that will be
 * accepted by date parser. By default, separator characters are: '.', '/' and '-'.
 * If it is nil or empty, date separator characters will be use default value.
 */
- (void)setDateSeparatorChars:(nonnull MBDateSeparatorCharsArray *)dateSeparatorChars;

@end

NS_ASSUME_NONNULL_END
