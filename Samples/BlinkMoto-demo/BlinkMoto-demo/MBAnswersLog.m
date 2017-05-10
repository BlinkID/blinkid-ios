//
//  MBAnswersLog.m
//  BlinkInput
//
//  Created by Jura on 17/09/16.
//  Copyright © 2016 MicroBlink. All rights reserved.
//

#import "MBAnswersLog.h"

#import <Crashlytics/Crashlytics.h>

@implementation MBAnswersLog

+ (void)logAppLaunchedWithAttributes:(nullable NSDictionary<NSString *, id> *)customAttributesOrNil {
    [Answers logCustomEventWithName:@"App launched" customAttributes:customAttributesOrNil];
}

+ (void)logScanStartedWithAttributes:(nullable NSDictionary<NSString *, id> *)customAttributesOrNil {
    [Answers logCustomEventWithName:@"Scan started" customAttributes:customAttributesOrNil];
}

+ (void)logScanFinishedWithAttributes:(nullable NSDictionary<NSString *,id> *)customAttributesOrNil {
    [Answers logCustomEventWithName:@"Scan finished" customAttributes:customAttributesOrNil];
}

+ (void)logScanCancelledWithAttributes:(nullable NSDictionary<NSString *,id> *)customAttributesOrNil {
    [Answers logCustomEventWithName:@"Scan cancelled" customAttributes:customAttributesOrNil];
}

@end
