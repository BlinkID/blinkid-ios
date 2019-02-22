//
//  MBIbanParser.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 09/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBParser.h"
#import "MBIbanParserResult.h"
#import "MBMicroblinkInitialization.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * MBAmountParser that can extract IBAN (International Bank Account Number) from OCR result.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBIbanParser : MBParser <NSCopying>

MB_INIT

/**
 * Iban parser result
 */
@property (nonatomic, strong, readonly) MBIbanParserResult *result;

/**
 * Should prefix (country code) always be returned.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL alwaysReturnPrefix;

/**
 * Set of allowed country codes. If whitelist is defined, only IBANs with defined country codes
 * will be recognized. For example to allow only Croatian IBANs define whitelist with country
 * code "HR". If whitelist is not defined, or if it is set to nil, all valid IBANs will
 * be returned.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *countryCodeWhitelist;

@end

NS_ASSUME_NONNULL_END
