//
//  MBTopUpParser.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 09/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBParser.h"
#import "MBTopUpParserResult.h"
#import "MBMicroblinkInitialization.h"

/**
 * Enumeration of posibble top up presets
 */
typedef NS_ENUM(NSUInteger, MBTopUpPreset) {
    
    /** For top ups which begin with <b>*123*</b> prefix and USSD code length is <b>14</b> */
    MBTopUp123,
    
    /** For top ups which begin with <b>*103*</b> and USSD code length is <b>14</b> */
    MBTopUp103,
    
    /** For top ups which begin with <b>*131*</b> and USSD code length is <b>13</b> */
    MBTopUp131,
    
    /** For top ups with any prefix and USSD code length from interval {[13, 16]} */
    MBTopUpGeneric,
    
};

NS_ASSUME_NONNULL_BEGIN

/**
 * MBTopUpParser is used for parsing Top Up numbers
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBTopUpParser : MBParser <NSCopying>

MB_INIT

/**
 * Top Up parser result
 */
@property (nonatomic, strong, readonly) MBTopUpParserResult *result;

/**
 * Indicates whether USSD codes without prefix are allowed.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL allowNoPrefix;

/**
 * Indicates whether digts prefix and # at the end of scanned USSD code will
 * be returned.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnCodeWithoutPrefix;

/**
 * Sets the top up prefix and USSD code length based on the given MBTopUpPreset. Only
 * top ups with the chosen prefix and USSD code length in form will be parsed.
 * If top up prefix and USSD code length is not set, top ups with any prefix and USSD code
 * length can be parsed.
 * @param topUpPreset that determines top up prefix and USSD code length that will be set.
 */
- (void)setTopUpPreset:(MBTopUpPreset)topUpPreset;

/**
 * Sets the given top up prefix and USSD code length. Only top ups with the chosen prefix and
 * USSD code length in form {@code *<prefixString>*<USSDCodeLength digits>#} will be parsed.
 * If top up prefix and USSD code length is not set, top ups with any prefix and USSD code
 * length can be parsed.
 * @param prefix top up prefix
 * @param ussdCodeLength length of the USSD code
 */
- (void)setPrefix:(NSString *)prefix andUssdCodeLength:(NSInteger)ussdCodeLength;

@end

NS_ASSUME_NONNULL_END
