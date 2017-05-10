//
//  PPResultImageViewController.h
//  BlinkInput
//
//  Created by Jura on 18/09/16.
//  Copyright © 2016 MicroBlink. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PPResultImageViewController : UIViewController

@property (nonatomic) NSInteger pageIndex;

@property (nonatomic) UIImage *image;

@property (nonatomic) NSString *text;

+ (instancetype)allocFromStoryboard;

@end
