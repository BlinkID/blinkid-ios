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

/* String constants */

// Title string
static NSString *const kTitleLabelText = @"About";

// Close button text
static NSString *const kCloseButtonLabelText = @"Close";

// Microblink products site link
static NSString *const kMicroblinkProductsLink = @"https://microblink.com/en/products";

// Microblink site link
static NSString *const kMicroblinkLink = @"https://microblink.com";

// Microblink LinkedIn site link
static NSString *const kLinkedInLink = @"https://www.linkedin.com/company/microblink";

// Microblink Facebook site link
static NSString *const kFacebookLink = @"https://www.facebook.com/microblink";

// Microblink Twitter site link
static NSString *const kTwitterLink = @"https://twitter.com/microblink";

@implementation AboutViewController

#pragma mark - Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = kTitleLabelText;
    self.closeButton.title = kCloseButtonLabelText;
}

- (void)viewWillAppear:(BOOL)animated {
    [self.navigationController setNavigationBarHidden:NO animated:YES];
}

- (void)viewWillDisappear:(BOOL)animated {
    [self.navigationController setNavigationBarHidden:YES animated:YES];
}

#pragma mark - Actions

- (IBAction)didTapBrowseOtherProductsButton:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:kMicroblinkProductsLink] options:@{} completionHandler:nil];
}

- (IBAction)didTapMicroblinkButton:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:kMicroblinkLink] options:@{} completionHandler:nil];
}

- (IBAction)didTapLinkedInButton:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:kLinkedInLink] options:@{} completionHandler:nil];
}

- (IBAction)didTapFacebookButton:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:kFacebookLink] options:@{} completionHandler:nil];
}

- (IBAction)didTapTwitterButton:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:kTwitterLink] options:@{} completionHandler:nil];
}

- (IBAction)didTapCloseButton:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
