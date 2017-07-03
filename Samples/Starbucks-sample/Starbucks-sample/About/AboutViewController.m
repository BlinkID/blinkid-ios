//
//  AboutViewController.m
//  Starbucks-sample
//
//  Created by Jure Cular on 29/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "AboutViewController.h"
#import "UIColor+MBAdditions.h"
@interface AboutViewController ()

@property (weak, nonatomic) IBOutlet UIBarButtonItem *closeButton;

@end

@implementation AboutViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"About";
    self.closeButton.title = @"Close";
}

- (void)viewWillAppear:(BOOL)animated {
    [self.navigationController setNavigationBarHidden:NO animated:YES];
}

- (void)viewWillDisappear:(BOOL)animated {
    [self.navigationController setNavigationBarHidden:YES animated:YES];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)didTapBrowseOtherProductsButton:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"https://microblink.com/en/products"] options:@{} completionHandler:nil];
}

- (IBAction)didTapMicroblinkButton:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"https://microblink.com"] options:@{} completionHandler:nil];
}

- (IBAction)didTapLinkedInButton:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"https://www.linkedin.com/company/microblink"] options:@{} completionHandler:nil];
}

- (IBAction)didTapFacebookButton:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"https://www.facebook.com/microblink"] options:@{} completionHandler:nil];
}

- (IBAction)didTapTwitterButton:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"https://twitter.com/microblink"] options:@{} completionHandler:nil];
}

- (IBAction)didTapCloseButton:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
