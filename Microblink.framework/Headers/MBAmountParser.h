//
//  MBAmountParser.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 09/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBParser.h"
#import "MBAmountParserResult.h"
#import "MBMicroblinkInitialization.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * MBAmountParser is used for extracting amount from OCR result
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBAmountParser : MBParser <NSCopying>

MB_INIT

/**
 * Amount parser result
 */
@property (nonatomic, strong, readonly) MBAmountParserResult *result;

/**
 * Indicates whether negative values are accepted as valid amounts.
 * Setting this to YES can yield to more false positives.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL allowNegativeAmounts;

/**
 * Indicates whether amounts with space separators between groups of digits(thousands) are allowed.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL allowSpaceSeparators;

/**
 * Indicates whether amounts without decimal are accepted as valid. For example 1.465 is
 * accepted as valid amount, but 1465 is not, unless this is set to YES.
 * Setting this to {@code true} can yield to more false positives
 * because any set of consequent digits can represent valid amount.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL allowMissingDecimals;
/**
 * Indicates whether Arabic-Indic mode is enabled. In Arabic-Indic mode parser can recognize
 * only amounts which consist of Arabic-Indic digits and decimal separator.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL arabicIndicMode;

@end

NS_ASSUME_NONNULL_END
