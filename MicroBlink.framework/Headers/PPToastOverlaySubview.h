//
//  PPTostOverlaySubview.h
//  PhotoPayFramework
//
//  Created by Jura on 08/06/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PPOverlaySubview.h"

NS_ASSUME_NONNULL_BEGIN

PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPToastOverlaySubview : PPOverlaySubview

@property (nonatomic, assign) CGFloat toastMargin;

@property (nonatomic, strong) UIFont *font;

@property (nonatomic, strong) UILabel *label;

@end

NS_ASSUME_NONNULL_END
