//
//  MBParserResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 06/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

/**
 * Enumeration of posibble parser result state
 */
typedef NS_ENUM(NSUInteger, MBParserResultState) {
    
    /**
     *  Empty
     */
    MBParserResultStateEmpty,
    
    /**
     *  Uncertain
     */
    MBParserResultStateUncertain,
    
    /**
     *  Valid
     */
    MBParserResultStateValid,
    
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all parser results
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBParserResult : NSObject

MB_INIT_UNAVAILABLE

@property (nonatomic, assign, readonly) MBParserResultState resultState;

@end

NS_ASSUME_NONNULL_END
