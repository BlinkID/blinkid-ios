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

PP_CLASS_AVAILABLE_IOS(6.0) @interface PPMetadata : NSObject

@property (nonatomic, strong, readonly) NSString *name;

- (instancetype)initWithName:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
