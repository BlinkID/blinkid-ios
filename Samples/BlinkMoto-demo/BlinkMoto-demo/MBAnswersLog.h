//
//  MBAnswersLog.h
//  BlinkInput
//
//  Created by Jura on 17/09/16.
//  Copyright © 2016 MicroBlink. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MBAnswersLog : NSObject

+ (void)logAppLaunchedWithAttributes:(nullable NSDictionary<NSString *, id> *)customAttributesOrNil;

+ (void)logScanStartedWithAttributes:(nullable NSDictionary<NSString *, id> *)customAttributesOrNil;

+ (void)logScanFinishedWithAttributes:(nullable NSDictionary<NSString *, id> *)customAttributesOrNil;

+ (void)logScanCancelledWithAttributes:(nullable NSDictionary<NSString *, id> *)customAttributesOrNil;

@end
