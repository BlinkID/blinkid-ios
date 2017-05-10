//
//  PPOcrParseElement.m
//  BlinkOCR
//
//  Created by Jura on 02/03/15.
//  Copyright (c) 2015 PhotoPay. All rights reserved.
//

#import "PPScanElement.h"

@interface PPScanElement ()

@end

@implementation PPScanElement

- (instancetype)initWithIdentifier:(NSString *)identifier parserFactory:(PPOcrParserFactory *)factory {
    self = [super init];
    if (self) {
        _identifier = identifier;
        _factory = factory;
        _keyboardType = UIKeyboardTypeDefault;
        _scanningRegionHeight = 0.09f;
        _scanningRegionWidth = 0.7f;
    }
    return self;
}

- (void)encodeWithCoder:(NSCoder *)encoder {
    //Encode properties, other class variables, etc
    [encoder encodeObject:self.identifier forKey:@"id"];
    [encoder encodeObject:NSStringFromClass([self.factory class]) forKey:@"factory"];
    [encoder encodeObject:self.localizedTextfieldText forKey:@"textfield"];
    [encoder encodeObject:self.localizedTooltip forKey:@"tooltip"];
    [encoder encodeObject:self.localizedTitle forKey:@"title"];
    [encoder encodeBool:self.scanned forKey:@"scanner"];
    [encoder encodeBool:self.edited forKey:@"edited"];
    [encoder encodeObject:self.value forKey:@"value"];
    [encoder encodeFloat:self.scanningRegionHeight forKey:@"height"];
    [encoder encodeFloat:self.scanningRegionWidth forKey:@"width"];
}

- (id)initWithCoder:(NSCoder *)encoder {
    if((self = [super init])) {
        _identifier=[encoder decodeObjectForKey:@"id"];

        NSString *factory=[encoder decodeObjectForKey:@"factory"];
        _factory = [[NSClassFromString(factory) alloc] init];
        _localizedTextfieldText=[encoder decodeObjectForKey:@"textfield"];
        _localizedTooltip=[encoder decodeObjectForKey:@"tooltip"];
        _localizedTitle=[encoder decodeObjectForKey:@"title"];
        _scanned=[encoder decodeBoolForKey:@"scanner"];
        _edited=[encoder decodeBoolForKey:@"edited"];
        _value=[encoder decodeObjectForKey:@"value"];
        _scanningRegionHeight=[encoder decodeFloatForKey:@"height"];
        _scanningRegionWidth=[encoder decodeFloatForKey:@"width"];
    }
    return self;
}

@end
