//
//  PPImageMetadata.h
//  PhotoPayFramework
//
//  Created by Jura on 02/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPMetadata.h"
#import <UIKit/UIKit.h>

@interface PPImageMetadata : PPMetadata

@property (nonatomic, assign, readonly) UIImageOrientation orientation;

- (instancetype)initWithName:(NSString *)name
                 orientation:(UIImageOrientation)orientation;

- (UIImage*)image;

@end
