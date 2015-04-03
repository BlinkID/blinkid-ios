//
//  PPRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 03/11/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

struct RecognizerSettingsImpl;
typedef struct RecognizerSettingsImpl RecognizerSettingsImpl;

@interface PPRecognizerSettings : NSObject <NSCopying>

@property (nonatomic, readonly, assign) RecognizerSettingsImpl* settings;

- (instancetype)initWithSettings:(RecognizerSettingsImpl*)settings;

- (void)setEnabled:(BOOL)enabled;

- (BOOL)isEnabled;

+ (NSData*)dataFromFileWithName:(NSString*)name;

@end
