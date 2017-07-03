//
//  OverlayViewController.h
//  Starbucks-sample
//
//  Created by Jure Cular on 29/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import <MicroBlink/MicroBlink.h>

@interface OverlayViewController : PPBaseOverlayViewController

@property (weak, nonatomic) IBOutlet UIImageView *pausedCameraImageView;

+ (instancetype)viewControllerFromStoryboard;

@end
