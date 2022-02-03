// Created by Jura Skrlec on 18.05.2021..
// Copyright (c) 2021 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(9.0) MB_FINAL
@interface MBProductIntegrationInfo : NSObject

+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

@property (nonatomic, strong, readonly) NSString *product;
@property (nonatomic, strong, readonly) NSString *productVersion;
@property (nonatomic, strong, readonly) NSString *packageName;
@property (nonatomic, strong, readonly) NSString *platform;
@property (nonatomic, strong, readonly) NSString *osVersion;
@property (nonatomic, strong, readonly) NSString *device;
@property (nonatomic, strong, readonly) NSString *userId;
@property (nonatomic, strong, readonly) NSString *licensee;
@property (nonatomic, strong, readonly) NSString *licenseId;

@end

NS_ASSUME_NONNULL_END
