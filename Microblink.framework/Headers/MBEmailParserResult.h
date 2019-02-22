//
//  MBEmailParserResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 09/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBParserResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * MBEmailParser is used for parsing emails
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBEmailParserResult : MBParserResult <NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Returns the recognized email or empty string if recognition failed.
 */
@property (nonatomic, nullable, strong, readonly) NSString *email;

@end

NS_ASSUME_NONNULL_END
