//
//  PPOcrLineOverlayViewController.h
//  PhotoPayFramework
//
//  Created by Jurica Cerovec on 6/2/13.
//  Copyright (c) 2013 MicroBlink Ltd. All rights reserved.
//

#import "PPOverlayViewController.h"
#import "PPBasePhotoPayOverlayViewController.h"

@class PPOcrResultOverlaySubview;
@class PPOcrLineOverlaySubview;

PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPOcrLineOverlayViewController : PPBasePhotoPayOverlayViewController

@property (nonatomic, assign) CGFloat ocrWindowStartPercentage;

@property (nonatomic, assign) CGFloat ocrWindowHeightPercentage;

@end
