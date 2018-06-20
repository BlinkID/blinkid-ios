//
//  MBParser.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 06/03/2018.
//

#import "MBMicroBlinkDefines.h"
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

@end

NS_ASSUME_NONNULL_END
