//
//  PPBlinkOcrHelpPage3ViewController.m
//  BlinkOCR-sample
//
//  Created by Jura on 10/03/15.
//  Copyright (c) 2015 MicroBlink. All rights reserved.
//

#import "PPBlinkOcrHelpPage3ViewController.h"

@interface PPBlinkOcrHelpPage3ViewController ()

@end

@implementation PPBlinkOcrHelpPage3ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.helpMessageLabel.text = @"You can move between the fields by swiping the titles.";

    self.closeLabel.text = @"Close";
    self.lightLabel.text = @"Light";
    self.helpLabel.text = @"Help";
}

@end
