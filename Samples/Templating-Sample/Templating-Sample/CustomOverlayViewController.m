//
//  CustomOverlayViewController.m
//  Templating-Sample
//
//  Created by Jure Cular on 29/03/2017.
//  Copyright © 2017 Dino. All rights reserved.
//

#import "CustomOverlayViewController.h"

@interface CustomOverlayViewController ()

@property (nonatomic, strong) PPModernViewfinderOverlaySubview *viewfinderSubview;

@end

@implementation CustomOverlayViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.viewfinderSubview = [[PPModernViewfinderOverlaySubview alloc] init];

    [self registerOverlaySubview:self.viewfinderSubview];
    [self.view addSubview:self.viewfinderSubview];

    PPOcrResultOverlaySubview *ocrSubview = [[PPOcrResultOverlaySubview alloc] initWithFrame:self.view.bounds];
    [self registerOverlaySubview:ocrSubview];

    [self.view addSubview:ocrSubview];
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];

    self.viewfinderSubview.frame = self.view.bounds;
}

@end
