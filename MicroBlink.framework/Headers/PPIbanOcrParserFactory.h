//
//  PPIbanOcrParserFactory.h
//  PhotoPayFramework
//
//  Created by Jura on 27/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

/**
 * Parses IBANs (International Bank Account Numbers)
 * @see https://en.wikipedia.org/wiki/International_Bank_Account_Number
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPIbanOcrParserFactory : PPOcrParserFactory

/**
 * Creates parser instance with default parametars.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Creating IBAN OCR parser with this initializer enables country code whitelist.
 * By default no country code whitelist is present and all IBANs are being scanned.
 * Adding a country code to whitelist will configure IBAN OCR parser to scan only those IBAN which begin with country codes present in
 * whitelist.
 */
- (instancetype)initWithCountryCodeWhitelist:(NSArray<NSString *> *)countryCodeWhitelist;

@end
