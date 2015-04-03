//
//  PPTextMetadata.h
//  PhotoPayFramework
//
//  Created by Jura on 02/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPMetadata.h"

typedef NS_ENUM(NSUInteger, PPTextMetadataType) {
    PPTextMetadataTypeTxt,
    PPTextMetadataTypeXml,
    PPTextMetadataTypeJson,
};

@interface PPTextMetadata : PPMetadata

@property (nonatomic, strong) NSString* text;

@property (nonatomic, assign) PPTextMetadataType type;

- (instancetype)initWithName:(NSString *)name
                        text:(NSString*)text;

- (instancetype)initWithName:(NSString *)name
                        text:(NSString*)text
                        type:(PPTextMetadataType)type;

@end
