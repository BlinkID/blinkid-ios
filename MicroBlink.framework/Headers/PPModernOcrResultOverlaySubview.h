//
//  PPModernOcrResultOverlaySubview.h
//  PhotoPayFramework
//
//  Created by Marko Mihovilić on 05/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPOverlaySubview.h"

NS_ASSUME_NONNULL_BEGIN

PP_CLASS_AVAILABLE_IOS(6.0) @interface PPModernOcrResultOverlaySubview : PPOverlaySubview

@property (strong, nonatomic) UIColor *foregroundColor;

@property (strong, nonatomic) UIColor *tintColor;

@property (assign, nonatomic) BOOL shouldIgnoreFastResults;

@property (assign, nonatomic) CGFloat charFadeInDuration;

@end

NS_ASSUME_NONNULL_END
