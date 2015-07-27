//
//  PPObjectDetectionMetadata.h
//  BlinkOcrFramework
//
//  Created by Jura on 17/04/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPMetadata.h"

#import "PPDetectionStatus.h"

@interface PPObjectDetectionMetadata : PPMetadata

@property (nonatomic, assign) PPDetectionStatus status;

@property (nonatomic, strong) NSArray *detectedPoints;

@end
