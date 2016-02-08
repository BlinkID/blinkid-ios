//
//  PPCameraOverlayViewController.h
//  pdf417-sample
//
//  Created by Jurica Cerovec on 13/11/13.
//  Copyright (c) 2013 PhotoPay. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <MicroBlink/MicroBlink.h>

@interface PPCameraOverlayViewController : PPOverlayViewController

@property (weak, nonatomic) IBOutlet UIButton *closeButton;

@property (weak, nonatomic) IBOutlet UIButton *torchButton;

- (IBAction)closePressed:(id)sender;

- (IBAction)torchPressed:(id)sender;

@end
