//
//  MBParser.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 06/03/2018.
//

#import "MBMicroblinkDefines.h"
#import "MBEntity.h"
#import "MBParserResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all parsers
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBParser : MBEntity

/**
 * Base parser result
 */
@property (nonatomic, readonly, weak) MBParserResult *baseResult;

/**
 * Defines/returns whether the parser configured with this parser settings object will be required or optional.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL required;

@end

NS_ASSUME_NONNULL_END
