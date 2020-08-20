//
//  MBLogger.h
//  PhotoMathFramework
//
//  Created by Marko Mihovilić on 23/03/16.
//  Copyright © 2016 Microblink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"

typedef NS_ENUM(NSInteger, MBLogLevel) {
    MBLogLevelError,
    MBLogLevelWarning,
    MBLogLevelInfo,
    MBLogLevelDebug,
    MBLogLevelVerbose
};

@protocol MBLoggerDelegate <NSObject>

@optional

- (void)log:(MBLogLevel)level message:(const char *)message;
- (void)log:(MBLogLevel)level format:(const char *)format arguments:(const char *)arguments;

@end

MB_CLASS_AVAILABLE_IOS(8.0) @interface MBLogger : NSObject

@property (nonatomic) id<MBLoggerDelegate> delegate;

+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

- (void)disableMicroblinkLogging;

@end
