//
//  ViewController.h
//  Camera-Sample
//
//  Created by Jura on 09/08/15.
//  Copyright © 2015 MicroBlink. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CameraViewController : UIViewController

@property (weak, nonatomic) IBOutlet UILabel *cameraPausedLabel;

- (IBAction)closeCamera:(id)sender;

@end

