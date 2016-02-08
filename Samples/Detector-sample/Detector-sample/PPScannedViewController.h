//
//  PPScannedViewController.h
//  BlinkID
//
//  Created by Jura on 30/08/15.
//  Copyright (c) 2015 MicroBlink. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <MicroBlink/MicroBlink.h>

@protocol PPScannedViewControllerDelegate;

@interface PPScannedViewController : UIViewController

@property (weak, nonatomic) id<PPScannedViewControllerDelegate> delegate;

@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;

@property (weak, nonatomic) IBOutlet UIImageView *scannedImage;

@property (weak, nonatomic) IBOutlet UIButton *retakeButton;

@property (nonatomic, strong) PPImageMetadata* imageMetadata;

@property (weak, nonatomic) IBOutlet UILabel *titleLabel;

- (IBAction)didTapRetake:(id)sender;

- (IBAction)didTapSave:(id)sender;

+ (PPScannedViewController *)viewControllerFromStoryboard:(UIStoryboard*)storyboard;

+ (PPScannedViewController *)viewControllerFromStoryboardWithName:(NSString*)name
                                                           bundle:(NSBundle*)bundle;

@end

@protocol PPScannedViewControllerDelegate <NSObject>

- (void)scannedViewControllerWillClose:(PPScannedViewController*)scannedViewController;

@end
