//
//  PPResultImageViewController.m
//  BlinkInput
//
//  Created by Jura on 18/09/16.
//  Copyright © 2016 MicroBlink. All rights reserved.
//

#import "PPResultImageViewController.h"

@interface PPResultImageViewController ()

@property (weak, nonatomic) IBOutlet UIImageView *imageResult;

@property (weak, nonatomic) IBOutlet UILabel *labelResult;

@end

@implementation PPResultImageViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.imageResult.image = self.image;
    self.labelResult.text = self.text;

    self.view.backgroundColor = [UIColor blackColor];
}

- (void)setImage:(UIImage *)image {
    _image = image;
    self.imageResult.image = image;
}

- (void)setText:(NSString *)text {
    _text = text;
    self.labelResult.text = text;
}

#pragma mark - Instantiation

+ (instancetype)allocFromStoryboard {

    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"VinResult" bundle:nil];
    PPResultImageViewController *vc = (PPResultImageViewController *)[storyboard instantiateViewControllerWithIdentifier:@"PPResultImageViewController"];

    return vc;
}

@end
