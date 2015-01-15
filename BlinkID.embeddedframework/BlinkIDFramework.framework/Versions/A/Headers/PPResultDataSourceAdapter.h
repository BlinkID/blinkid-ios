//
//  PPResultDataSourceAdapter.h
//  PhotoPayFramework
//
//  Created by Jura on 28/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPBaseResult.h"

@interface PPResultDataSourceAdapter : NSObject

@property (nonatomic, strong) PPBaseResult* result;

@property (nonatomic, strong) NSString* title;

@property (nonatomic, strong) NSMutableArray* names;

@property (nonatomic, strong) NSMutableArray* keys;

@property (nonatomic, strong) NSMutableArray* labels;

@property (nonatomic, strong) NSMutableArray* values;

- (instancetype)initWithResult:(PPBaseResult*)result;

@end
