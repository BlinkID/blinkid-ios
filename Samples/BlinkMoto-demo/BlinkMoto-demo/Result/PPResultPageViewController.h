//
//  PPResultPageViewController.h
//  BlinkInput
//
//  Created by Jura on 18/09/16.
//  Copyright © 2016 MicroBlink. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PPResultPageViewController : UIPageViewController

@property (nonatomic) NSMutableArray *scanElements;

+ (instancetype)allocFromStoryboard;

@end
