//
//  PPMetadata.h
//  PhotoPayFramework
//
//  Created by Jura on 02/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MBMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for outputting various data via 'didOutputMetadata:' method
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMetadata : NSObject

/**
 * Unique metadata name/Id
 */
@property (nonatomic, strong, readonly) NSString *name;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithName:(NSString *)name NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
