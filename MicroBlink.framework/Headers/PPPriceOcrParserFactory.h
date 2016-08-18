//
//  PPPriceOcrParserFactory.h
//  PhotoPayFramework
//
//  Created by Jura on 27/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPOcrParserFactory.h"

/**
 *  Parses various transaction amount formats on invoices.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPPriceOcrParserFactory : PPOcrParserFactory

@property (nonatomic) BOOL arabicIndicModeEnabled;

@property (nonatomic) BOOL allowMissingDecimals;

@property (nonatomic) BOOL allowSpaceSeparators;

@property (nonatomic) BOOL allowNegativeAmounts;

@property (nonatomic) BOOL expectCurrencySymbol;

@property (nonatomic) BOOL expectAsterixOrEqualsPrefix;

@property (nonatomic) int idealNumberOfDigits;

@end
