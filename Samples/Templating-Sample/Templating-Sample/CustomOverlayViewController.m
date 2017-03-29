//
//  CustomOverlayViewController.m
//  Templating-Sample
//
//  Created by Jure Cular on 29/03/2017.
//  Copyright © 2017 Dino. All rights reserved.
//

#import "CustomOverlayViewController.h"

@interface CustomOverlayViewController ()

@end

@implementation CustomOverlayViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    PPOverlaySubview *subview = [[PPModernViewfinderOverlaySubview  alloc] init];
    [self registerOverlaySubview:subview];
    [self.view addSubview:subview];


    PPOverlaySubview *ocrSubview = [[PPOcrResultOverlaySubview alloc] initWithFrame:self.view.frame];
    [self registerOverlaySubview:ocrSubview];
    
    [self.view addSubview:ocrSubview];
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
