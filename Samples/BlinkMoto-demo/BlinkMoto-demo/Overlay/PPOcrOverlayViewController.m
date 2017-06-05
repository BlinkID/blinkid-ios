//
//  PPOcrOverlayViewController.m
//  BlinkMoto-demo
//
//  Created by Jura Skrlec on 02/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "PPOcrOverlayViewController.h"
#import "PPOcrOverlayViewController+Private.h"
#import "PPOcrOverlaySubview.h"

@interface PPOcrOverlayViewController ()<PPOcrFinderViewDelegate>

@property (strong, nonatomic) PPOcrOverlaySubview *resultOverlay;

@property (nonatomic) UIInterfaceOrientation interfaceOrientation;

@end

@implementation PPOcrOverlayViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _interfaceOrientation = UIInterfaceOrientationPortrait;
    
    _viewfinder = [[PPOcrFinderView alloc] initWithFrame:self.view.bounds];
    _viewfinder.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
    
    [self.view insertSubview:self.viewfinder atIndex:0];
    
    self.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    
    self.resultOverlay = [[PPOcrOverlaySubview alloc] initWithFrame:self.view.bounds];
    
    // Set overlay subview
    self.resultOverlay.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.resultOverlay setBackgroundColor:[UIColor clearColor]];
    [self.view insertSubview:self.resultOverlay belowSubview:self.viewfinder];
    [self registerOverlaySubview:self.resultOverlay];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [self setupNotifications];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    // Set scanning region
    self.scanningRegion = self.viewfinder.scanningRegion;
}

- (void)viewWillDisappear:(BOOL)animated {
    [self removeNotifications];
}

#pragma mark - notifications

- (void)setupNotifications {
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(deviceOrientationChanged:)
                                                 name:UIDeviceOrientationDidChangeNotification
                                               object:nil];
}

- (void)removeNotifications {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIDeviceOrientationDidChangeNotification object:nil];
}


- (BOOL)shouldAutorotate {
    return YES;
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationPortrait | UIInterfaceOrientationLandscapeLeft | UIInterfaceOrientationLandscapeRight;
}


- (void)deviceOrientationChanged:(NSNotification *)notification {
    
    UIDeviceOrientation deviceOrientation = [[UIDevice currentDevice] orientation];
    
    UIInterfaceOrientation orientation = self.interfaceOrientation;
    
    if (UIDeviceOrientationIsPortrait(deviceOrientation)) {
        orientation = UIInterfaceOrientationPortrait;
    }
    else if (UIDeviceOrientationIsLandscape(deviceOrientation)) {
        orientation = deviceOrientation == UIDeviceOrientationLandscapeLeft ? UIInterfaceOrientationLandscapeLeft : UIInterfaceOrientationLandscapeRight;
    }
    
    [self setInterfaceOrientation:orientation animated:YES];
}

- (void)setInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    [self setInterfaceOrientation:interfaceOrientation animated:NO];
}

- (void)setInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation animated:(BOOL)animated {
    if (self.interfaceOrientation == interfaceOrientation) {
        return;
    }
    
    if (UIInterfaceOrientationIsPortrait(interfaceOrientation)) {
        
        [self.viewfinder setScanningOrientation:UIInterfaceOrientationPortrait animated:animated];
        
    } else if (UIInterfaceOrientationIsLandscape(interfaceOrientation)) {

        [self.viewfinder setScanningOrientation:interfaceOrientation animated:animated];
    }
    
    _interfaceOrientation = interfaceOrientation;
}


#pragma mark - PPOcrFinderViewDelegate

- (void)viewfinderViewUpdatedScanningRegion:(PPOcrFinderView *)viewfinderView {
    [self.containerViewController setScanningRegion:self.viewfinder.scanningRegion];

}

- (BOOL)viewfinderViewIsScanningPaused:(PPOcrFinderView *)viewfinderView {
    return [self.containerViewController isScanningPaused];
}

@end
