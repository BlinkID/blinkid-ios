//
//  PPModernOcrResultOverlaySubview.h
//  PhotoPayFramework
//
//  Created by Marko Mihovilić on 05/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPOverlaySubview.h"

@interface PPModernOcrResultOverlaySubview : PPOverlaySubview

@property (strong, nonatomic) UIColor *foregroundColor;

@property (strong, nonatomic) UIColor *tintColor;

@property (assign, nonatomic) BOOL shouldIgnoreFastResults;

@property (assign, nonatomic) CGFloat charFadeInDuration;

@end
