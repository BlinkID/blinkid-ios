//
//  PPMetadata.h
//  PhotoPayFramework
//
//  Created by Jura on 02/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for outputting various data via 'didOutputMetadata:' method
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPMetadata : NSObject

/**
 * Unique metadata name/Id
 */
@property (nonatomic, strong, readonly) NSString *name;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithName:(NSString *)name NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
