//
//  PPOcrLayoutMetadata.h
//  BlinkOcrFramework
//
//  Created by Jura on 17/04/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPMetadata.h"
#import "PPOcrLayout.h"

@interface PPOcrLayoutMetadata : PPMetadata

@property (nonatomic, strong) PPOcrLayout *layout;

@property (nonatomic, strong) NSString* layoutName;

@end
